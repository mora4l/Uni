#if !defined(EXCEPTIONS_H)
#define EXCEPTIONS_H
struct LexicalError : std::runtime_error {
	LexicalError(const char* msg) : std::runtime_error(msg) {}
	LexicalError(std::string msg) : std::runtime_error(msg.c_str()) {}
};
#endif
