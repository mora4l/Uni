#if !defined(LEXER_H)
#define LEXER_H

#include <vector>
#include <fstream>

#include "Token.h"
#include "Exception.h"

// Function object to tokenize an input stream
class Lexer {
public:
	Lexer() = default;
	~Lexer() = default;
	Lexer(Lexer const&) = delete;
	Lexer& operator=(Lexer const&) = delete;

	std::vector<Token> operator()(std::ifstream& inputFile) {
		std::vector<Token> inputTokens;
		tokenizeInputFile(inputFile, inputTokens);
		return inputTokens;
	}

private:
	std::string tokenizeConstant(std::ifstream& inputFile, std::stringstream& temp);
	void tokenizeInputFile(std::ifstream& inputFile, std::vector<Token>& inputTokens);
};


#endif
