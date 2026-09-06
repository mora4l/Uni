#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <iostream>
#include "Tokenizer.h"

// questo metodo mi serve per capire se il numero letto è accettabile o no
// esempio : ho letto 3
std::string Tokenizer::tokenizzaCostanti(std::ifstream &programmadafile, std::stringstream &temp)
{
    char ch;
    do
    {
        ch = programmadafile.get(); // continuo a prendere quello che è "attaccato" al primo char passato

        if (std::isdigit(ch))
        { // se è un numero continuo a leggerlo (33333333)
            temp << ch;
        }
        if (ch == '.')
        {
            std::stringstream temp;
            temp << "Only integer value allowed in file.txt";
            throw LexicalError(temp.str());
        } // se ho letto "." guardo :

    } while (std::isdigit(ch) || ch == '.'); // finchè non abbiamo un numero oppure un punto vado avanti

    programmadafile.unget(); // l'ultimo carattere letto è proprio quello che ha fatto interrompere il ciclo quindi lo scartiamo
    return temp.str();
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
            inputTokens.emplace_back(Token::LP, Token::idleggibile[Token::LP]); // emplace_back: costruisce il Token direttamente nello slot del vector, non devo chiamare il costruttore Token
        }
        else if (ch == ')')
        {
            inputTokens.emplace_back(Token::RP, Token::idleggibile[Token::RP]);
        }
        else if (ch == '-')
        { // se c'è un meno , allora per forza dopo ci deve essere un numero . se ce qualcos altro allora c'è un errore
            // il + invece non ci puo proprio essere come definizione di numero positivo (:= dalla grammatica) e quindi non mi interessa capire la situazione col + , perchè so a priori che sarà una keyword se lo incontrerò

            char ch2 = programmadafile.get(); // mi prendo il carattere dopo al primo già preso
            if(ch2 == '0'){ 

                char ch3 = programmadafile.get(); //devo verificare subito una cosa : 

                if(std::isdigit(ch3)){ //se c'è qualsiasi numero dopo lo 0 ancora attaccato c'è un errore
                                    std::stringstream temp;
                temp << "You cant write a number followed by any number after a zero " << ch
                     << " Error in file.txt at line " << rowCount;
                throw LexicalError{temp.str()};
                }else{
                    programmadafile.unget(); //se non era un numero cio che c'era dopo lo 0 , allora rimetto tutto nello stream
                    std::stringstream temp ; 
                    temp<<ch<<ch2; 
                    inputTokens.emplace_back(Token::CONST,temp.str()); //e salvo come -0 quella costante
                }
            }else if (std::isdigit(ch2)) //se non è uno zero (perche se siamo arrivati qui per forza zero non è per esclusione dei casi)
            {//allora posso andare avanti senza problemi
                std::stringstream temp;
                temp << ch << ch2;
                tokenizzaCostanti(programmadafile, temp);
                inputTokens.emplace_back(Token::CONST, temp.str());
            }
            else // se dopo "-" non ce altro allora ce un problema, non è accettato "-" e basta
            {
                std::stringstream temp;
                temp << "Not valid single character: " << ch
                     << " Error in file.txt at line " << rowCount;
                throw LexicalError{temp.str()};
            }
        }
        else if (std::isdigit(ch)) 
        { // se è un numero devo andare a vedere che tipo di numero è (grazie a tokenizzacostanti) e poi lo salvo come costante

            std::stringstream temp; // metto dentro ad uno stream di stringa il carattere che ho appena letto
            temp << ch;

            if (ch == '0')
            { // se ho letto 0 allora devo capire se dopo c'è un altro numero : in tal caso è un errore
                char ch2 = programmadafile.get();

                if (isdigit(ch2)) //se ch2 è un numero allora c'è un errore
                { //qui entra se il numero è 0n0
                    std::stringstream temp;
                    temp << "Zero value followed by another value is not allowed " << ch
                         << " Error in file.txt at line " << rowCount;
                    throw LexicalError{temp.str()};
                }else{

                    //altrimenti qui siamo nel caso 0nABC...
                    programmadafile.unget(); // se non era un numero allora lo rimetto nello stream e procedo a salvare 0 come CONST
                    inputTokens.emplace_back(Token::CONST,temp.str()); // e salvo semplicemente ch che era '0'
                }
            }else{//qui invece siamo nel caso in cui abbiamo n che non è zero inizialmente e quindi non ci sono restrizioni strane
                tokenizzaCostanti(programmadafile, temp); // così lo passo alla funzione di check della correttezza del numero
                inputTokens.emplace_back(Token::CONST, temp.str());

            }
        }else if (std::isalpha(ch))
            {                           // qua devo capire se ho davanti una parola chiave (KWRD) o una variabile (ID) ("if" , "while", "set" oppure "var" , "variabile" , "temp")
                std::stringstream temp; // metto dentro ad uno stream di stringa il carattere che ho appena letto
                temp << ch;

                do
                { // mi leggo tutto ciò che è attaccato al primo carattere
                    ch = programmadafile.get();

                    if (std::isalpha(ch))
                    {
                        temp << ch;
                    }
                } while (std::isalpha(ch));

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
                temp << "Bad news from tokenizer !! Carattere non valido : " << ch
                     << " Error in file.txt at line " << rowCount;
                throw LexicalError{temp.str()};
            }
            ch = programmadafile.get();
        }
    }