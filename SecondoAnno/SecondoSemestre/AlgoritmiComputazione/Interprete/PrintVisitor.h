#ifndef PRINT_VISITOR_H
#define PRINT_VISITOR_H

#include <iostream>
#include <string>

#include "Visitor.h"
#include "Syntax.h"
#include "Token.h"

class PrintVisitor : public Visitor {
public:
    explicit PrintVisitor(std::ostream& out = std::cout) 
        : out_{ out }, indentLevel_{ 0 } {}

    void visit(Program const& program) override {
        out_ << indent() << "[Program]\n";
        indentLevel_ += 2;
        
        program.root_->accept(*this);
        
        indentLevel_ -= 2;
    }

    void visit(Block const& block) override {
        out_ << indent() << "[Block]\n";
        indentLevel_ += 2;
        
        for (auto* stmt : block.statements_) {
            stmt->accept(*this);
        }
        
        indentLevel_ -= 2;
    }

    void visit(PrintStmt const& print) override {
        out_ << indent() << "[PrintStmt]\n";
        indentLevel_ += 2;
        
        print.num_expr_->accept(*this);
        
        indentLevel_ -= 2;
    }

    void visit(InputStmt const& in) override {
        out_ << indent() << "[InputStmt]\n";
        indentLevel_ += 2;
        
        in.variable_id_->accept(*this);
        
        indentLevel_ -= 2;
    }

    void visit(WhileStmt const& whil) override {
        out_ << indent() << "[WhileStmt]\n";
        indentLevel_ += 2;
        
        out_ << indent() << "Condition:\n";
        whil.bool_expr_->accept(*this);
        
        out_ << indent() << "Body:\n";
        whil.stmt_block_->accept(*this);
        
        indentLevel_ -= 2;
    }

    void visit(IfStmt const& iff) override {
        out_ << indent() << "[IfStmt]\n";
        indentLevel_ += 2;
        
        out_ << indent() << "Condition:\n";
        iff.bool_expr->accept(*this);
        
        out_ << indent() << "True Branch:\n";
        iff.stmt_block1->accept(*this);
        
        if (iff.stmt_block2 != nullptr) {
            out_ << indent() << "False Branch:\n";
            iff.stmt_block2->accept(*this);
        }
        
        indentLevel_ -= 2;
    }

    void visit(SetStmt const& set) override {
        out_ << indent() << "[SetStmt]\n";
        indentLevel_ += 2;
        
        set.variable_id_->accept(*this);
        set.num_expr_->accept(*this);
        
        indentLevel_ -= 2;
    }

    void visit(Operator const& op) override {
        out_ << indent() << "[Operator]\n";
        indentLevel_ += 2;
        
        op.left_->accept(*this);
        op.right_->accept(*this);
        
        indentLevel_ -= 2;
    }

    void visit(Number const& num) override {
        out_ << indent() << "Number(";
        out_ << num.n_;
        out_ << ")\n";
    }

    void visit(Variable const& var) override {
        out_ << indent() << "Variable(";
        out_ << var.id_;
        out_ << ")\n";
    }

    void visit(BoolOp const& boolop) override {
        out_ << indent() << "[BoolOp]\n";
        indentLevel_ += 2;
        
        boolop.op1->accept(*this);
        boolop.op2->accept(*this);
        
        indentLevel_ -= 2;
    }

    void visit(BoolConst const& boolconst) override {
        out_ << indent() << "BoolConst(";
        out_ << (boolconst.boolean ? "true" : "false");
        out_ << ")\n";
    }

    void visit(RelOp const& relop) override {
        out_ << indent() << "[RelOp]\n";
        indentLevel_ += 2;
        
        relop.num1_l->accept(*this);
        relop.num2_r->accept(*this);
        
        indentLevel_ -= 2;
    }

private:
    std::ostream& out_;
    int indentLevel_; 

    std::string indent() const {
        return std::string(indentLevel_, ' ');
    }
};

#endif