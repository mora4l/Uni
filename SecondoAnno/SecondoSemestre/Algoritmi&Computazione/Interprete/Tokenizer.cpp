#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>

#include "Tokenizer.h"


// questo metodo mi serve per capire se il numero letto è accettabile o no
//esempio : ho letto 3
std::string Tokenizer::tokenizzaCostanti(std::ifstream &programmadafile, std::stringstream &temp)
{
    bool dotSeen = false ; 
    char ch ; 

    do{
        ch = programmadafile.get() ; //continuo a prendere quello che è "attaccato" al primo char passato
        if(std::isdigit(ch)){ //se è un numero continuo a leggerlo (33333333)
            temp << ch ; 
        }
        if(ch == '.'){ //se ho letto "." guardo : 
            if(not dotSeen){ //se ho 33333333. : ok va bene , non potra più esserci un altro punto per forza
                dotSeen = true ; 
                temp << ch ; //continuo a leggere : 33333333.123456 ecc
            }else{ //qua siamo nel caso in cui ho appena letto 33333333.. : c'è un errore
                throw LexicalError("Doppio punto decimale") ;
            }
        }
    }while(std::isdigit(ch) || ch == '.'); //finchè non abbiamo un numero oppure un punto vado avanti

    programmadafile.unget() ; //l'ultimo carattere letto è proprio quello che ha fatto interrompere il ciclo quindi lo scartiamo
    return temp.str() ; 
}

void Tokenizer::tokenizeFileInput(std::ifstream &programmadafile, std::vector<Token> &inputTokens)
{
    char ch{};                // creo un char che mi servirà per leggere dal file
    unsigned int rowCount{1}; // parto dalla riga 1 del file a leggere

    ch = programmadafile.get();

    while (!programmadafile.eof())
    {
        // ora dobbiamo lavorare su tutti i casi possibili
        if (isspace(ch))
        {
            if (ch == '\n')
            {
                rowCount += 1;
            }
        }
        else if (ch == '(')
        {
            // dentro al vector inputTokens ci metto un oggetto token che ha tag LP e valore 0 e id l'elemento corrispondente all'indice LP (0) di "idleggibile[]"
            inputTokens.emplace_back(Token::LP, Token::idleggibile[Token::LP]); //emplace_back: costruisce il Token direttamente nello slot del vector, non devo chiamare il costruttore Token
        }
        else if (ch == ')')
        {
            inputTokens.emplace_back(Token::RP, Token::idleggibile[Token::RP]);
        }
        else if (ch == '-')
        { // se c'è un meno , allora per forza dopo ci deve essere un numero . se ce qualcos altro allora c'è un errore
            // il + invece non ci puo proprio essere come definizione di numero positivo (:= dalla grammatica) e quindi non mi interessa capire la situazione col + , perchè so a priori che sarà una keyword se lo incontrerò
            
            char ch2 = programmadafile.get(); // mi prendo il carattere dopo al primo già preso
                if (std::isdigit(ch2))
                {
                    std::stringstream temp;
                    temp << ch << ch2;
                    tokenizzaCostanti(programmadafile, temp);
                    inputTokens.emplace_back(Token::CONST, temp.str());
                }else{ //se dopo il - non c'è nessun numero , allora io lo assumo come una keyword (se non è -n , ma è solo "-" , allora io di per sè lo assumo come keyword)
                    std::stringstream temp;
                    temp<<ch;
                    std::string word{temp.str()};
                    int tag = Token::KWORD;
                    inputTokens.emplace_back(tag,word);
                    programmadafile.unget(); //mi serve per "far ripartire da zero" la stringa temp
                }
            
        }
        else if (std::isdigit(ch))
        { // se è un numero devo andare a vedere che tipo di numero è (grazie a tokenizzacostanti) e poi lo salvo come costante
            // non legge in forma esponenziale!!!
            std::stringstream temp; // metto dentro ad uno stream di stringa il carattere che ho appena letto
            temp << ch;
            tokenizzaCostanti(programmadafile, temp); // così lo passo alla funzione di check della correttezza del numero
            inputTokens.emplace_back(Token::CONST, temp.str());
        }
        else if (std::isalpha(ch) or ch == '_')
        {                           // qua devo capire se ho davanti una parola chiave (KWRD) o una variabile (ID) ("if" , "while", "set" oppure "var" , "variabile" , "temp")
            std::stringstream temp; // metto dentro ad uno stream di stringa il carattere che ho appena letto
            temp << ch;

            do
            { // mi leggo tutto ciò che è attaccato al primo carattere
                ch = programmadafile.get();

                if (std::isalpha(ch) or std::isdigit(ch) or ch == '_')
                {
                    temp << ch;
                }
            } while (std::isalpha(ch) or std::isdigit(ch) or ch == '_');

            std::string word{temp.str()};

            int tag = Token::ID; // di base quello che ho appena letto potrebbe essere una variabile e intanto preparo l'id associato

            // poi , se per caso quello che ho appena letto è proprio una parola chiave trovata dentro all'array che le definisce , allora cambio tag definendolo come parola chiave
            if (Token::parole_chiave.find(word) != Token::parole_chiave.end())
            {
                tag = Token::KWORD;
            }
            inputTokens.emplace_back(tag, word);

            programmadafile.unget(); // torno indietro al char iniziale che ho letto , levandomi tutti i char "attaccati" all ID o alla parola chiave che ho appena analizzato
        }
        else
        {
            std::stringstream temp;
            temp << "Carattere non valido : " << ch
                 << " in input alla linea " << rowCount;
            throw LexicalError{temp.str()};
        }
        ch = programmadafile.get();
    }
}