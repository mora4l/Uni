#include <string>
#include <sstream>
#include <cstring>

#include "Tokenizer.h"

std::string Tokenizer::tokenizeConstant(std::ifstream &inputFile, std::stringstream &temp)
{
	bool dotSeen = false;
	char ch;
	do
	{
		ch = inputFile.get();
		if (std::isdigit(ch))
			temp << ch;
		if (ch == '.')
		{
			if (not dotSeen)
			{
				dotSeen = true;
				temp << ch;
			}
			else
			{
				throw LexicalError("Duplicate decimal dot");
			}
		}
	} while (std::isdigit(ch) || ch == '.');
	// Unget the last character which was not part of this token
	inputFile.unget();//perchè l'ultimo carattere letto è colui che l'ha fatto uscire dal ciclo quindi lo scartiamo
	return temp.str();
}

void Tokenizer::tokenizeInputFile(std::ifstream &inputFile, std::vector<Token> &inputTokens)
{
	char ch{};
	unsigned int rowCount{1};
	ch = inputFile.get();
	while (!inputFile.eof())
	{
		if (std::isspace(ch))
		{
			// Skip "whitespace", but count rows (for error messages)
			if (ch == '\n')
				rowCount += 1;
		}
		else if (ch == '{')
		{
			// Left brace
			inputTokens.push_back(Token{Token::LB, Token::id2word[Token::LB]});
		}
		else if (ch == '}')
		{
			// Right brace
			inputTokens.push_back(Token{Token::RB, Token::id2word[Token::RB]});
		}
		else if (ch == '(')
		{
			// Left parenthesis
			inputTokens.push_back(Token{Token::LP, Token::id2word[Token::LP]});
		}
		else if (ch == ')')
		{
			// Right parenthesis
			inputTokens.push_back(Token{Token::RP, Token::id2word[Token::RP]});
		}
		else if (ch == ',')
		{
			// Comma
			inputTokens.push_back(Token{Token::CO, Token::id2word[Token::CO]});
		}
		else if (ch == ';')
		{
			// Semicolon
			inputTokens.push_back(Token{Token::SC, Token::id2word[Token::SC]});
		}
		else if (ch == '+')
		{
			// Addition
			inputTokens.push_back(Token{Token::ADD, Token::id2word[Token::ADD]});
		}
		else if (ch == '-')
		{
			// Subtraction or negative numeric constant: read one more character
			char ch2 = inputFile.get();
			if (std::isdigit(ch2))
			{
				// Negative numeric constant
				std::stringstream temp;
				temp << ch << ch2;//in temp 
				tokenizeConstant(inputFile, temp);
				inputTokens.push_back(Token{Token::CONST, temp.str()});
			}
			else
			{
				inputTokens.push_back(Token{Token::SUB, Token::id2word[Token::SUB]});
				// Unget the next character which is not part of this token
				inputFile.unget();
			}
		}
		else if (ch == '*')
		{
			// Multiplication
			inputTokens.push_back(Token{Token::MUL, Token::id2word[Token::MUL]});
		}
		else if (ch == '/')
		{
			// Division
			inputTokens.push_back(Token{Token::DIV, Token::id2word[Token::DIV]});
		}
		else if (ch == '=')
		{
			// Equal (assignment)
			inputTokens.push_back(Token{Token::EQ, Token::id2word[Token::EQ]});
		}
		else if (std::isdigit(ch))
		{
			// Positive numeric constant, either integer or floating point
			// Does not work with constants written using exponential notation
			std::stringstream temp;
			temp << ch;
			tokenizeConstant(inputFile, temp);
			inputTokens.push_back(Token{Token::CONST, temp.str()});
		}
		else if (std::isalpha(ch) or ch == '_')
		{
			// Keyword or identifier
			std::stringstream temp;
			temp << ch;
			do
			{
				ch = inputFile.get();
				if (std::isalpha(ch) or std::isdigit(ch) or ch == '_')
					temp << ch;
			} while (std::isalpha(ch) or std::isdigit(ch) or ch == '_');


			std::string word{temp.str()};


			int tag = Token::ID;


			if (Token::keywords.find(word) != Token::keywords.end())
			{
				tag = Token::KWORD;
			}


			inputTokens.push_back(Token{tag, word});
			// Unget the last character which was not part of this token
			inputFile.unget();
		}
		else
		{
			// Garbage
			std::stringstream temp;
			temp << "Stray character " << ch
				 << " in input at line " << rowCount;
			throw LexicalError{temp.str()};
		}
		ch = inputFile.get();
	}
}
