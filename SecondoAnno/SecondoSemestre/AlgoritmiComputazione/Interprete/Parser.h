#if !defined(PARSER_H)
#define PARSER_H
#include <vector>
#include "Token.h"
#include "Syntax.h"
#include "Eccezioni.h"

class Parser
{
public:
    Program *operator()(std::vector<Token> const &tokenStream)
    { // usiamo un function object

        auto itr = tokenStream.begin(); // uso auto per iterare perche il tipo della variable è lungo
        end_ = tokenStream.end();

        Program *p = parseProgram(itr); // ed iniziamo ad iterare per parsare

        if (itr != end_)
        { // se alla fine del parsing , quando ritorna tutto , itr non è ancora alla fine allora c'è un problema
            throw EvaluationError{"Reading file not completely nerminated"};
        }

        return p;
    }

private:
    // dichiaro tutti i metodi necessari per parsare ogni componente del programma

    std::vector<Token>::const_iterator end_;

    Program *parseProgram(std::vector<Token>::const_iterator &itr);
    Block *parseStmtBlock(std::vector<Token>::const_iterator &itr);
    Block *parseBlock(std::vector<Token>::const_iterator &itr);
    Statement *parseStatement(std::vector<Token>::const_iterator &itr);

    NumExpr *parseNumExpr(std::vector<Token>::const_iterator &itr);
    Number *parseNumber(std::vector<Token>::const_iterator &itr);
    Variable *parseVariable(std::vector<Token>::const_iterator &itr);

    BoolExpr *parseBoolExpr(std::vector<Token>::const_iterator &itr);
    BoolConst *parseBoolConst(std::vector<Token>::const_iterator &itr);

    PrintStmt *parsePrintStmt(std::vector<Token>::const_iterator &itr);
    SetStmt *parseSetStmt(std::vector<Token>::const_iterator &itr);
    InputStmt *parseInputStmt(std::vector<Token>::const_iterator &itr);
    WhileStmt *parseWhileStmt(std::vector<Token>::const_iterator &itr);
    IfStmt *parseIfStmt(std::vector<Token>::const_iterator &itr);

    void safe_next(std::vector<Token>::const_iterator &itr) // mi serve per avanzare il puntatore in maniera sicura
    {
        if (itr != end_)
        {
            ++itr;
        }
        else
        {
            throw SyntaxError{"Premature end of input"};
        }
    }
};
#endif