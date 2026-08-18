#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Token.h"
#include "Tokenizer.h"

int main(int argc, char* argv[])
{
	
	// Check if there is at least one input argument
	// The first input argument (argv[0]) is always the name of the program
	if (argc < 2) {
		std::cerr << "No input file!" << std::endl;
		std::cerr << "Usage: " << std::endl;
		std::cerr << argv[0] << " <filename> " << std::endl;
		return EXIT_FAILURE;
	}

	// Try to open the file to be interpreted
	std::ifstream inputFile;
	try {
		inputFile.open(argv[1]);
	}
	catch (std::exception& e) {
		// Whatever exception is raised, end up here
		std::cerr << "Cannot open " << argv[1] << " got: " << std::endl;
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	// TOKENIZING 
	// Create a tokenizer function object
	Tokenizer tokenize;
	// Create a vector to memorize the token stream
	std::vector<Token> inputTokens;
	// Extract a token stream from the input stream
	try {
		// Avoid copying the stream of tokens
		inputTokens = std::move(tokenize(inputFile));
	}
	catch (LexicalError& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (std::exception& e) {
		std::cerr << "Cannot read from " << argv[1] << " got: " << std::endl;
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	// Printing the stream of Tokens
	for (Token tok : inputTokens) {
		std::cout << tok << " ";
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}


