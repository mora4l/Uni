#if !defined(SYMBOL_TABLE_H)
#define SYMBOL_TABLE_H

#include <string>
#include <sstream>
#include <unordered_map>

#include "Eccezioni.h"

class SymbolTable
{
public:
    SymbolTable() = default;
    ~SymbolTable() = default;

    SymbolTable(const SymbolTable &other) = delete;
    SymbolTable &operator=(const SymbolTable &other) = delete;

    int64_t getValue(std::string const &key) const
    {
        auto itr = map.find(key); //in questo modo sto andando a trovare con find la casella della mappa in cui ho quel valore associato a quella variabile. find mi restituisce un iteratore , non un valore

        if (itr == map.end()) //map.end è lo stesso concetto del nullptr
        {
            std::stringstream temp;
            temp << "Not declared variable : " << key;
            throw EvaluationError{temp.str()};
        }
        return (*map.find(key)).second;
    }

    void setValue(std::string const &key, int64_t value)
    {
        map[key] = value;
    }

private:
    std::unordered_map<std::string, int64_t> map; //i valori interi sono , da specifica, a 64 bit quindi devo usare il tipo "int64_t"
};
#endif