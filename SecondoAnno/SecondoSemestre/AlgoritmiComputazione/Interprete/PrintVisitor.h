#if !defined(PRINT_VISITOR_H)
#define PRINT_VISITOR_H

#include <iostream>

#include "Visitor.h"
#include "Syntax.h"
#include "Token.h"

class PrintVisitor : public Visitor
{
public:
    PrintVisitor(std::ostream &con, int spazio) : console_(con), spazio_(0) {}

    // ora sviluppo per ogni elemento dell'AST il metodo che stampa a schermo quella parte di albero .

    void visit(Program const &p) override
    {
        console_ << spazioTree() << "[PROGRAM] \n";
        spazio_ += 2; //questi contatori mi servono per creare una forma grafica di gerarchia
        p.root_->accept(*this); // iniziamo a visitare l'albero dalla radice
        spazio_ -= 2; //vado avanti con +2 e poi dopo aver visitato torno indietro
    }

    void visit(Block const& block)override{
        console_<<spazioTree()<< "[BLOCK] \n";
        spazio_ += 2; 
        for(auto* stmt : block.statements_){ //usiamo quanto visto nei range e iteratori per minimizzare la scrittura dei tipi , tutto questo grazie ad "auto" che lo fa automaticamente
            stmt->accept(*this);
        }
        spazio_ -= 2;
    }

    void visit(PrintStmt const& print)override{
        console_<<spazioTree()<<"[PRINT] \n";
        spazio_ += 2; 
        print.num_expr_->accept(*this);
        spazio_ -= 2;
    }

    void visit(InputStmt const& in)override{
        console_<<spazioTree()<<"[INPUT] \n";
        spazio_ += 2; 
        in.variable_id_->accept(*this);
        spazio_ -= 2;
    }

    void visit(WhileStmt const& whil)override{
        console_<<spazioTree()<<"[WHILE] \n";
        spazio_ += 2; 
        console_<<spazioTree()<<"[while condition] \n";
        whil.bool_expr_->accept(*this);

        console_<<spazioTree()<<"[while body] \n";
        whil.stmt_block_->accept(*this);
        spazio_ -= 2;
    }

    void visit(IfStmt const& iff)override{
        console_<<spazioTree()<<"[IF] \n";
        spazio_ += 2; 
        console_<<spazioTree()<<"[if condition] : \n";
        iff.bool_expr->accept(*this);

        console_<<spazioTree()<<"[if statement] : \n";
        iff.stmt_block1->accept(*this);

        console_<<spazioTree()<<"[else statement] : \n";
        iff.stmt_block2->accept(*this);

        spazio_ -= 2;
 
    }
    
    void visit(SetStmt const& set)override{
        console_<<spazioTree()<<"[SET] \n";
        spazio_ += 2;
        set.variable_id_->accept(*this);
        set.num_expr_->accept(*this);
        spazio_ -= 2;
    }

    void visit(Operator const& op)override{
        console_<<spazioTree()<<"[OPERATOR] \n";
        spazio_ +=2 ; 
        op.left_->accept(*this);
        op.right_->accept(*this);
        spazio_ -= 2 ; 
    }

    void visit(Number const& num)override{
        console_<<spazioTree()<<"[CONST] ";
        console_<<"value: "<<num.n_<<"\n";
    }

    void visit(Variable const& var)override{
        console_<<spazioTree()<<"[VARIABLE] ";

        console_<<"name: "<<var.id_<<"\n";
    }

    void visit(BoolOp const& boolop)override{
        console_<<spazioTree()<<"[BOOLOP] \n";
        spazio_+=2; 
        boolop.op1->accept(*this);
        boolop.op2->accept(*this);
        spazio_-=2 ; 
    }

    void visit(BoolConst const& boolconst)override{
        console_<<spazioTree()<<"[BOOLCONST]";

        console_<<" value: "<<boolconst.boolean<<"\n";

    }

    void visit(RelOp const& relop)override{
        console_<<spazioTree()<<"[RELOP]\n";
        spazio_+=2;
        relop.num1_l->accept(*this);
        relop.num2_r->accept(*this);
        spazio_-=2;
    }

private:
    std::ostream &console_;
    int spazio_;

    std::string spazioTree() const
    {
        return std::string(spazio_, ' ');
    }
};
#endif