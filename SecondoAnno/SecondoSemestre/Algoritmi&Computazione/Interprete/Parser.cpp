#include <sstream>
#include "Parser.h"

Program *Parser::parseProgram(std::vector<Token>::const_iterator &itr)
{
    Program *p = new Program{};
    p->root_ = parseStatement(itr);

    return p;
}

Statement *Parser::parseStatement(std::vector<Token>::const_iterator &itr)
{
    if (itr->tag == Token::LP)
    {
        safe_next(itr);

        if (itr->tag == Token::KWORD)
        {
            if (itr->word == "BLOCK")
            {
                return parseBlock(itr);
            }
            else if (itr->word == "SET")
            {
                return parseSetStmt(itr);
            }
            else if (itr->word == "INPUT")
            {
                return parseInputStmt(itr);
            }
            else if (itr->word == "PRINT")
            {
                return parsePrintStmt(itr);
            }
            else if (itr->word == "IF")
            {
                return parseIfStmt(itr);
            }
            else if (itr->word == "WHILE")
            {
                return parseWhileStmt(itr);
            }
        }else{
            std::stringstream temp ; 
            temp << "Unexpected token: "<< *itr<< std::endl
            << "Expected block or statement";
            throw SyntaxError{temp.str()};
        }
    }
}