#include <iostream>

#include "Token.h"

std::unordered_set<std::string> Token::keywords = { "int", "float", "return" };

std::ostream& operator<<(std::ostream& os, const Token& t) {
	os << "(" << Token::tag2string[t.tag] << ",\"" << t.word << "\")";
	return os;
};
