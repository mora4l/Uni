#if !defined(EVALUATION_VISITOR_H)
#define EVALUATION_VISITOR_H

#include <iostream>

#include "Visitor.h"
#include "SymbolTable.h"

class EvaluationVisitor : public Visitor
{
public:
    EvaluationVisitor();
    EvaluationVisitor(SymbolTable &st, std::ostream &con) : symbolTable_{st}, console_{con} {}
    ~EvaluationVisitor() = default;
    EvaluationVisitor &operator=(const EvaluationVisitor &other) = delete;

    void visit(Block const &block) override
    { // da controllare
        for (Statement *statement : block.statements_)
        {
            statement->accept(*this);
            console_ << std::endl;
        }
    }

    void visit(PrintStmt const &print) override
    {
        print.num_expr_->accept(*this);
        console_ << lastValue_ << std::endl;
    }

    void visit(InputStmt const &in) override
    {
        int value = 0;
        console_ << "Inserisci il valore di " << in.variable_id_->id_ << " : ";
        std::cin >> value;
        symbolTable_.setValue(in.variable_id_->id_, value);
    }

    // void visit(WhileStmt const& whil) override{
    //     whil.bool_expr_->accept(*this); //ottengo il risultato della bool expr (true o false)
    //     whil.stmt_block_->accept(*this);
    // da completare

    // }

    void visit(IfStmt const &iff) override
    {
        iff.bool_expr->accept(*this);
        if (lastValue_)
        { // da controllare
            iff.stmt_block1->accept(*this);
        }
        else
        {
            iff.stmt_block2->accept(*this);
        }
    }

    void visit(SetStmt const &set) override
    {
        // int value = symbolTable_.getValue(set.variable_id_->id_); //devo estrarre dall'oggetto Variable* la variabile id  . perche set ha un oggetto Variable ma che va estratto a sua volta per prendere l'attributo di quell oggetto
        set.num_expr_->accept(*this);
        symbolTable_.setValue(set.variable_id_->id_, lastValue_);
    }

    void visit(Operator const &op) override
    {
        op.right_->accept(*this);
        int ris_op_r = lastValue_;

        op.left_->accept(*this);

        int ris_op_l = lastValue_;

        if (op.opCode_ == 0)
        {
            lastValue_ = ris_op_l + ris_op_r;
        }
        else if (op.opCode_ == 1)
        {
            lastValue_ = ris_op_l - ris_op_r;
        }
        else if (op.opCode_ == 2)
        {
            lastValue_ = ris_op_l * ris_op_r;
        }
        else if (op.opCode_ == 3)
        {

            if (ris_op_l != 0)
            {

                lastValue_ = ris_op_l / ris_op_r;
            }
            else
            {
                std::stringstream temp;
                temp << "Divisione per zero non ammessa" << std::endl;
                throw EvaluationError{temp.str()};
            }
        }
    }

    void visit(Number const& num) override{ //questo è il caso base , il nodo foglia
        lastValue_ = num.n_;
    }

    void visit(Variable const& var)override{
        lastValue_ = symbolTable_.getValue(var.id_); //?? da capire
    }

    /*da finire bool op , bool const e rel op*/

private:
    SymbolTable &symbolTable_;
    std::ostream &console_;
    int lastValue_;
};

#endif