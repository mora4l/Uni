#if !defined(PARSER_H)
#define PARSER_H
#include <vector>
#include "Token.h"
#include "Syntax.h"
#include "Eccezioni.h"

class Parser
{
public:
Block* operator()(std::vector<Token> const& tokenStream){
    auto itr = tokenStream.begin() ; //uso auto per iterare perche il tipo della variable è lungo
    end_ =  tokenStream.end();

    Block* p = parseStmtBlock(itr) ;

    
    
    if(itr != end_){
        throw EmptyVector{"Lettura non finita"};
    }


    return p; 
}

private : 
    
    std::vector<Token>::const_iterator end_;
    
    Program* parseProgram(std::vector<Token>::const_iterator &itr);
    Block *parseStmtBlock(std::vector<Token>::const_iterator &itr);
    Block *parseBlock(std::vector<Token>::const_iterator &itr);
    Statement *parseStatement(std::vector<Token>::const_iterator &itr);
    
    
    NumExpr *parseNumExpr(std::vector<Token>::const_iterator &itr);
    Number* parseNumber(std::vector<Token>::const_iterator &itr);
    Variable *parseVariable(std::vector<Token>::const_iterator &itr);
    // Operator* parseOperator(std::vector<Token>::const_iterator& itr);

    BoolExpr *parseBoolExpr(std::vector<Token>::const_iterator &itr);
    // BoolConst *parseBoolConst(std::vector<Token>::const_iterator &itr);
    // RelOp *parseRelOp(std::vector<Token>::const_iterator &itr);
    // BoolOp *parseBoolOp(std::vector<Token>::const_iterator &itr);

    PrintStmt *parsePrintStmt(std::vector<Token>::const_iterator &itr);
    SetStmt *parseSetStmt(std::vector<Token>::const_iterator &itr);
    InputStmt *parseInputStmt(std::vector<Token>::const_iterator &itr);
    WhileStmt *parseWhileStmt(std::vector<Token>::const_iterator &itr);
    IfStmt *parseIfStmt(std::vector<Token>::const_iterator &itr);

    void safe_next(std::vector<Token>::const_iterator &itr) //mi serve per avanzare il puntatore in maniera sicura
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