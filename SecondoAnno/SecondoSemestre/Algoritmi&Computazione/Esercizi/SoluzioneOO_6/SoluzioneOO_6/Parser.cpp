#include <sstream>

#include "Parser.h"

Program* Parser::parseProgram(std::vector<Token>::const_iterator& itr) {
	Program* p = new Program{};
	while (itr != end_) {
		Statement* s = parseStatement(itr);
		p->statements.push_back(s);
	}
	return p;
}

Statement* Parser::parseStatement(std::vector<Token>::const_iterator& itr) {
	// Three cases: Definition, Expresssion, Error
	if (itr->tag == Token::ID) {
		return parseDefinition(itr);
	} else if (itr->tag == Token::LP) {
		return parseExpression(itr);
	} else {
		std::stringstream temp;
		temp << "Unexpected token: " << *itr << std::endl
			<< "Expected definition or expression.";
		throw SyntaxError{ temp.str() };
	}
}

Definition* Parser::parseDefinition(std::vector<Token>::const_iterator& itr) {
	Variable* v = parseVariable(itr);
	if (itr->tag != Token::EQ) {
		std::stringstream temp;
		temp << "Unexpected token: " << *itr << std::endl
			<< "Expected '=' instead.";
		throw SyntaxError{ temp.str() };
	}
	safe_next(itr);
	Expression* e = parseExpression(itr);
	return new Definition{ v, e };
}

inline bool isOperator(Token const& tok) {
	return (tok.tag == Token::ADD) or
		(tok.tag == Token::SUB) or
		(tok.tag == Token::MUL) or
		(tok.tag == Token::DIV);
}

Expression* Parser::parseExpression(std::vector<Token>::const_iterator& itr) {
	// Four cases: compound expression, variable, constant, error
	if (itr->tag == Token::LP) {
		// Compound expression
		// Discard LP token
		safe_next(itr);
		// Parse left operand
		Expression* left = parseExpression(itr);
		if (not isOperator(*itr)) {
			// If this is not an operator, then error
			std::stringstream temp;
			temp << "Unexpected token: " << *itr << std::endl
				<< "Expected operator (+, -, *, /) instead.";
			throw SyntaxError{ temp.str() };
		}
		int opCode = itr->tag;
		// Advance to next operand
		safe_next(itr);
		// Parse right operand
		Expression* right = parseExpression(itr);
		if (itr->tag != Token::RP) {
			// If this is not a closed parenthesis, then error
			std::stringstream temp;
			temp << "Unexpected token: " << *itr << std::endl
				<< "Expected ')' instead.";
			throw SyntaxError{ temp.str() };
		}
		// Discard right parenthesis
		safe_next(itr);
		return new Operator{ opCode, left, right };
	} else if (itr->tag == Token::ID) {
		// Variable
		return parseVariable(itr);
	} else if (itr->tag == Token::CONST) {
		// Constant
		return parseConstant(itr);
	} else {
		std::stringstream temp;
		temp << "Unexpected token: " << *itr << std::endl
			<< "Expected ID, CONST or LP instead.";
		throw SyntaxError{ temp.str() };
	}
}

Variable* Parser::parseVariable(std::vector<Token>::const_iterator& itr) {
	Variable* v = new Variable{ itr->word };
	// Advance iterator to next token
	safe_next(itr);
	return v;
}

Constant* Parser::parseConstant(std::vector<Token>::const_iterator& itr) {
	// Using a string stream to convert from string to integer
	std::stringstream temp;
	temp << itr->word;
	int num;
	temp >> num;
	Constant* c = new Constant{ num };
	// Advance iterator to next token
	safe_next(itr);
	return c;
}
	

