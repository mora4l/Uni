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

    void visit(Program const& program)override{
        program.root_->accept(*this); //con la visit di program inizio a esplorare la root dell'albero
    }
    void visit(Block const &block) override
    { 
        for (Statement *statement : block.statements_)
        {
            statement->accept(*this);
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

    void visit(WhileStmt const& whil) override{
        bool condizione_while ;

        whil.bool_expr_->accept(*this); //ottengo il risultato della bool expr (true o false)
        
        condizione_while =  lastBoolValue_ ; //e me lo salvo in una variabile

        while(condizione_while){ //il while verifica "condizione_while" per la prima volta , poi pero devo trovare un modo di fermarmi se "condizione_while" non fosse più vera
            whil.stmt_block_->accept(*this); //se entro nel while eseguo tutto cio che ho da eseguire

            whil.bool_expr_->accept(*this); // e alla fine di tutto cio che ho eseguito ri-controllo la condizione , eseguendo di nuovo i calcoli necessari
            condizione_while = lastBoolValue_ ;  //se la condizione_while non dovesse essere più valida , il while finisce
            
        }
    }

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
        lastValue_ = symbolTable_.getValue(var.id_);  //mi ritorna il valore associato a quella variabile
    }

    void visit(BoolOp const& boolop) override{
        boolop.op1->accept(*this);
        bool boolop_r = lastBoolValue_;

        boolop.op2->accept(*this);
        bool boolop_l = lastBoolValue_; 

        // 1 AND 0 nell'albero viene creato con 0 a destra e 1 a sinistra , ma poi nella visita guardo prima il destro . quindi devo usarli "al contrario"
        if(boolop.boolOpCode_ == 0 ){
            lastBoolValue_ = boolop_l && boolop_r ; 
        }else if(boolop.boolOpCode_ == 1){
            lastBoolValue_ = boolop_l || boolop_r ; 
        }else if(boolop.boolOpCode_ == 2){
            lastBoolValue_ = !boolop_r ;  //op1 , quello definito nel costruttore fatto apposta per il not in syntax.h , l'ho salvato in boolop_r
        }
    }

    void visit(BoolConst const& boolconst) override{
        lastBoolValue_ = boolconst.boolean ; 
    }

    void visit(RelOp const& relop) override{
        relop.num1_l->accept(*this);
        bool relop_r = lastBoolValue_ ; 

        relop.num2_r->accept(*this) ;
        bool relop_l = lastBoolValue_ ; 

        if(relop.relCode_ == 0 ){
            if(relop_l < relop_r){
                lastBoolValue_ = true ; 
            }else{
                lastBoolValue_ = false ; 
            }
        }else if(relop.relCode_ == 1){
            if(relop_l > relop_r){
                lastBoolValue_ = true ; 
            }else{
                lastBoolValue_ = false ; 
            }
        }else if(relop.relCode_ == 2){
            if(relop_l == relop_r){
                lastBoolValue_ = true ; 
            }else{
                lastBoolValue_ = false ; 
            }
        }
    }

private:
    SymbolTable &symbolTable_;
    std::ostream &console_;
    int lastValue_;
    bool lastBoolValue_ ; 
};

#endif