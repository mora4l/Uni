#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Token.h"
#include "Tokenizer.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Non è stato inserito nessun file da linea di comando " << std::endl;
        return EXIT_FAILURE; // grazie a stdlib
    }

    std::ifstream programmadafile;

    try
    {
        programmadafile.open(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cerr << "Non è stato possibile aprire il file " << argv[1] << "a causa di " << std::endl;
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    Tokenizer tokenizza;

    std::vector<Token> inputTokens;

    try
    {
        inputTokens = std::move(tokenizza(programmadafile));
    }
    catch (LexicalError& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (std::exception &e)
    {
        std::cerr << "Impossibile leggere da " << argv[1] << " per la seguente causa: " << std::endl;
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    for (Token tok : inputTokens) {
		std::cout << tok << " ";
	}
	std::cout << std::endl;

    return EXIT_SUCCESS;
}
