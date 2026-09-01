#if !defined(TOKENIZER_H)
#define TOKENIZER_H

#include <vector>
#include <fstream>

#include "Token.h"
#include "Exceptions.h"

// Function object to tokenize an input stream
class Tokenizer
{
public:
	Tokenizer() = default;
	~Tokenizer() = default;
	Tokenizer(Tokenizer const &) = delete;
	Tokenizer &operator=(Tokenizer const &) = delete;

	std::vector<Token> operator()(std::ifstream &inputFile)
	{
		std::vector<Token> inputTokens;
		tokenizeInputFile(inputFile, inputTokens);
		return inputTokens;
	}

private:
	std::string tokenizeConstant(std::ifstream &inputFile, std::stringstream &temp);
	void tokenizeInputFile(std::ifstream &inputFile, std::vector<Token> &inputTokens);
};

#endif
