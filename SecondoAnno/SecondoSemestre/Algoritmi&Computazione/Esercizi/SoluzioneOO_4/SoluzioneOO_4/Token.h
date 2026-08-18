#if !defined(TOKEN_H)
#define TOKEN_H

#include <string>
#include <unordered_set>

struct Token {

	// Tags: integer codes associated to each token
	static constexpr int LB = 0; // Left bracket {
	static constexpr int RB = 1; // Right bracket }
	static constexpr int LP = 2; // Left parenthesis (
	static constexpr int RP = 3; // Right parenthesis )
	static constexpr int CO = 4; // Comma ,
	static constexpr int SC = 5; // Semicolon ;
	static constexpr int EQ = 6; // Equal
	static constexpr int ADD = 7;
	static constexpr int SUB = 8;
	static constexpr int MUL = 9;
	static constexpr int DIV = 10;
	static constexpr int KWORD = 11;
	static constexpr int ID = 12;
	static constexpr int CONST = 13;

	// Mapping tags to human readable strings
	static constexpr const char* id2word[]{
		"{", "}", "(", ")", ",", ";",
		"=", "+", "-", "*", "/",
		"KWORD", "ID", "CONST"
	};
	
	// Mapping tags to corresponding string names
	static constexpr const char* tag2string[]{
		"LB", "RB", "LP", "RP", "CO", "SC",
		"EQ", "OP", "OP", "OP", "OP",
		"KWORD", "ID", "CONST"
	};

	// Recognized keywords
	static std::unordered_set<std::string> keywords;

	Token(int t, const char* w) : tag{ t }, word{ w } {}
	Token(int t, std::string w) : tag{ t }, word{ w } {}
	~Token() = default;
	Token(Token const&) = default;
	Token& operator=(Token const&) = default;

	int tag;
	std::string word;
};

// Overloading the output stream operator for tokens
std::ostream& operator<<(std::ostream & os, const Token & t);


#endif
