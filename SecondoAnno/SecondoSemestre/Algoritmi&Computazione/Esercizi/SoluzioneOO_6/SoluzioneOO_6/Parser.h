#if !defined(PARSER_H)
#define PARSER_H

#include <vector>

#include "Token.h"
#include "Syntax.h"
#include "Exception.h"

class Parser {

public:
	//TODO: Implement constructors, destructors, etc.

	Program* operator()(std::vector<Token> const& tokenStream) { //lavora con un function object che passa il vettore di token
		auto itr = tokenStream.begin(); //impostiamo l'indice iniziale del vettore
		end_ = tokenStream.end(); //e l'indice finale


		
		Program* p = parseProgram(itr); //creo un oggetto programma e poi ci applico il parsing
		if (p->statements.size() == 0) {
			throw SyntaxError{ "Empty program!" };
		}
		return p;
	}

private:
	std::vector<Token>::const_iterator end_;

	// Invariant: all parsing functions take the itr at the beginning
	// of the symbol parsed and leave itr after the end of the symbol
	Program* parseProgram(std::vector<Token>::const_iterator& itr);
	Statement* parseStatement(std::vector<Token>::const_iterator& itr);
	Definition* parseDefinition(std::vector<Token>::const_iterator& itr);
	Expression* parseExpression(std::vector<Token>::const_iterator& itr);
	Variable* parseVariable(std::vector<Token>::const_iterator& itr);
	Constant* parseConstant(std::vector<Token>::const_iterator& itr);

	void safe_next(std::vector<Token>::const_iterator& itr) {
		if (itr != end_) {
			++itr;
		} else {
			throw SyntaxError{ "Premature end of input!" };
		}
	}

};


#endif