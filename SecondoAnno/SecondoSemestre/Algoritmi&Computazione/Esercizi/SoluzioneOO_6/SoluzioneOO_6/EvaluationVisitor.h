#if !defined(EVALUTATION_VISITOR_H)
#define EVALUATION_VISITOR_H

#include <iostream>

#include "Visitor.h"
#include "SymbolTable.h"

//TODO: complete EvaluationVisitor
class EvaluationVisitor : public Visitor {
	
public:
	//TODO: complete definition of constructors, destructors, etc.
	EvaluationVisitor(SymbolTable& st, std::ostream& con) : 
		symbolTable_{ st }, console_{ con } { }

	void visit(Program const& p) override {
		for (Statement* statement : p.statements) {
			statement->accept(*this);
			console_ << std::endl;
		}
	}
	void visit(Definition const& d) override {
		console_ << d.variable_->id_;
		console_ << " " << Token::id2word[Token::EQ] << " ";
		d.expression_->accept(*this);
	} 
	void visit(Operator const& o) override {
		//TODO
	} 
	void visit(Variable const& v) override {
		int value = symbolTable_.getValue(v.id_);
		//TODO
	} 
	void visit(Constant const& c) override {
		//TODO
	}

	//TODO: method to get the computed value of the expression

private:
	SymbolTable& symbolTable_;
	std::ostream& console_;

};

#endif
