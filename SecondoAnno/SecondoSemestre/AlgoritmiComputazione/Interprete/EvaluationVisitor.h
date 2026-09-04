#if !defined(EVALUATION_VISITOR_H)
#define EVALUATION_VISITOR_H

#include <iostream>
#include <algorithm>
#include "Visitor.h"
#include "SymbolTable.h"

class EvaluationVisitor : public Visitor
{
public:
    EvaluationVisitor();
    EvaluationVisitor(SymbolTable &st, std::ostream &con) : symbolTable_{st}, console_{con} {}
    ~EvaluationVisitor() = default;
    EvaluationVisitor &operator=(const EvaluationVisitor &other) = delete;

    void visit(Program const &program) override
    {
        program.root_->accept(*this); // con la visit di program inizio a esplorare la root dell'albero
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
        try{ //uso il try catch per poter specificare meglio da dove arrivare l'errore . 

            print.num_expr_->accept(*this);
            console_ << lastValue_ << std::endl;
        }catch(EvaluationError &e){ //in questo modo getValue in Symboltable crea un oggetto EvalutationError , che posso ristampare qua attraverso what
            std::stringstream temp;
            temp << "You must define a variable with INPUT or SET before using it" <<std::endl<<"("<< e.what() <<")"; 
            throw EvaluationError{temp.str()};
        }
    }

/*
per la input abbiamo un problema : devo capire , come in tokenizzacostanti nel tokenizzatore , se la cifra inserita è un intero positivo o negativo
qua pero lavoriamo con una string e non una stringstream   quindi non posso scorrere come prima la stringa subito e controllare se c'è un "."
*/
    void visit(InputStmt const &in) override
    {
        console_ << "Inserisci il valore di " << in.variable_id_->id_ << " : ";

        std::string stringaDaConsole;
        std::getline(std::cin, stringaDaConsole);

        size_t start = 0; //partiamo dall'indice zero della stringa in cui ho messo il valore

        if (!stringaDaConsole.empty())//se la stringa non è vuota continuo a ispezionarla per capire se è un intero positivo o negativo, altrimenti posso anche fermarmi qui
        {

            if (stringaDaConsole[0] == '-') //se il primo valore è un "-" 
            {
                start = 1; //allora parto dal char dopo a capire se si tratta di un intero 
            }
/*ora qui uso una funzione senzanome con una funzione di <algorithm> : ritorna vero se scorrendo la stringa attraverso std::all_of (la funzione di <algorithm>) legge solo numeri
in pratica parte dall inizio della stringa (stringaDaConsole.begin()) e va avanti fino alla fine (stringaDaConsole.end()) attraverso un char c generico
*/
            if ((start < stringaDaConsole.size()) && std::all_of(stringaDaConsole.begin() + start, stringaDaConsole.end(),[](unsigned char c){ return std::isdigit(c); }))
            {
                int64_t value = std::stoll(stringaDaConsole); //la stoll invece mi serve per convertire la stringa in un int long long (stoi invece mi andrebbe bene per un int normale)
                symbolTable_.setValue(in.variable_id_->id_, value); //input funziona che : se non ha mai letto la variabile la crea , mentre se esiste già la sovrascrive . set invece ha un controllo in più : prima di sovrascriverla si chiede se esiste già
            }
            else
            {
                std::stringstream temp;
                temp << "Only positive or negative integer allowed without space between numbers";
                throw EvaluationError{temp.str()};
            }
        }
        else
        {
            std::stringstream temp;
            temp << in.variable_id_->id_ << " cannot be empty.";
            throw EvaluationError{temp.str()};
        }
    }

/*
check correttezza while
    (BLOCK 
(SET n 10)
(WHILE (GT n 0) (BLOCK (PRINT n) (SET n (SUB n 1))))
)
    */
    void visit(WhileStmt const &whil) override
    {
        bool condizione_while;

        whil.bool_expr_->accept(*this); // ottengo il risultato della bool expr (true o false)

        condizione_while = lastBoolValue_; // e me lo salvo in una variabile

        while (condizione_while) //l'esecuzione non avviene se bool_expr è falsa in partenza
        {                                    // il while verifica "condizione_while" per la prima volta , poi pero devo trovare un modo di fermarmi se "condizione_while" non fosse più vera
            whil.stmt_block_->accept(*this); // se entro nel while eseguo tutto cio che ho da eseguire

            whil.bool_expr_->accept(*this);    // e alla fine di tutto cio che ho eseguito ri-controllo la condizione , eseguendo di nuovo i calcoli necessari
            condizione_while = lastBoolValue_; // se la condizione_while non dovesse essere più valida , il while finisce
        }
    }

    /*
check correttezza if
(BLOCK 
(SET n 10)
(IF (LT n 100) (PRINT 23) (PRINT 67 ))
)
*/
    void visit(IfStmt const &iff) override
    {
        try{//stesso discorso fatto nella visit di print

            iff.bool_expr->accept(*this);
        
            if (lastBoolValue_)
            { // da controllare
                iff.stmt_block1->accept(*this);
            }
            else
            {
                iff.stmt_block2->accept(*this);
            }
        }catch(EvaluationError& e){
            std::stringstream temp;
            temp << "You must define a variable with INPUT or SET before using it in IF statement" <<std::endl<<"("<< e.what() <<")"; 
            throw EvaluationError{temp.str()};
        }
    }

    void visit(SetStmt const &set) override
    {
        // devo estrarre dall'oggetto Variable* la variabile id  . perche set ha un oggetto Variable ma che va estratto a sua volta per prendere l'attributo di quell oggetto
        try{

            set.num_expr_->accept(*this);
            symbolTable_.setValue(set.variable_id_->id_, lastValue_);
        }catch(EvaluationError& e){
            throw EvaluationError{e.what()};
        }
    }

    void visit(Operator const &op) override
    {
/*
metto try cosi se ce un problema più in basso che blocca l'esecuzione posso capire in che parte del codice è . 
se per esempio dentro ad una ADD ho una variabile non dichiarata , allora la variabile non dichiarata lancerà un errore che verrà a sua volta preso 
da questo try affinchè si capisca meglio da dove viene l'errore
*/
        try{
            op.right_->accept(*this);
            int64_t ris_op_r = lastValue_;
    
            op.left_->accept(*this);
    
            int64_t ris_op_l = lastValue_;
    
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
        }catch(EvaluationError& e){
                                std::stringstream temp;
                    temp << "You can't use an operator with this problem : " <<std::endl<<e.what();
                    throw EvaluationError{temp.str()};
        }
    }

    void visit(Number const &num) override
    { // questo è il caso base , il nodo foglia
        lastValue_ = num.n_;
    }

    void visit(Variable const &var) override
    {

            lastValue_ = symbolTable_.getValue(var.id_); // mi ritorna il valore associato a quella variabile

    }

    void visit(BoolOp const &boolop) override
    {
/*
metto try cosi se ce un problema più in basso che blocca l'esecuzione posso capire in che parte del codice è . 
se per esempio dentro ad una AND ho una variabile non dichiarata , allora la variabile non dichiarata lancerà un errore che verrà a sua volta preso 
da questo try affinchè si capisca meglio da dove viene l'errore
*/
        try{

            boolop.op1->accept(*this);
            bool boolop_r = lastBoolValue_;
    
            boolop.op2->accept(*this);
            bool boolop_l = lastBoolValue_;
    
            // 1 AND 0 nell'albero viene creato con 0 a destra e 1 a sinistra , ma poi nella visita guardo prima il destro . quindi devo usarli "al contrario"
            if (boolop.boolOpCode_ == 0)
            {
                lastBoolValue_ = boolop_l && boolop_r;
            }
            else if (boolop.boolOpCode_ == 1)
            {
                lastBoolValue_ = boolop_l || boolop_r;
            }
            else if (boolop.boolOpCode_ == 2)
            {
                lastBoolValue_ = !boolop_r; // op1 , quello definito nel costruttore fatto apposta per il not in syntax.h , l'ho salvato in boolop_r
            }
        }catch(EvaluationError& e){
                                std::stringstream temp;
                    temp << "You can't use an operator with this problem : " <<std::endl<<e.what();
                    throw EvaluationError{temp.str()};
        }
    }

    void visit(BoolConst const &boolconst) override
    {
        lastBoolValue_ = boolconst.boolean;
    }

    void visit(RelOp const &relop) override
    { 
/*
metto try cosi se ce un problema più in basso che blocca l'esecuzione posso capire in che parte del codice è . 
se per esempio dentro ad una LT ho una variabile non dichiarata , allora la variabile non dichiarata lancerà un errore che verrà a sua volta preso 
da questo try affinchè si capisca meglio da dove viene l'errore
*/
        try{

            relop.num1_l->accept(*this);
            int64_t relop_1 = lastValue_; //questo è il primo valore nell IF 
    
    
            relop.num2_r->accept(*this);
            int64_t relop_2 = lastValue_; //questo il secondo
    
    
            if (relop.relCode_ == 0)
            {
                if (relop_1 < relop_2)
                {
    
                    lastBoolValue_ = true;
                }
                else
                {
                    lastBoolValue_ = false;
                }
            }
            else if (relop.relCode_ == 1)
            {
                if (relop_1 > relop_2)
                {
                    lastBoolValue_ = true;
                }
                else
                {
                    lastBoolValue_ = false;
                }
            }
            else if (relop.relCode_ == 2)
            {
                if (relop_1 == relop_2)
                {
                    lastBoolValue_ = true;
                }
                else
                {
                    lastBoolValue_ = false;
                }
            }
        }catch(EvaluationError& e){
                                std::stringstream temp;
                    temp << "You can't use an operator with this problem : " <<std::endl<<e.what();
                    throw EvaluationError{temp.str()};
        }
    }

private:
    SymbolTable &symbolTable_;
    std::ostream &console_;
    int64_t lastValue_;
    bool lastBoolValue_;
};

#endif