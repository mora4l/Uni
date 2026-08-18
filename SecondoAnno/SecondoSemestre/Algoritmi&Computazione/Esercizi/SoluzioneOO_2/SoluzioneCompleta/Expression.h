#if !defined(EXPRESSION_H)
#define EXPRESSION_H

#include "Context.h"

class Expression {
public:
    virtual ~Expression() = default;
    virtual int interpret(Context const&) const = 0;
};

class Number : public Expression {
public:
    Number(int v) : value{ v } { }
    ~Number() = default;

    Number(Number const& other) = default;
    Number& operator=(Number const& other) = default;

    int getValue() const {
        return value;
    }

    int interpret(Context const&) const override {
        return value;
    }

private:
    int value;
};

// Adding a class variable
class Variable : public Expression {
public:
    Variable(std::string const& v) : identifier{ v } { }
    ~Variable() = default;

    Variable(Variable const& other) = default;
    Variable& operator=(Variable const& other) = default;

    std::string const& getIdentifier() const {
        return identifier;
    }

    int interpret(Context const& c) const override {
        return c.getValue(identifier);
    }

private:
    std::string identifier;
};

class Operator : public Expression {
public:
    enum OpCode { PLUS, MINUS, TIMES, DIV };

    Operator(OpCode o, Expression* lop, Expression* rop) :
        op{ o }, left{ lop }, right{ rop } { }
    ~Operator() = default;

    Operator(Operator const& other) = default;
    Operator& operator=(Operator const& other) = default;

    OpCode getOp() const {
        return op;
    }
    Expression* getLeft() const {
        return left;
    }
    Expression* getRight() const {
        return right;
    }

    int interpret(Context const&) const override;

    static OpCode charToOpCode(char ch) {
        switch (ch) {
        case '+': return PLUS;
        case '-': return MINUS;
        case '*': return TIMES;
        case '/': return DIV;
        }
    }

private:
    OpCode      op;
    Expression* left;
    Expression* right;

};

#endif

