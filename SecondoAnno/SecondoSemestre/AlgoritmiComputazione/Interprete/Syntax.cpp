#include <string> //questa e sstream mi serve per le exception
#include <sstream>
#include <iostream>
#include "Syntax.h"
#include "Visitor.h"
#include "Eccezioni.h"

//
void Program::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

void Block::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

void PrintStmt::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

void InputStmt::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

void WhileStmt::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

void IfStmt::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

void SetStmt::accept(Visitor& visitor) const {
    visitor.visit(*this);
}


void Operator::accept(Visitor& visitor) const {
    visitor.visit(*this);
};
int Operator::stringaAcodiceOperatoriAritmetici(const std::string& word){
    if(word=="ADD"){
        return ADD ; 
    }else if(word=="SUB"){
        return SUB; 
    }else if(word=="MUL"){
        return MUL;
    }else if(word=="DIV"){
        return DIV;
    }else{
                               std::stringstream temp;
            temp << "Unexpected word: " << word << std::endl
                 << "Expected an aritmethic operator (ADD,SUB,MUL,DIV)";
            throw SyntaxError{temp.str()};
    }
}

void Number::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

void Variable::accept(Visitor& visitor) const {
    visitor.visit(*this);
};



void BoolOp::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

int BoolOp::stringaAcodiceNOT(const std::string& word){
    if(word=="NOT"){
        return NOT; 
    }else{ /*ce da comunicare un errore qui : il token non è nessuno dei 3 aspettati, 
anche se è inutile perche ho già verificato con isRelOperators (inline in parser.cpp) che abbiamo un <,>,=
pero comunque lascio un throw perche potrebbe essere comodo come "difesa" a possibili modifiche future
*/
                       std::stringstream temp;
            temp << "Unexpected word: " << word << std::endl
                 << "Expected a bool expression (AND,OR,NOT)";
            throw SyntaxError{temp.str()};
    }
}

int BoolOp::stringaAcodiceANDOR(const std::string& word){
if(word=="AND"){
    return AND;
}else if(word=="OR") {
    return OR; 
}else{   /*ce da comunicare un errore qui : il token non è nessuno dei 3 aspettati, 
anche se è inutile perche ho già verificato con isRelOperators (inline in parser.cpp) che abbiamo un <,>,=
pero comunque lascio un throw perche potrebbe essere comodo come "difesa" a possibili modifiche future
*/
                       std::stringstream temp;
            temp << "Unexpected word: " << word << std::endl
                 << "Expected a bool expression (AND,OR,NOT) ";
            throw SyntaxError{temp.str()};
    }

}

void BoolConst::accept(Visitor& visitor) const {
    visitor.visit(*this);
};


void RelOp::accept(Visitor& visitor) const {
    visitor.visit(*this);
};

int RelOp::stringaAcodiceLTGTEQ(const std::string& word){
    if(word=="LT"){
        return LT;
    }else if(word=="GT"){
        return GT;
    }else if(word=="EQ"){
        return EQ;
    }else{    /*ce da comunicare un errore qui : il token non è nessuno dei 3 aspettati, 
anche se è inutile perche ho già verificato con isRelOperators (inline in parser.cpp) che abbiamo un <,>,=
pero comunque lascio un throw perche potrebbe essere comodo come "difesa" a possibili modifiche future
*/

                       std::stringstream temp;
            temp << "Unexpected word: " << word << std::endl
                 << "Expected a bool expression ";
            throw SyntaxError{temp.str()};
    }
}
