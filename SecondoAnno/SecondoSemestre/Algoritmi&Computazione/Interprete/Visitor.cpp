#include "Visitor.h"
#include <iostream>
/*
da finire , intanto faccio parser
qua ho fatto solo l'identificazione dei simboli degli operatori algebrici/booleani
*/
class InterpreterVisitor : public Visitor{
    public :
    void visit (Program const& program)override{
        program.root_->accept(*this);
    }

    void visit(RelOp const& relop) override{
        relop.num1_l->accept(*this) ; 
        int temp_l=valore_sinistra;
        relop.num2_r->accept(*this);

        switch(relop.relCode_){
            case RelOp::LT : 
            if(temp_l < valore_sinistra){
                valore_sinistra = true ; 
            }else{
                valore_sinistra = false ; 
            }
            break ;

            case RelOp::GT : 
            if(temp_l > valore_sinistra){
                valore_sinistra = true ; 
            }else{
                valore_sinistra = false ; 
            }
            break;

            case RelOp::EQ : 
            if(temp_l == valore_sinistra){
                valore_sinistra = true ; 
            }else{
                valore_sinistra = false ; 
            }
            break; 

            default : 
            std::cerr<<"operatore relazionale sconosciuto" ; 
            break;
        }
    }

    void visit(BoolOp const& boolop) override{
        boolop.op1->accept(*this) ;  //metto op1  in temp perche leggendo op2 sovrascriverei valore_sinistra
        int temp_l = valore_sinistra;

        switch(boolop.boolOpCode_){
            

            case BoolOp::AND : 
            if(temp_l == false){ //cortocircuitato
                valore_sinistra = false ; 
            }else{

                boolop.op2->accept(*this); // leggo il secondo solo se non è not
                
                valore_sinistra = temp_l && valore_sinistra ; 
            }
            break ;

            case BoolOp::OR :
            
            if(temp_l == true){//cortocircuitato
                valore_sinistra  = true ; 
            }else{

                boolop.op2->accept(*this); 
                valore_sinistra = temp_l || valore_sinistra ; 
            }
            break;

            case BoolOp::NOT : 
            valore_sinistra =  !valore_sinistra; 

            break; 

            default : 
            std::cerr<<"operatore booleano sconosciuto" ; 
            break;
        }
    }

    void visit(Operator const& op) override{
        op.left_->accept(*this) ; 
        int temp_l = valore_sinistra;
        op.right_->accept(*this);

        switch(op.opCode_){
            case Operator::PLUS : 
            valore_sinistra += temp_l; 
            break ;

            case Operator::MINUS : 
            valore_sinistra = temp_l - valore_sinistra; 
            break;

            case Operator::TIMES : 
            valore_sinistra *= temp_l; 
            break; 

            case Operator::DIV : 
            if(valore_sinistra == 0){
                //errore
            }
            valore_sinistra = temp_l / valore_sinistra; 
            break ; 
            default : 
            std::cerr<<"operatore aritmetico sconosciuto" ; 
            break;
        }
    }
    int valore_sinistra;
};