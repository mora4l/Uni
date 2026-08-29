#include <sstream>
#include "Parser.h"

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
                 << "Expected block or statement";
            throw SyntaxError{temp.str()};
        }
    }
    else
    { // ancora peggio se il codice non iniziava manco con una "("
        std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected block or statement";
        throw SyntaxError{temp.str()};
    }
}

Block *Parser::parseBlock(std::vector<Token>::const_iterator &itr)
{
    // arrivati qui ho letto "BLOCK"
    safe_next(itr); // avanzo e...

    // statement list → statement statement list | statement
    // ( BLOCK (SET x x )  )
    std::vector<Statement *> another_statement;
    while (itr->tag != Token::RP)
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
                 << "Expected block or statement";
            throw SyntaxError{temp.str()};
        }
    }
    if (another_statement.empty())
    { // se il vettore è vuoto vuol dire che dopo BLOCK non c'era una "(" e che quindi non è stato in grado nemmeno di costruire uno statement
        std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected block or statement";
        throw SyntaxError{temp.str()};
    }
    else
    {                   // altrimenti il vettore è pieno di roba e ritorno
        safe_next(itr); // consumo la ")" finale che mi ha fatto uscire dal ciclo
        return new Block(std::move(another_statement));
    }
}

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
                 << "Expected block or statement";
            throw SyntaxError{temp.str()};
        }
    }
    else
    {
        std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected block or statement";
        throw SyntaxError{temp.str()};
    }
}

IfStmt* Parser::parseIfStmt(std::vector<Token>::const_iterator &itr){

    safe_next(itr); //dopo aver letto il tipo di statement vado avanti...

    //ci sono 3 cose che devo creare : 
        BoolExpr* condizione = parseBoolExpr(itr);
        Block* blocco_then = parseStmtBlock(itr);
        Block* blocco_else = parseStmtBlock(itr);
// e se è andato tutto bene , sono arrivato qui che ho tutte le espressioni dell'IfStmt lette FINO ALLA ")" GIA LETTA
        if(itr->tag == Token::RP){
            safe_next(itr);
            return new IfStmt(condizione, blocco_then, blocco_else); 
        }else{
                    std::stringstream temp;
        temp << "Unexpected token: " << *itr << std::endl
             << "Expected closing parenthesis for IF statement";
        throw SyntaxError{temp.str()};
        }
    
}