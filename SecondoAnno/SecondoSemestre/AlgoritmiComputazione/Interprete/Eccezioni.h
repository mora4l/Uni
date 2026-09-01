#if !defined(ECCEZIONI_H)
#define ECCEZIONI_H
#include <stdexcept>

struct LexicalError : std::runtime_error{
    LexicalError(const char *msg) : std::runtime_error(msg) {}
    LexicalError(std::string msg) : std::runtime_error(msg.c_str()) {}
};
struct SyntaxError : std::runtime_error{
SyntaxError(const char* msg) : std::runtime_error (msg){};
SyntaxError(std::string msg) : std::runtime_error (msg.c_str()){};

};

struct EmptyVector : std::runtime_error{
    EmptyVector(const char* msg) : std::runtime_error (msg){};
    EmptyVector(std::string msg) : std::runtime_error (msg.c_str()){};
};

struct EvaluationError : std::runtime_error{
    EvaluationError(const char* msg) : std::runtime_error (msg){};
    EvaluationError(std::string msg) : std::runtime_error (msg.c_str()){};
};
#endif