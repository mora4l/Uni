#if !defined(TOKENIZER_H)
#define TOKENIZER_H
#include <vector>
#include <fstream>

#include "Token.h"
#include "Eccezioni.h"

class Tokenizer
{
public:
    /*
    adesso mi dichiaro i 4 fondamenti della classe : il costruttore default che imposto come default , il distruttore default ,
    il costruttore di copia che se chiamo elimino subito dopo e l'operatore di assegnamento che elimino anche lui subito dopo la chiamata
    */
    Tokenizer() = default;
    ~Tokenizer() = default;
    Tokenizer(Tokenizer const &) = delete;
    Tokenizer &operator=(Tokenizer const &) = delete;

    // creo un function object , ovvero un oggetto trattato come una funzione in quanto viene richiamato altrove ma con se porta delle variabili o altro
    std::vector<Token> operator()(std::ifstream &programmadafile)
    {
        std::vector<Token> inputTokens;                  // creo il vettore in cui ci saranno tutti i token in fila
        tokenizeFileInput(programmadafile, inputTokens); // chiamo il metodo che legge i token e li inserisce
        return inputTokens;                              // ritorno il vettore di token
    }

private:
    std::string tokenizzaCostanti(std::ifstream &programmadafile, std::stringstream &temp);
    void tokenizeFileInput(std::ifstream &inputFile, std::vector<Token> &inputTokens);
};
#endif