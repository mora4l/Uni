#if !defined(ECCEZIONI_H)
#define ECCEZIONI_H
#include <stdexcept>

//abbiamo 3 macro categorie di errori : 

//errori derivanti dalla fase di tokenizzazione (analisi lessicale)
struct LexicalError : std::runtime_error{
    LexicalError(const char *msg) : std::runtime_error(msg) {}
    LexicalError(std::string msg) : std::runtime_error(msg.c_str()) {}
};

//errori derivanti dalla fase di parsing (analisi sintattica)
struct SyntaxError : std::runtime_error{
SyntaxError(const char* msg) : std::runtime_error (msg){};
SyntaxError(std::string msg) : std::runtime_error (msg.c_str()){};

};

//errori derivanti dalla fase di valutazione dell'AST (analisi semantica)
struct EvaluationError : std::runtime_error{
    EvaluationError(const char* msg) : std::runtime_error (msg){};
    EvaluationError(std::string msg) : std::runtime_error (msg.c_str()){};
};

struct EmptyProgram : std::runtime_error{
    EmptyProgram(const char* msg) : std::runtime_error (msg){};
    EmptyProgram(std::string msg) : std::runtime_error (msg.c_str()){};
};

#endif