#include <sstream>
#include "Parser.h"

// partiamo ad effettuare il parsing di tutto il programma che abbiamo "letto" durante la tokenizzazione

/*** program -> ***/
Program *Parser::parseProgram(std::vector<Token>::const_iterator &itr)
{

    Block *programma_parsabile = parseStmtBlock(itr); // iniziamo creando un programma che viene definito come block . poi da qui potrà essere una serie di statement block oppure solo uno
    return new Program{programma_parsabile};
}
Block *Parser::parseStmtBlock(std::vector<Token>::const_iterator &itr)
{
    /*
    stmt block → statement | ( BLOCK statement list )

    prima cosa da chiedersi : il codice in input è uno statement solo oppure è una lista di statement ?
    */
    if (itr->tag == Token::LP)
    {                   // intanto sicuramente il codice deve contenere "(" per iniziare
        safe_next(itr); // leggo il carattere dopo...
        if (itr->tag == Token::KWORD && itr->word == "BLOCK")
        { // qua ci sono due casi : se ce scritto BLOCK allora ci sarà un solo block da leggere...
            return parseBlock(itr);
        }
        else if (itr->tag == Token::KWORD)
        { // se invece non ce scritto block ,ma un altra keyword , allora potrebbe essere uno statement (potrebbe, perche devo ancora capire di che altra keyword si tratta)

            // se è uno statement , ho già letto una "(" che FARA GIA PARTE DELLO STATEMENT , quindi dovro controllare a fine parseStatement (che devo ancora dichiarare e sviluppare) se ce la ")" finale

            std::vector<Statement *> temp;       // qua ho un problema : se faccio return parseStatement mi ritorna un Statement* , cosa che non posso permettermi perche questa funzione ritorna un Block*, quindi devo creare un vettore ausiliario uguale al tipo supportato da Block
            temp.push_back(parseStatement(itr)); // ci metto dentro l'unico elemento analizzato (uno statement solo , che vado a leggere)
            return new Block(std::move(temp));   // e poi ritorno un nuovo Block creato con un vettore che ha un solo elemento (un solo statement)
        }
        else
        { // se non era né un BLOCK e tantomeno una keyword generica , allora ce un problema di fondo di sintassi
            std::stringstream temp;
            temp << "Missing BLOCK statement or another one at token " << *itr;
            throw SyntaxError{temp.str()};
        }
    }
    else
    { // ancora peggio se il codice non iniziava manco con una "("
        std::stringstream temp;
        temp << "Missing left parenthesis at token " << *itr;
        throw SyntaxError{temp.str()};
    }
}

/*** stmt_list -> ***/

Block *Parser::parseBlock(std::vector<Token>::const_iterator &itr)
{
    // arrivati qui ho letto "BLOCK"
    safe_next(itr); // avanzo e...

    // statement list → statement statement list | statement
    // ( BLOCK (SET x x )  )
    /*
    //faccio un vector di statement : questo perchè ho deciso che se lo statement_list ha un elemento , ritornerò nel vettore un solo elemento ;
    altrimenti ritornero un vettore con più elementi
    */
    std::vector<Statement *> another_statement;

    while (itr->tag != Token::RP) // finchè non incontro la ")" del BLOCK da cui ho chiamato questa funzione , dentro ci saranno statement da leggere (se tutto va bene)
    {

        if (itr->tag == Token::LP)
        { // dopo BLOCK PER FORZA ci deve essere uno statement , quindi PER FORZA DEVE ESSERCI "(". la ")" la leggero in ParseStatement , come facevo in parseSetStmtBlock
            safe_next(itr);
            another_statement.push_back(parseStatement(itr));
        }
        else
        {
            std::stringstream temp;
            temp << "Overflow in token stream. " << *itr;
            throw SyntaxError{temp.str()};
        }
    }
    if (another_statement.empty())
    { // se il vettore è vuoto vuol dire che dopo BLOCK non c'era una "(" e che quindi non è stato in grado nemmeno di costruire uno statement
        std::stringstream temp;
        temp << "Empty BLOCK statement" << *itr;
        throw SyntaxError{temp.str()};
    }
    else
    {                   // altrimenti il vettore è pieno di roba e ritorno
        safe_next(itr); // consumo la ")" finale che mi ha fatto uscire dal ciclo
        return new Block(std::move(another_statement));
    }
}

/*** statement -> ***/

Statement *Parser::parseStatement(std::vector<Token>::const_iterator &itr)
{

    if (itr->tag == Token::KWORD) // gestisco tutti i casi di statement che possiamo avere ...
    {
        if (itr->word == "SET")
        {
            return parseSetStmt(itr);
        }
        else if (itr->word == "INPUT")
        {
            return parseInputStmt(itr);
        }
        else if (itr->word == "PRINT")
        {
            return parsePrintStmt(itr);
        }
        else if (itr->word == "IF")
        {
            return parseIfStmt(itr);
        }
        else if (itr->word == "WHILE")
        {
            return parseWhileStmt(itr);
        }
        else // se non è nessuno dei precedenti allora c'è un problema di fondo
        {
            std::stringstream temp;
            temp << "Cannot parse Statement at token " << *itr;
            throw SyntaxError{temp.str()};
        }
    }
    else // se non c'era nemmeno un token di tipo keyword , ancora peggio
    {
        std::stringstream temp;
        temp << "Missing a statement at token " << *itr;
        throw SyntaxError{temp.str()};
    }
}

/*** variable_def -> ***/

SetStmt *Parser::parseSetStmt(std::vector<Token>::const_iterator &itr)
{
    safe_next(itr); // dopo aver letto SET avanzo

    /*AVVISO
    in qualche commit vecchio avevo messo , per ogni componente di ogni statement da creare , un trycatch per definire meglio la provenienza dell'errore .
    ma visto che non viene richiesto l'ho levato
    */
    Variable *variabile_set = parseVariable(itr); // creo ciò che serve a set per esistere . se ci saranno degli errori interni li segnalerò durante la creazione stessa
    NumExpr *valore_set = parseNumExpr(itr);

    if (itr->tag == Token::RP) // solito controllo finale da definizione di cfg
    {
        safe_next(itr);
        return new SetStmt(variabile_set, valore_set);
    }
    else
    {
        delete valore_set;
        std::stringstream temp;
        temp << "Missing right parenthesis at token " << *itr;

        throw SyntaxError{temp.str()};
    }
}

/*** io_stmt -> ***/

InputStmt *Parser::parseInputStmt(std::vector<Token>::const_iterator &itr)
{
    safe_next(itr);                                 // dopo aver letto INPUT avanzo
                                                    /*AVVISO
                                                    in qualche commit vecchio avevo messo , per ogni componente di ogni statement da creare , un trycatch per definire meglio la provenienza dell'errore .
                                                    ma visto che non viene richiesto l'ho levato
                                                    */
    Variable *variabile_input = parseVariable(itr); // creo ciò che serve allo statement input

    if (itr->tag == Token::RP)
    {
        safe_next(itr);
        return new InputStmt(variabile_input);
    }
    else
    {
        delete variabile_input;
        std::stringstream temp;
        temp << "Missing right parenthesis at token " << *itr;
        throw SyntaxError{temp.str()};
    }
}

PrintStmt *Parser::parsePrintStmt(std::vector<Token>::const_iterator &itr)
{
    safe_next(itr); // dopo aver letto PRINT avanzo

    /*AVVISO
    in qualche commit vecchio avevo messo , per ogni componente di ogni statement da creare , un trycatch per definire meglio la provenienza dell'errore .
    ma visto che non viene richiesto l'ho levato
    */
    NumExpr *num_expr_print = parseNumExpr(itr);

    if (itr->tag == Token::RP)
    {
        safe_next(itr);
        return new PrintStmt(num_expr_print);
    }
    else
    {
        //!!!!sarebbe da eliminare i blocchi creati prima di capire che era tutto sbagliato !!!!
        delete num_expr_print;
        std::stringstream temp;
        temp << "Missing right parenthesis at token " << *itr;
        throw SyntaxError{temp.str()};
    }
}

/*** cond_stmt -> ***/

IfStmt *Parser::parseIfStmt(std::vector<Token>::const_iterator &itr)
{

    safe_next(itr); // dopo aver letto il tipo di statement vado avanti...

    /*AVVISO
    in qualche commit vecchio avevo messo , per ogni componente di ogni statement da creare , un trycatch per definire meglio la provenienza dell'errore .
    ma visto che non viene richiesto l'ho levato
    */
    // ci sono 3 cose che devo creare :
    BoolExpr *condizione_if = parseBoolExpr(itr);
    Block *blocco_then = parseStmtBlock(itr);
    Block *blocco_else = parseStmtBlock(itr);

    // e se è andato tutto bene , sono arrivato qui che ho tutte le espressioni dell'IfStmt lette FINO ALLA ")" GIA LETTA
    if (itr->tag == Token::RP)
    {
        safe_next(itr); // mi porto avanti col prossimo token da leggere
        return new IfStmt(condizione_if, blocco_then, blocco_else);
    }
    else
    {
        delete condizione_if;
        delete blocco_else;
        delete blocco_then;
        std::stringstream temp;
        temp << "Missing right parenthesis at token " << *itr;
        throw SyntaxError{temp.str()};
    }
}

/*** loop_stmt -> ***/

WhileStmt *Parser::parseWhileStmt(std::vector<Token>::const_iterator &itr)
{
    safe_next(itr); // dopo aver letto WHILE avanzo

    /*AVVISO
    in qualche commit vecchio avevo messo , per ogni componente di ogni statement da creare , un trycatch per definire meglio la provenienza dell'errore .
    ma visto che non viene richiesto l'ho levato
    */
    BoolExpr *condizione_while = parseBoolExpr(itr);
    Block *blocco_while = parseStmtBlock(itr);

    // se è andato tutto bene ho letto correttamente e creato cio che serve al while per sopravvivere e quindi ...

    if (itr->tag == Token::RP)
    {
        safe_next(itr);
        return new WhileStmt(condizione_while, blocco_while);
    }
    else
    {
        delete condizione_while;
        delete blocco_while;
        std::stringstream temp;
        temp << "Missing right parenthesis at token " << *itr;
        throw SyntaxError{temp.str()};
    }
}

/*** bool_expr -> ***/

BoolConst *Parser::parseBoolConst(std::vector<Token>::const_iterator &itr)
{

    bool variabile_booleana = (itr->word == "TRUE"); // qua non funziona cio che ho fatto in parsenumber , quindi faccio cosi

    /*AVVISO
    in qualche commit vecchio avevo messo , per ogni componente di ogni statement da creare , un trycatch per definire meglio la provenienza dell'errore .
    ma visto che non viene richiesto l'ho levato
    */
    BoolConst *var_booleana = new BoolConst{variabile_booleana};
    safe_next(itr);
    return var_booleana;
}

// i successivi 4 "inline check "mi servono per capire se ALMENO il token corrente è uno di questi elencati
// nel momento in cui sappiamo che il token è uno di questi , andremo a capire (in Syntax.cpp) di quale si tratta tramite i metodi implementati in Syntax.h nelle classi RelOp e BoolOp
inline bool isRelOperator(Token const &tok)
{
    return (tok.word == "LT") or (tok.word == "GT") or (tok.word == "EQ");
}

inline bool isBoolOperators(Token const &tok)
{
    return (tok.word == "AND") or (tok.word == "OR");
}

inline bool isNotOperator(Token const &tok) // il not l'ho messo a parte perche in questo SPECIFICO caso , se stessi leggendo il not, devo comportarmi in maniera leggermente diversa dal caso di AND o OR
{
    return (tok.word == "NOT");
}

inline bool isTrueFalse(Token const &tok)
{ // mi serve per capire se cio che sto leggendo ALMENO ricade in uno di questi due casi
    return (tok.word == "FALSE") or (tok.word == "TRUE");
}

BoolExpr *Parser::parseBoolExpr(std::vector<Token>::const_iterator &itr)
{
    /*AVVISO
    in qualche commit vecchio avevo messo , per ogni componente di ogni statement da creare , un trycatch per definire meglio la provenienza dell'errore .
    ma visto che non viene richiesto l'ho levato
    */
    // non mi serve mettere un safenext qui , altrimenti andrei avanti di uno inutilmente creando un effetto domino letale sul parsing. stesso discorso in parseNumExpr

    if (itr->tag == Token::LP) // se inizio con la "(" posso andare avanti , altrimenti già qui mi fermo
    {
        safe_next(itr); // avanzo a leggere cosa ce dopo la parentesi : adesso devo trovare per forza un operatore

        if (isRelOperator(*itr)) // in caso sia <,>,=  , la inline qua sopra ha ritornato true e posso interessarmi di che segno specifico si tratti
        {
            int opCode_rel_operator = RelOp::stringaAcodiceLTGTEQ(itr->word); // ritorno esattamente l'operatore che ho letto. gli passo la word che è una string

            safe_next(itr); // vado avanti : ora devo creare due cose

            NumExpr *primo_valore_numexpr = parseNumExpr(itr);
            NumExpr *secondo_valore_numlexpr = parseNumExpr(itr);

            if (itr->tag == Token::RP)
            { // se ce ")" ho finito , altrimenti do errore
                safe_next(itr);
                return new RelOp(opCode_rel_operator, primo_valore_numexpr, secondo_valore_numlexpr);
            }
            else
            { // se alla fine non ce ")" crolla tutta l'istruzione di valutazione bool expression
                delete primo_valore_numexpr;
                delete secondo_valore_numlexpr;
                std::stringstream temp;
                temp << "Missing right parenthesis at token " << *itr;
                throw SyntaxError{temp.str()};
            }
        }
        else if (isBoolOperators(*itr)) // se dopo "(" non c'era <,>,= allora ho ancora due casi in cui posso salvarmi
        {                               // ora ci troviamo nel caso AND o OR  ...

            int opCode_bool_operators = BoolOp::stringaAcodiceANDOR(itr->word); // chiamo il metodo che ho fatto in Syntax per capire quale operatore ho appena letto

            safe_next(itr);
            BoolExpr *primo_valore_boolexpr = parseBoolExpr(itr);
            BoolExpr *secondo_valore_boolexpr = parseBoolExpr(itr);

            if (itr->tag == Token::RP)
            {
                safe_next(itr);

                return new BoolOp(opCode_bool_operators, primo_valore_boolexpr, secondo_valore_boolexpr);
            }
            else
            { // se alla fine non ce ")" crolla tutta l'istruzione di valutazione bool expression
                delete primo_valore_boolexpr;
                delete secondo_valore_boolexpr;
                std::stringstream temp;
                temp << "Missing right parenthesis at token " << *itr;
                throw SyntaxError{temp.str()};
            }
        }
        else if (isNotOperator(*itr)) /*questo ormai è l'ultima spiaggia : il NOT .L'ho messo a parte perche devo sapere separatamente di essere qui .
                                        questo a causa del fatto che il not richiede solo un parametro nel costruttore e non 2 come in AND e OR (i suoi due colleghi)
                                      */
        {
            int opCode_bool_operator = BoolOp::stringaAcodiceNOT(itr->word); // è un po ridondante stare a controllare questo perche so benissimo che è NOT (grazie a isnotoperator)

            safe_next(itr);

            BoolExpr *primo_valore_boolexpr = parseBoolExpr(itr);

            if (itr->tag == Token::RP)
            {
                safe_next(itr);

                return new BoolOp(opCode_bool_operator, primo_valore_boolexpr); // ho creato il costruttore apposta per questo caso (in Syntax.h)
            }
            else
            { // se alla fine non ce ")" crolla tutta l'istruzione di valutazione bool expression
                delete primo_valore_boolexpr;
                std::stringstream temp;
                temp << "Missing right parenthesis at token " << *itr;
                throw SyntaxError{temp.str()};
            }
        }
        else // se invece non è stato letto neanche and , or not , <,>, = ...
        {
            std::stringstream temp;
            temp << "Unrecognized operator " << *itr;
            throw SyntaxError{temp.str()};
        }
    }
    else if (isTrueFalse(*itr)) // se invece non c'era manco "(" ...
    {
        BoolConst *variabile_booleana_boolexpr = parseBoolConst(itr);

        return variabile_booleana_boolexpr;
    }
    else
    {
        std::stringstream temp;
        temp << "Missing left parenthesis at token " << *itr;
        throw SyntaxError{temp.str()};
    }
}
/*** num_expr -> ***/

Number *Parser::parseNumber(std::vector<Token>::const_iterator &itr)
{
    /*AVVISO
    in qualche commit vecchio avevo messo , per ogni componente di ogni statement da creare , un trycatch per definire meglio la provenienza dell'errore .
    ma visto che non viene richiesto l'ho levato
    */
    std::stringstream temp;
    temp << itr->word;
    int64_t num;
    temp >> num;
    Number *c = new Number{num};
    safe_next(itr); // avanzo solo in parsenumber l'iteratore
    return c;
}

Variable *Parser::parseVariable(std::vector<Token>::const_iterator &itr)
{
    /*AVVISO
    in qualche commit vecchio avevo messo , per ogni componente di ogni statement da creare , un trycatch per definire meglio la provenienza dell'errore .
    ma visto che non viene richiesto l'ho levato
    */
    if (itr->tag != Token::KWORD)
    {
        Variable *v = new Variable{itr->word};
        safe_next(itr);
        return v;
    }
    else
    {
        std::stringstream temp;
        temp << "Expected a variable, got '" << *itr << "'";
        throw SyntaxError{temp.str()};
    }
}

inline bool Possible_Operator(Token const &tok) // stesso discorso delle righe iniziali di ParseBoolExpr
{
    return (tok.word == "ADD" or tok.word == "SUB" or tok.word == "MUL" or tok.word == "DIV");
}

NumExpr *Parser::parseNumExpr(std::vector<Token>::const_iterator &itr)
{
    /*AVVISO
    in qualche commit vecchio avevo messo , per ogni componente di ogni statement da creare , un trycatch per definire meglio la provenienza dell'errore .
    ma visto che non viene richiesto l'ho levato
    */
    if (itr->tag == Token::LP) // il PRIMO CASO è che num_expr abbia la forma : ( OPERATORE num_expr num_expr )
    {                          // intanto la num expression deve iniziare a sua volta con "("
        safe_next(itr);        // avanzo a leggere che tipo di operatore abbiamo

        if (Possible_Operator(*itr))
        { // ora so che ho appena letto o ADD o SUB o MUL o DIV per forza , non so ancora quale sia precisamente però

            int opCode_num_expr = Operator::stringaAcodiceOperatoriAritmetici(itr->word);

            safe_next(itr); // avanzo e creo due num expression ( := della cfg , a prescindere da quale sia l'operatore )

            NumExpr *valore1_NumExpr = parseNumExpr(itr);
            NumExpr *valore_2_NumExpr = parseNumExpr(itr);

            if (itr->tag == Token::RP)
            {                   // e se non ho altri operatori definiti ricorsivamente controllo che ci sia la ")" finale...
                safe_next(itr); // mando avanti la lettura e poi ritorno
                return new Operator(opCode_num_expr, valore1_NumExpr, valore_2_NumExpr);
            }
            else
            { // se dopo aver fatto un espressione aritmetica non c'era la ")" ...
                delete valore1_NumExpr;
                delete valore_2_NumExpr;
                std::stringstream temp;
                temp << "Missing right parenthesis at token " << *itr;
                throw SyntaxError{temp.str()};
            }
        }
        else // qua ci cadiamo se l'operatore non era uno di quelli che noi ci aspettavamo
        {
            std::stringstream temp;
            temp << "Stray character at token " << *itr;
            throw SyntaxError{temp.str()};
        }
    }
    else if (itr->tag == Token::ID)
    { // il SECONDO CASO è che num_expr abbia un number semplice che non richiede parentesi inziali e finali

        Variable *variabile_num_expr = parseVariable(itr);

        return variabile_num_expr; // qua non devo fare new perche ritorno gia un variable*
    }
    else if (itr->tag == Token::CONST)
    { // caso number
        // ho appena letto che è un number
        Number *numero_num_expr = parseNumber(itr);
        // vado avanti e ritorno senza problemi : dalla cfg vedo che non devo leggere ne parentesi e ne altro

        return numero_num_expr;
    }
    else
    {
        /*
        qui ricadiamo nel caso in cui
        1. num_expr non è un number
        2. num_expr non è un variable_id
        3. num_expr non ha la "(" richiesta per un operatore aritmetico

        qui proprio non posso più fare niente
        */
        std::stringstream temp;
        temp << " Cannot parse Block at token " << *itr;
        throw SyntaxError{temp.str()};
    }
}