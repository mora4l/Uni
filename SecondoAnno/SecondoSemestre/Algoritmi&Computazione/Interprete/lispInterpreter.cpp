#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Token.h"
#include "Tokenizer.h"
#include "Parser.h"

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

    //analisi lessicale
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

    // for (const auto& tok : inputTokens) { //con & non faccio nessuna copia per stampare
	// 	std::cout << tok << " "<<std::endl;
	// }

    /*adesso ho in un vector tutti i token , divisi per cosa sono 
    ora devo fare l'analisi sintattica con il parsing e creare l'albero sintattico 
    adesso non so ancora se il codice ha senso , "so di aver letto delle cose" , ma non so se abbiano senso
    */

     Parser parse ; 
     Program* program; 

    try{
        program = parse(inputTokens); 
    }catch(SyntaxError& e){
        std::cerr << e.what() <<std::endl ; 
        return EXIT_FAILURE ; 
    }catch (std::exception& e){
        std::cerr << "Something odd happened during parsing, got: " << std::endl;
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
    }
    

    return EXIT_SUCCESS;
}
