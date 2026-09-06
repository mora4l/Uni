#include <sstream>
#include "Parser.h"

/*** program -> ***/
Program *Parser::parseProgram(std::vector<Token>::const_iterator &itr)
{
    Block *programma_parsabile = parseStmtBlock(itr);
    return new Program{programma_parsabile};
}
Block *Parser::parseStmtBlock(std::vector<Token>::const_iterator &itr)
{
    /*
    stmt block → statement | ( BLOCK statement list )

    1a cosa da sapere : il codice in input è uno statement solo oppure è una lista di statement ?
    */
    if (itr->tag == Token::LP)
    {                   // intanto sicuramente il codice deve contenere "(" per iniziare
        safe_next(itr); // leggo il carattere dopo...
        if (itr->tag == Token::KWORD && itr->word == "BLOCK")
        { // qua ci sono due casi : se ce scritto BLOCK allora ci sarà un block da leggere
            return parseBlock(itr);
        }
        else if (itr->tag == Token::KWORD)
        { // se invece non ce scritto block ,ma un altra keyword , allora potrebbe essere uno statement (potrebbe, perche devo ancora capire di che altra keyword si tratta)

            // se è uno statement , ho già letto una "(" che FARA GIA PARTE DELLO STATEMENT , quindi dovro controllare a fine parseStatement (che devo ancora fare) se ce la ")" finale

            std::vector<Statement *> temp;       // il problema è che se faccio return parseStatement mi ritorna un Statement* , cosa che non posso perche questa funzione ritorna un Block*, quindi devo creare un vettore ausiliario uguale al tipo supportato da Block
            temp.push_back(parseStatement(itr)); // ci metto dentro l'unico elemento analizzato (uno statement solo , che vado a leggere)
            return new Block(std::move(temp));   // e poi ritorno un nuovo Block creato con un vettore che ha un solo elemento (un solo statement)
        }
        else
        { // se non era né un BLOCK e tantomeno una keyword generica , allora ce un problema di fondo di sintassi
            std::stringstream temp;
            temp << "Unexpected token: " << *itr << std::endl
                 << "Expected 'BLOCK' or a single statement";
            throw SyntaxError{temp.str()};
        }
    }
    else
    { // ancora peggio se il codice non iniziava manco con una "("
        std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected left parenthesis to start a new BLOCK or a new STATEMENT";
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
    while (itr->tag != Token::RP) // finchè non incontro la ")" del BLOCK da cui ho chiamato questa funzione , dentro ci saranno statement da leggere
    {

        if (itr->tag == Token::LP)
        { // dopo BLOCK PER FORZA ci deve essere uno statement , quindi PER FORZA DEVE ESSERCI "(". la ")" la leggero in ParseStatement , come facevo in parseSetStmtBlock
            safe_next(itr);
            another_statement.push_back(parseStatement(itr));
        }
        else
        {
            std::stringstream temp;
            temp << "Unexpected token: " << *itr << std::endl
                 << "Expected at least one statement after BLOCK declaration with opening parenthesis '(' ";
            throw SyntaxError{temp.str()};
        }
    }
    if (another_statement.empty())
    { // se il vettore è vuoto vuol dire che dopo BLOCK non c'era una "(" e che quindi non è stato in grado nemmeno di costruire uno statement
        std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected at least one statement after BLOCK declaration";
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

    if (itr->tag == Token::KWORD)
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
        else
        {
            std::stringstream temp;
            temp << "Unexpected token: " << *itr << std::endl
                 << "Expected one of the acceptable statement";
            throw SyntaxError{temp.str()};
        }
    }
    else
    {
        std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected a statement token";
        throw SyntaxError{temp.str()};
    }
}

/*** variable_def -> ***/

SetStmt *Parser::parseSetStmt(std::vector<Token>::const_iterator &itr)
{
    safe_next(itr); // dopo aver letto SET avanzo

    Variable *variabile_set = parseVariable(itr);
    NumExpr *valore_set = parseNumExpr(itr);

    if (itr->tag == Token::RP)
    {
        safe_next(itr);
        return new SetStmt(variabile_set, valore_set);
    }
    else
    {
        //!!!!sarebbe da eliminare i blocchi creati prima di capire che era tutto sbagliato !!!!
        // delete variabile_set; io lo lascio qui scritto , poi è da controllare
        // delete valore_set;
        std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected closing parenthesis for SET statement";
        throw SyntaxError{temp.str()};
    }
}

/*** io_stmt -> ***/

InputStmt *Parser::parseInputStmt(std::vector<Token>::const_iterator &itr)
{
    safe_next(itr); // dopo aver letto INPUT avanzo
    

    Variable *variabile_input = parseVariable(itr);

    if (itr->tag == Token::RP)
    {
        safe_next(itr);
        return new InputStmt(variabile_input);
    }
    else
    {
        //!!!!sarebbe da eliminare i blocchi creati prima di capire che era tutto sbagliato !!!!
        // delete variabile_input
        std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected closing parenthesis for INPUT statement";
        throw SyntaxError{temp.str()};
    }
}

PrintStmt *Parser::parsePrintStmt(std::vector<Token>::const_iterator &itr)
{
    safe_next(itr); // dopo aver letto PRINT avanzo

    NumExpr *num_expr_print = parseNumExpr(itr);

    if (itr->tag == Token::RP)
    {
        safe_next(itr);
        return new PrintStmt(num_expr_print);
    }
    else
    {
        //!!!!sarebbe da eliminare i blocchi creati prima di capire che era tutto sbagliato !!!!
        // delete num_expr_print
        std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected closing parenthesis for PRINT statement";
        throw SyntaxError{temp.str()};
    }
}

/*** cond_stmt -> ***/

IfStmt *Parser::parseIfStmt(std::vector<Token>::const_iterator &itr)
{

    

        safe_next(itr); // dopo aver letto il tipo di statement vado avanti...
    
        // ci sono 3 cose che devo creare :
        BoolExpr *condizione_if = parseBoolExpr(itr);
        Block *blocco_else = nullptr;
        Block *blocco_then = parseStmtBlock(itr);
        try{

            blocco_else = parseStmtBlock(itr);
        }catch(SyntaxError& e){
            std::stringstream temp;
            temp << "Error in ELSE statement"<<std::endl<<"("<<e.what()<<")";
            throw SyntaxError{temp.str()};
        }
        // e se è andato tutto bene , sono arrivato qui che ho tutte le espressioni dell'IfStmt lette FINO ALLA ")" GIA LETTA
        if (itr->tag == Token::RP)
        {
            safe_next(itr); // mi porto avanti col prossimo token da leggere
            return new IfStmt(condizione_if, blocco_then, blocco_else);
        }
        else
        {
            // delete condizione_if;
            // delete blocco_else;
            // delete blocco_then;
            std::stringstream temp;
            temp << "Unexpected token: " << *itr << std::endl
                 << "Expected closing parenthesis for IF statement";
            throw SyntaxError{temp.str()};
        }

}

/*** loop_stmt -> ***/

WhileStmt *Parser::parseWhileStmt(std::vector<Token>::const_iterator &itr)
{
    safe_next(itr); // dopo aver letto WHILE avanzo

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
        //!!!!sarebbe da eliminare i blocchi creati prima di capire che era tutto sbagliato !!!!
        // delete condizione_while;
        // delete blocco_while;
        std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected closing parenthesis for WHILE statement";
        throw SyntaxError{temp.str()};
    }
}

/*** bool_expr -> ***/

BoolConst *Parser::parseBoolConst(std::vector<Token>::const_iterator &itr)
{

    bool variabile_booleana = (itr->word == "TRUE"); // qua non funziona cio che ho fatto in parsenumber , quindi faccio cosi

    BoolConst *var_booleana = new BoolConst{variabile_booleana};
    safe_next(itr);
    return var_booleana;
}
// questi inline check mi servono per capire se ALMENO il token corrente è uno di questi elencati
// nel momento in cui sappiamo che il token è uno di questi , andremo a capire di quale si tratta tramite i metodi implementati in Syntax.h nelle classi RelOp e BoolOp
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
    // non mi serve mettere un safenext qui , altrimenti andrei avanti di uno inutilmente e creando un effetto domino letale sul parsing. stesso discorso in parseNumExpr
    if (itr->tag == Token::LP) // se inizio con la "(" posso andare avanti , altrimenti già qui mi fermo
    {
        safe_next(itr); // avanzo a leggere cosa ce dopo la parentesi : adesso devo trovare per forza un operatore

        if (isRelOperator(*itr)) // in caso sia <,>,=  , inline ha ritornato true e posso interessarmi di che segno si tratta
        {
            int opCode_rel_operator = RelOp::stringaAcodiceLTGTEQ(itr->word); // ritorno esattamente l'operatore che ho letto. gli passo la word che è una string
            safe_next(itr);                                                   // vado avanti : ora devo creare due cose
            NumExpr *primo_valore_numexpr = parseNumExpr(itr);
            NumExpr *secondo_valore_numlexpr = parseNumExpr(itr);
            if (itr->tag == Token::RP)
            { // se ce ")" ho finito , altrimenti do errore
                safe_next(itr);
                return new RelOp(opCode_rel_operator, primo_valore_numexpr, secondo_valore_numlexpr);
            }
            else
            { // se alla fine non ce ")" crolla tutta l'istruzione di valutazione bool expression
                // delete primo_valore_numexpr;
                // delete secondo_valore_numlexpr;
                std::stringstream temp;
                temp << "Unexpected token: " << *itr << std::endl
                     << "Expected closing parenthesis for bool expression statement";
                throw SyntaxError{temp.str()};
            }
        }
        else if (isBoolOperators(*itr))                                         // se dopo "(" non c'era <,>,= allora ho ancora due casi in cui posso salvarmi
        {                                                                       // in caso sia AND o OR  ...
            int opCode_bool_operators = BoolOp::stringaAcodiceANDOR(itr->word); // chiamo il metodo che ho fatto in Syntax per capire che operatore ho appena letto

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
                // delete primo_valore_boolexpr;
                // delete secondo_valore_boolexpr;
                std::stringstream temp;
                temp << "Unexpected token: " << *itr << std::endl
                     << "Expected closing parenthesis for bool expression statement";
                throw SyntaxError{temp.str()};
            }
        }
        else if (isNotOperator(*itr)) /*questo ormai è l'ultima spiaggia : il NOT .L'ho messo a parte perche devo sapere separatamente di essere qui .
questo a causa del fatto che il not richiede solo un parametro nel costruttore e non 2 come in AND e OR (i suoi due colleghi)
 */
        {
            int opCode_bool_operator = BoolOp::stringaAcodiceNOT(itr->word); // è un po inutile stare a controllare questo perche so benissimo che è NOT (grazie a isnotoperator)

            safe_next(itr);

            BoolExpr *primo_valore_boolexpr = parseBoolExpr(itr);

            if (itr->tag == Token::RP)
            {
                safe_next(itr);

                return new BoolOp(opCode_bool_operator, primo_valore_boolexpr); // ho creato il costruttore apposta per questo caso (riga 79 Syntax.h)
            }
            else
            { // se alla fine non ce ")" crolla tutta l'istruzione di valutazione bool expression
                // delete primo_valore_boolexpr;
                std::stringstream temp;
                temp << "Unexpected token: " << *itr << std::endl
                     << "Expected closing parenthesis for bool expression statement";
                throw SyntaxError{temp.str()};
            }
        }
        else // se invece non è stato letto neanche and , or not , <,>, = ...
        {
            std::stringstream temp;
            temp << "Unexpected token: " << *itr << std::endl
                 << "Expected at least one feasible operator (boolean operator or comparison operator)";
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
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected opening parenthesis for bool expression or TRUE / FALSE boolean variable";
        throw SyntaxError{temp.str()};
    }
}
/*** num_expr -> ***/

Number *Parser::parseNumber(std::vector<Token>::const_iterator &itr)
{
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
    if (itr->tag != Token::KWORD)
    {
        Variable *v = new Variable{itr->word};
        safe_next(itr);
        return v;
    }
    else
    {
        std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Is not allowed to use a keyword as a variable name";
        throw SyntaxError{temp.str()};
    }
}

inline bool Possible_Operator(Token const &tok) // stesso discorso delle righe iniziali di ParseBoolExpr
{
    return (tok.word == "ADD" or tok.word == "SUB" or tok.word == "MUL" or tok.word == "DIV");
}

NumExpr *Parser::parseNumExpr(std::vector<Token>::const_iterator &itr)
{

    if (itr->tag == Token::LP) // il PRIMO CASO è che num_expr abbia ( OPERATORE num_expr num_expr )
    {                          // intanto la num expression deve iniziare a sua volta con "("
        safe_next(itr);        // avanzo a leggere che tipo di operatore abbiamo

        if (Possible_Operator(*itr))
        { // ora so che ho appena letto o ADD o SUB o MUL o DIV per forza , non so ancora quale sia precisamente pero
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
                // delete valore1_NumExpr;
                // delete valore_2_NumExpr;
                std::stringstream temp;
                temp << "Unexpected token: " << *itr << std::endl
                     << "Expected closing parenthesis for num expression";
                throw SyntaxError{temp.str()};
            }
        }
        else
        {
            std::stringstream temp;
            temp << "Unexpected token: " << *itr << std::endl
                 << "Expected a valid aritmethic operator after '(' ";
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
        */
        std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected a number or a variable or an aritmethic operator";
        throw SyntaxError{temp.str()};
    }
}