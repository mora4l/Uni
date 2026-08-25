/*
i costruttori di copia e gli operatori di assegnamento non li ho messi perchè non so 
quando potrebbe presentarsi effettivamente la situazione in cui servono

Finito : 
classe BoolExpr
classe NumExpr

sottoclasse Ifstmt

Da fare : 
Printstmt
Setstmt
Inputstmt
WhileStmt
*/
#if !defined(SYNTAX_H)
#define SYNTAX_H

#include <vector>
#include <string>

class Visitor;

struct Statement{
    virtual void accept(Visitor& visitor) const = 0 ; 
    virtual ~Statement() = default ; 
};

struct Block : public Statement {
    Block(std::vector<Statement*> stmts) : statements_{std::move(stmts)}{};
    std::vector<Statement*> statements_;
} ; 

struct Program{
    void accept(Visitor& visitor) const ; 
    Statement* root_;
};





struct PrintStmt : public Statement{
    void accept(Visitor& visitor) const ;

};

struct SetStmt : public Statement{
    void accept(Visitor& visitor) const ;

};

struct InputStmt : public Statement{
    void accept(Visitor& visitor) const ;
    
};

struct WhileStmt : public Statement{
    void accept(Visitor& visitor) const ;
    
};

class IfStmt : public Statement{
public :


    IfStmt(BoolExpr* boolexpr , Block* stat_1, Block* stat_2): bool_expr{boolexpr} , stmt_block1{stat_1} , stmt_block2{stat_2}{}
    ~IfStmt() = default ; 
    
private : 
    BoolExpr* bool_expr; 
    Block* stmt_block1; 
    Block* stmt_block2; 
};






struct NumExpr{
virtual void accept(Visitor& Visitor) const = 0 ; 
~NumExpr() = default ; 
};

struct Operator : public NumExpr{
    Operator(int opCode, NumExpr* l, NumExpr* r) : opCode_(opCode) , left_(l),right_(r){}
    ~Operator() = default ; 
    void accept(Visitor& visitor) const override; 

    int opCode_ ; 
    NumExpr* left_ ; 
    NumExpr* right_ ; 
};

struct Number: public NumExpr{
    Number(int n) : n_(n){}
    ~Number() = default ; 

    void accept(Visitor& visitor) const override; 

    int n_; 
};

struct Variable : public NumExpr{
    Variable(std::string id) : id_(id) {}
    ~Variable() = default ; 

    std::string id_;
};




struct BoolExpr{ 
virtual void accept(Visitor& visitor) const = 0 ; 
virtual ~BoolExpr() = default ; 
};

struct BoolOp : public BoolExpr{
 
BoolOp(BoolExpr* op_1 , BoolExpr* op_2) : op1(op_1) , op2(op_2){} //serve per AND e OR
BoolOp(BoolExpr* op_1,BoolExpr* op_2) : op1(op_1) , op2(nullptr){} //serve per il NOT
~BoolOp() = default ; 

void accept(Visitor& Visitor) const override ; 

BoolExpr* op1; 
BoolExpr* op2; 
};

struct BoolConst : public BoolExpr{

BoolConst(bool boole) : boolean{boole}{}
~BoolConst() = default ; 

void accept(Visitor& Visitor) const override ; 

bool boolean ;
};

struct RelOp : public BoolExpr{
 
    RelOp(NumExpr* num_1, NumExpr* num_2) : num1(num_1) , num2(num_2) {}
    ~RelOp() = default ; 

    void accept(Visitor& Visitor) const override ; 


    NumExpr* num1 ;
    NumExpr* num2 ; 
};

#endif