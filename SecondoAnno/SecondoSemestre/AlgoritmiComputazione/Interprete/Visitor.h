#if !defined(VISITOR_H)
#define VISITOR_H

#include "Syntax.h"

class Visitor {
    public : 
    virtual void visit(Program const& program) = 0 ; 
    virtual void visit(Block const& block) = 0 ; 

    virtual void visit(PrintStmt const& print) = 0 ; 
    virtual void visit(InputStmt const& in) = 0 ; 
    virtual void visit(WhileStmt const& whil) = 0 ; 
    virtual void visit(IfStmt const& iff) = 0 ; 
    virtual void visit(SetStmt const& set ) = 0 ; 

    virtual void visit(Operator const& op) = 0 ; 
    virtual void visit(Number const& num) = 0 ; 
    virtual void visit(Variable const& var) = 0 ; 

    virtual void visit(BoolOp const& boolop) = 0;
    virtual void visit(BoolConst const& boolconst) = 0 ; 
    virtual void visit(RelOp const& relop) = 0 ; 

};
#endif