#if !defined(PRINT_VISITOR_H)
#define PRINT_VISITOR_H

#include <iostream>

#include "Visitor.h"
#include "Syntax.h"
#include "Token.h"

//TODO: complete EvaluationVisitor
class PrintVisitor : public Visitor {

public:
	//TODO: complete definition of constructors, destructors, etc.
	PrintVisitor(std::ostream& con) : console_{ con } { }

	void visit(Program const& p) override {
		for (Statement* statement : p.statements) {
			statement->accept(*this);
			console_ << std::endl;
		}
	}
	void visit(Definition const& d) override {
		d.variable_->accept(*this);
		console_ << " " << Token::id2word[Token::EQ] << " ";
		d.expression_->accept(*this);
	}
	void visit(Operator const& o) override {
		console_ << Token::id2word[Token::LP];
		o.left_->accept(*this);
		console_ << " " << Token::id2word[o.opCode_] << " ";
		o.right_->accept(*this);
		console_ << Token::id2word[Token::RP];
	}
	void visit(Variable const& v) override {
		console_ << v.id_;
	}
	void visit(Constant const& c) override {
		console_ << c.num_;
	}

private:
	std::ostream& console_;

};



#endif
