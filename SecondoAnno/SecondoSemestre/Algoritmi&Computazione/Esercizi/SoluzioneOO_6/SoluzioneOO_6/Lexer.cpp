#include <sstream>

#include "Lexer.h"

std::string Lexer::tokenizeConstant(std::ifstream& inputFile, std::stringstream& temp) {
	char ch = inputFile.get();
	while (std::isdigit(ch)) {
		temp << ch;
		ch = inputFile.get();
	};
	// Unget the last character which was not part of this token
	inputFile.unget();
	return temp.str();
}

void Lexer::tokenizeInputFile(std::ifstream& inputFile, std::vector<Token>& inputTokens) {
	char ch{ };
	unsigned int rowCount{ 1 };
	ch = inputFile.get();
	while (!inputFile.eof()) {
		if (std::isspace(ch)) {
			// Skip "whitespace", but count rows (for error messages)
			if (ch == '\n') rowCount += 1;
		}
		else if (ch == '(') {
			// Left parenthesis
			inputTokens.push_back(Token{ Token::LP, Token::id2word[Token::LP] });
		}
		else if (ch == ')') {
			// Right parenthesis
			inputTokens.push_back(Token{ Token::RP, Token::id2word[Token::RP] });
		}
		else if (ch == '=') {
			// Assignment
			inputTokens.push_back(Token{ Token::EQ, Token::id2word[Token::EQ] });
		}
		else if (ch == '+') {
			// Addition
			inputTokens.push_back(Token{ Token::ADD, Token::id2word[Token::ADD] });
		}
		else if (ch == '-') {
			// Subtraction 
			inputTokens.push_back(Token{ Token::SUB, Token::id2word[Token::SUB] });
		}
		else if (ch == '*') {
			// Multiplication
			inputTokens.push_back(Token{ Token::MUL, Token::id2word[Token::MUL] });
		}
		else if (ch == '/') {
			// Division
			inputTokens.push_back(Token{ Token::DIV, Token::id2word[Token::DIV] });
		}
		else if (std::isdigit(ch)) {
			// Positive numeric constant
			std::stringstream temp;
			temp << ch;
			tokenizeConstant(inputFile, temp);
			inputTokens.push_back(Token{ Token::CONST, temp.str() });
		}
		else if (std::isalpha(ch)) {
			// Identifier
			std::stringstream temp;
			temp << ch;
			do {
				ch = inputFile.get();
				if (std::isalpha(ch) or std::isdigit(ch)) temp << ch;
			} while (std::isalpha(ch) or std::isdigit(ch));
			std::string word{ temp.str() };
			int tag = Token::ID;
			inputTokens.push_back(Token{ tag, word });
			// Unget the last character which was not part of this token
			inputFile.unget();
		}
		else {
			// Garbage
			std::stringstream temp;
			temp << "Stray character " << ch
				<< " in input at line " << rowCount;
			throw LexicalError{ temp.str() };
		}
		ch = inputFile.get();
	}
}
