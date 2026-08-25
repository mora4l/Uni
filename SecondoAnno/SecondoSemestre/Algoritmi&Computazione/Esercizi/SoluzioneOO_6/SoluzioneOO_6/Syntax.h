#if !defined(SYNTAX_H)
#define SYNTAX_H

#include <vector>
#include <string>

// Composite/interpreter hierarchy for program syntax according to the CF grammar:
//
// P ::= A | B stands for
// P ::= A
// P ::= B
// 
// Program ::= Statement | Statement other_statements

// other_statements ::= epsilon | Statement other_statements

// Statement ::= Definition | Expression

// Definition ::= ID = Expression

// Expression ::= (Expression operator Expression) | ID | CONST

// operator ::= + | - | * | /

// Forward declaration of Visitor class for evaluation
class Visitor;
 
struct Statement {
	virtual void accept(Visitor& visitor) const = 0;
};

struct Program {
	//TODO: define constructors, destructors, etc.
	void accept(Visitor& visitor) const;

	std::vector<Statement*> statements;
};

struct Expression : public Statement { };

struct Operator : public Expression {
	//TODO: complete definition of constructors, destructors, etc.
	// opCode is one of Token::ADD, Token::SUB, Token::MUL, Token::DIV
	Operator(int opCode, Expression* l, Expression* r) :
		opCode_{ opCode }, left_{ l }, right_{ r } { }

	void accept(Visitor& visitor) const;

	int opCode_;
	Expression* left_;
	Expression* right_;
};

struct Variable : public Expression {
	//TODO: complete definition of constructors, destructors, etc.
	Variable(std::string id) : id_{ id } { }

	void accept(Visitor& visitor) const;

	std::string id_;
};

struct Constant : public Expression {
	//TODO: complete definition of constructors, destructors, etc.
	Constant(int num) : num_{ num } { }

	void accept(Visitor& visitor) const;

	int num_;

};

struct Definition : public Statement {
	//TODO: complete definition of constructors, destructors, etc.
	Definition(Variable* v, Expression* e) :
		variable_{v}, expression_{e} { }

	void accept(Visitor& visitor) const override;

	Variable* variable_;
	Expression* expression_;
};


#endif
