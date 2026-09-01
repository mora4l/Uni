#if !defined(TOKEN_H)
#define TOKEN_H

#include <string>

struct Token {

	// Tags: integer codes associated to each token
	static constexpr int LP    =  0; // Left parenthesis
	static constexpr int RP    =  1; // Right parenthesis
	static constexpr int EQ    =  2; // Equal
	static constexpr int ADD   =  3; // Add
	static constexpr int SUB   =  4; // Subtract
	static constexpr int MUL   =  5; // Multiply
	static constexpr int DIV   =  6; // Divide
	static constexpr int ID    =  7; // Variable identifier
	static constexpr int CONST = 13; // Numeric constant

	// Mapping tags to human readable strings
	static constexpr const char* id2word[]{
		"(", ")", "=", "+", "-", "*", "/", "ID", "CONST"
	};

	// Mapping tags to corresponding string names
	static constexpr const char* tag2string[]{
		"LP", "RP", "EQ", "OP", "OP", "OP", "OP", "ID", "CONST"
	};

	Token(int t, const char* w) : tag{ t }, word{ w } {}
	Token(int t, std::string w) : tag{ t }, word{ w } {}
	~Token() = default;
	Token(Token const&) = default;
	Token& operator=(Token const&) = default;

	int tag;
	std::string word;
};

// Overloading the output stream operator for tokens
std::ostream& operator<<(std::ostream& os, const Token& t);


#endif

