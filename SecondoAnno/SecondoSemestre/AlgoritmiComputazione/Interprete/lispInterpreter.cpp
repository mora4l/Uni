/*
per debuggare
g++ -g -Wall -Wextra -std=c++20 lispInterpreter.cpp Parser.cpp Syntax.cpp Tokenizer.cpp Token.cpp  -o lispInterpreter

per scovare tutti gli errori
g++ -g -Wall -Wextra -Wpedantic -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -std=c++20 lispInterpreter.cpp Parser.cpp Syntax.cpp Tokenizer.cpp Token.cpp -o lispInterpreter
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Token.h"
#include "Tokenizer.h"
#include "Parser.h"
#include "SymbolTable.h"
#include "PrintVisitor.h"
#include "EvaluationVisitor.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Missing file from command line " << std::endl;
        return EXIT_FAILURE; // grazie a stdlib
    }

    std::ifstream programmadafile; // prendiamo il file da analizzare ed interpretare

    try // praticamente il try ci servirà per "controllare" l'esecuzione e gestirla in maniera controllata
    {
        programmadafile.open(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cerr << "Impossible to open " << argv[1] << " with the following issue " << std::endl;
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    //**** ANALISI LESSICALE ****//

    Tokenizer tokenizza;

    std::vector<Token> inputTokens;

    try
    {
        inputTokens = std::move(tokenizza(programmadafile)); // usiamo la move per non creare copie inutili
    }
    catch (LexicalError &e)
    {
        std::cerr << "(ERROR in tokenizer: ";
        std::cerr << e.what() << ")" << std::endl;
        return EXIT_FAILURE;
    }
    /*
    qui io ho creato un'eccezione apposita per descrivere il caso in cui il programma sia vuoto .
    non è un problema lessicale ,tantomeno un problema sintattico o semantico , però allo stesso tempo devo gestirlo per controllare
    efficacemente l'esecuzione .
    */
    catch (EmptyProgram &e)
    {
        return EXIT_FAILURE;
    }
    catch (std::exception &e) // questo ultimo catch è come se fosse una "rete" finale per tutte le eccezioni std avvenute
    {
        std::cerr << "Impossible to open " << argv[1] << " with the following issue " << std::endl;
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    /*adesso ho in un vector tutti i token , divisi per cosa sono
    ora devo fare l'analisi sintattica con il parsing e creare l'albero sintattico
    adesso non so ancora se il programma ha senso , "so di aver letto delle cose" , ma non so se abbiano senso
    */

    //**** ANALISI SINTATTICA  ****//

    Parser parse;
    Program *program;

    try
    {
        program = parse(inputTokens);
    }
    catch (SyntaxError &e)
    {
        std::cerr << "(ERROR in parser: ";
        std::cerr << e.what() << ")" << std::endl;
        return EXIT_FAILURE;
    }
    catch (std::exception &e)
    {
        std::cerr << "Something odd happened during parsing, got: " << std::endl;
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    /*
        //a questo punto abbiamo l'albero AST
        // la symbol table mi serve per associare un nome di variabile (string che è un ID) ad un numero (int che è un CONST)
    */

    //**** ANALISI SEMANTICA ****//

    SymbolTable symboltable;
    EvaluationVisitor evaluator{symboltable, std::cout};

    try
    {
        if (program != nullptr)
        {
            /*
            //in questo modo mantengo il corretto uso dell'overriding , chiamando la accept su program che va a sua volta
            va ad invocare la corretta visit in Evalutation.h (che a sua volta inizierà a esplorare l'albero) (questo si basa sul pattern visitor)
            */
            program->accept(evaluator);
        }
        else
        {
            std::cerr << "Empty program ";
        }
    }
    catch (EvaluationError &e)
    {
        std::cerr << "(ERROR in evaluator: ";
        std::cerr << e.what() << ")" << std::endl;
        return EXIT_FAILURE;
    }
    catch (std::exception &e)
    { // è una "rete di sicurezza" finale , cioè che se non è stato lanciata nessuna eccezione particolare , allora sarà un eccezione standard che finisce qua dentro
        std::cerr << "ERROR in" << std::endl;
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    /*QUESTO MI SERVE PER STAMPARE L' AST (facoltativo, non fondamentale)

        std::cout<<"\n\n\n ALBERO AST: \n\n";
        PrintVisitor albero{std::cout,0};
        program->accept(albero);

    */

    return EXIT_SUCCESS;
}
