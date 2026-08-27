/*
i costruttori di copia e gli operatori di assegnamento non li ho messi perchè non so 
quando potrebbe presentarsi effettivamente la situazione in cui servono

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
    void accept(Visitor& visitor) const override ; 
    
    std::vector<Statement*> statements_;
} ; 

struct Program{
    void accept(Visitor& visitor) const ; 
    Statement* root_;
};

struct NumExpr{
virtual void accept(Visitor& visitor) const = 0 ; 
virtual ~NumExpr() = default ; 
};

struct Operator : public NumExpr{
    
    enum OpCode { PLUS, MINUS, TIMES, DIV };

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

    void accept(Visitor& visitor) const override ;

    std::string id_;
};




struct BoolExpr{ 
virtual void accept(Visitor& visitor) const = 0 ; 
virtual ~BoolExpr() = default ; 
};

struct BoolOp : public BoolExpr{
enum boolOpCode {AND , OR , NOT};

BoolOp(int boolOpCode, BoolExpr* op_1 , BoolExpr* op_2) : boolOpCode_(boolOpCode) , op1(op_1) , op2(op_2){} //serve per AND e OR
BoolOp(int boolOpCode, BoolExpr* op_1) : boolOpCode_(boolOpCode) , op1(op_1) , op2(nullptr){} //serve per il NOT
~BoolOp() = default ; 

void accept(Visitor& visitor) const override ; 

int boolOpCode_ ;
BoolExpr* op1; 
BoolExpr* op2; 
};

struct BoolConst : public BoolExpr{

BoolConst(bool boole) : boolean{boole}{}
~BoolConst() = default ; 

void accept(Visitor& visitor) const override ; 

bool boolean ;
};

struct RelOp : public BoolExpr{
 enum relCode {LT , GT , EQ};
    RelOp(int relCode, NumExpr* num_1, NumExpr* num_2) : relCode_(relCode) , num1_l(num_1) , num2_r(num_2) {}
    ~RelOp() = default ; 

    void accept(Visitor& visitor) const override ; 

    int relCode_ ;
    NumExpr* num1_l ;
    NumExpr* num2_r ; 
};


struct PrintStmt : public Statement{
    void accept(Visitor& visitor) const override;
    PrintStmt(NumExpr* num_expr) : num_expr_(num_expr) {} ; 
    ~PrintStmt()  = default ; 
    
    NumExpr* num_expr_ ; 
};

struct SetStmt : public Statement{
    void accept(Visitor& visitor) const override;
    SetStmt(Variable* variable_id, NumExpr* num_expr) : variable_id_(variable_id) , num_expr_(num_expr) {};
    ~SetStmt() = default ; 

    Variable* variable_id_ ; 
    NumExpr* num_expr_ ; 
};

struct InputStmt : public Statement{
    void accept(Visitor& visitor) const override;
    InputStmt(Variable* variable_id) : variable_id_(variable_id){};
    ~InputStmt() = default ; 

    Variable* variable_id_;
};

struct WhileStmt : public Statement{
    void accept(Visitor& visitor) const override;

    WhileStmt(BoolExpr* bool_expr, Block* stmt_block_) : bool_expr_(bool_expr) , stmt_block_(stmt_block_) {} ; 
    ~WhileStmt() = default ; 

    
    BoolExpr* bool_expr_; 
    Block* stmt_block_;
};

struct IfStmt : public Statement{

    void accept(Visitor& visitor) const override; 

    IfStmt(BoolExpr* boolexpr , Block* stat_1, Block* stat_2): bool_expr{boolexpr} , stmt_block1{stat_1} , stmt_block2{stat_2}{}
    ~IfStmt() = default ; 
    

    BoolExpr* bool_expr; 
    Block* stmt_block1; 
    Block* stmt_block2; 
};


#endif