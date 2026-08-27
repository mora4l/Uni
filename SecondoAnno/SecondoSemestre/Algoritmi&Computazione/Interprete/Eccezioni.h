#if !defined(ECCEZIONI_H)
#define ECCEZIONI_H

struct LexicalError : std::runtime_error{
    LexicalError(const char *msg) : std::runtime_error(msg) {}
    LexicalError(std::string msg) : std::runtime_error(msg.c_str()) {}
};
struct SyntaxError : std::runtime_error{
SyntaxError(const char* msg) : std::runtime_error (msg){};
SyntaxError(std::string msg) : std::runtime_error (msg.c_str()){};

};

struct NotEmptyVector : std::runtime_error{
    NotEmptyVector(const char* msg) : std::runtime_error (msg){};
    NotEmptyVector(std::string msg) : std::runtime_error (msg.c_str()){};
};
#endif