#include "Token.h"
#include <iostream>
// definisco i due metodi ulteriori che ho definito nel .h
std::unordered_set<std::string> Token::parole_chiave = {"BLOCK", "INPUT", "SET", "WHILE", "IF", "GT", "LT", "EQ", "AND", "OR", "NOT", "TRUE", "FALSE", "ADD", "SUB", "MUL", "DIV", "PRINT"};

std::ostream &operator<<(std::ostream &os, const Token &t)
{
	os << "'" << Token::tag2string[t.tag] << ",\"" << t.word << "\"'";
	return os;
};
