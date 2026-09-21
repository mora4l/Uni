#if !defined(EVALUATION_VISITOR_H)
#define EVALUATION_VISITOR_H

#include <iostream>
#include <algorithm>
#include "Visitor.h"
#include "SymbolTable.h"

class EvaluationVisitor : public Visitor
{

public:
    /*
    implemento tutti i costruttori / distruttori necessari
    */
    EvaluationVisitor();
    EvaluationVisitor(SymbolTable &st, std::ostream &con) : symbolTable_{st}, console_{con} {}
    virtual ~EvaluationVisitor() = default;                                // è il distruttore usato di default e lo dichiaro virtual in quanto è una classe con metodi virtuali
    EvaluationVisitor &operator=(const EvaluationVisitor &other) = delete; // operatore di assegnamento

    void visit(Program const &program) override
    {
        program.root_->accept(*this); // con la visit di program inizio a esplorare la root dell'albero
    }

    void visit(Block const &block) override
    {

        for (Statement *statement : block.statements_)
        {
            statement->accept(*this); // qui inizio a scorrere ogni statement all'interno del vettore statements_
        }
    }

    void visit(PrintStmt const &print) override
    {
        print.num_expr_->accept(*this); // visitiamo ciò che c'è da stampare e poi lo stampiamo
        console_ << lastValue_ << std::endl;
    }

    /*
    per la input abbiamo un problema : devo capire (come nella funzione "tokenizzacostanti" di Tokenizer.cpp) se la cifra inserita è un intero positivo o negativo
    qua pero lavoriamo con una string e non una stringstream   quindi non posso scorrere come prima la stringa subito e controllare se c'è un "."
    */
    void visit(InputStmt const &in) override
    {

        console_ << "Inserisci il valore di " << in.variable_id_->id_ << " : ";

        std::string stringaDaConsole;
        std::getline(std::cin, stringaDaConsole);

        size_t start = 0; // partiamo dall'indice zero della stringa in cui ho messo il valore
        int64_t value;
        if (!stringaDaConsole.empty()) // se la stringa non è vuota continuo a ispezionarla per capire se è un intero positivo o negativo, altrimenti posso anche fermarmi qui
        {

            if (stringaDaConsole[0] == '-') // se il primo valore è un "-"
            {
                start = 1; // allora parto dal char dopo a capire se si tratta di un intero
            }

            /*ora qui uso una funzione senzanome con una funzione di <algorithm> : ritorna vero se scorrendo la stringa attraverso std::all_of
            (la funzione di <algorithm>) (dall'inizio della stringa con begin +indice fino a end) legge solo numeri e quindi non è frazionario (usando un char c generico dichiarato dentro) :
            in pratica parte dall inizio della stringa (stringaDaConsole.begin()) e va avanti fino alla fine (stringaDaConsole.end()) attraverso un char c generico
            */
            if ((start < stringaDaConsole.size()) && std::all_of(stringaDaConsole.begin() + start, stringaDaConsole.end(), [](unsigned char c)
                                                                 { return std::isdigit(c); }))

            {
                char ch2 = stringaDaConsole[start]; // prima di proseguire devo assicurarmi che dopo un presunto 0 non ci siano altri valori

                if (ch2 == '0')
                {
                    char ch3 = stringaDaConsole[start + 1];
                    if (std::isdigit(ch3))
                    {
                        std::stringstream temp;
                        temp << "Multiple numbers after zero in input";
                        throw EvaluationError{temp.str()};
                    }
                }

                try
                {                                         // uso un try catch nel caso il valore inserito superi la grandezza consentita e la stoll dia problemi
                    value = std::stoll(stringaDaConsole); // la stoll invece mi serve per convertire la stringa in un int long long (stoi invece mi andrebbe bene per un int normale ma qui non ci serve)
                }
                catch (...)
                { // metto i "..." e non EvaluationError perchè altrimenti non mi funziona

                    throw EvaluationError{"Too many values in input "};
                }
                symbolTable_.setValue(in.variable_id_->id_, value); // input funziona che : se non ha mai letto la variabile la crea , mentre se esiste già la sovrascrive. quindi in ogni caso usiamo setValue della symbolTable
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
    programma per check correttezza while
        (BLOCK
    (SET n 10)
    (WHILE (GT n 0) (BLOCK (PRINT n) (SET n (SUB n 1))))
    )
    */
    void visit(WhileStmt const &whil) override
    {

        bool condizione_while;

        whil.bool_expr_->accept(*this); // ottengo il risultato della bool expr (true o false)

        condizione_while = lastBoolValue_; // e me lo salvo in una variabile, intanto l'albero continua ad essere esplorato

        while (condizione_while) // l'esecuzione non avviene se bool_expr è falsa in partenza
        {                        // il while verifica "condizione_while" per la prima volta , poi pero devo trovare un modo di fermarmi se "condizione_while" non fosse più vera

            whil.stmt_block_->accept(*this); // se entro nel while eseguo tutto cio che ho da eseguire

            whil.bool_expr_->accept(*this);    // e alla fine di tutto cio che ho eseguito ri-controllo la condizione di partenza, eseguendo di nuovo i calcoli necessari
            condizione_while = lastBoolValue_; // se la condizione_while non dovesse essere più valida , il while uscirà alla prossima iterazione
        }
    }

    /*
    programma per check correttezza if
    (BLOCK
    (SET n 10)
    (IF (LT n 100) (PRINT 23) (PRINT 67 ))
    )
    */
    void visit(IfStmt const &iff) override
    {

        iff.bool_expr->accept(*this);
        if (lastBoolValue_ == true) // se è vera la prima condizione allora  lastBoolValue_ è 1
        {
            iff.stmt_block1->accept(*this);
        }
        else
        {
            iff.stmt_block2->accept(*this);
        }
    }

    void visit(SetStmt const &set) override
    {
        // devo estrarre dall'oggetto Variable* la variabile id  . perche set ha un oggetto Variable ma che va estratto per prendere l'attributo di quell oggetto

        set.num_expr_->accept(*this);
        symbolTable_.setValue(set.variable_id_->id_, lastValue_);
    }

    void visit(Operator const &op) override
    {

        op.right_->accept(*this); // qui andiamo ad ottenere i due operandi (figlio destro e sinistro )
        int64_t ris_op_r = lastValue_;

        op.left_->accept(*this);

        int64_t ris_op_l = lastValue_;

        if (op.opCode_ == 0) // e poi in base all'operatore che abbiamo smistiamo i casi . opCode l'ho dichiarato in Syntax.h e l'ho gestito in Syntax.cpp
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

            if (ris_op_r == 0) // nel caso della divisione , prima di tutto devo controllare se ho il denominatore = 0
            {
                std::stringstream temp;
                temp << "Division by zero.";
                throw EvaluationError{temp.str()};
            }
            else // solo ora posso procedere . se non faccio cosi mi genera un segmentation fault in caso di divisioni per zero
            {
                lastValue_ = ris_op_l / ris_op_r;
            }
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

        // 1 AND 0 nell'albero viene creato con 0 a destra e 1 a sinistra , ma poi nella visita guardo prima il destro .

        /*
        //prima creo il primo valore che c'è sempre , sia per AND che OR che NOT . il secondo non lo creo sempre perchè se
        l'operatore fosse NOT , nel costruttore in syntax.h quando lo chiamo da parser.h in parseBoolExpr non riuscirebbe a gestire il secondo operatore
        */

        boolop.op1->accept(*this);
        bool boolop_r = lastBoolValue_;

        if (boolop.boolOpCode_ == 0) // siamo nel caso AND
        {
            if (boolop_r == false)
            {                           // per cortocircuitare gli operatori AND e OR devo fare questo controllo (a quanto pare comunque fare l'operazione direttamente && cortocircuita già tutto)
                lastBoolValue_ = false; // operatore cortocircuitato : se il primo operando è già falso , allora il secondo non lo valuto neanche
            }
            else
            {
                boolop.op2->accept(*this); // solo ora ho capito che il primo operando non è FALSO e in più l'operatore non è NOT , quindi creo il secondo valore
                bool boolop_l = lastBoolValue_;
                lastBoolValue_ = boolop_l && boolop_r;
            }
        }
        else if (boolop.boolOpCode_ == 1) // siamo nel caso OR
        {

            if (boolop_r == true)
            {                          // stessi discorsi di AND
                lastBoolValue_ = true; // operatore cortocircuitato : se il primo operando è già vero , allora il secondo non lo valuto neanche
            }
            else
            {
                boolop.op2->accept(*this);
                bool boolop_l = lastBoolValue_;
                lastBoolValue_ = boolop_l || boolop_r;
            }
        }
        else if (boolop.boolOpCode_ == 2) // siamo nel caso NOT
        {
            lastBoolValue_ = !boolop_r; // op1 , quello definito nel costruttore fatto apposta per il not in syntax.h , l'ho salvato in boolop_r
        }
    }

    void visit(BoolConst const &boolconst) override
    {
        lastBoolValue_ = boolconst.boolean;
    }

    void visit(RelOp const &relop) override
    {

        relop.num1_l->accept(*this);
        int64_t relop_1 = lastValue_; // questo è il primo valore

        relop.num2_r->accept(*this);
        int64_t relop_2 = lastValue_; // questo il secondo

        if (relop.relCode_ == 0) // vado a gestire tutti i casi possibili . relCode è definito in Syntax.h e gestito in Syntax.cpp
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
    }

private:
    SymbolTable &symbolTable_;
    std::ostream &console_;
    int64_t lastValue_;
    bool lastBoolValue_;
};

#endif