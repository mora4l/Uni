#if !defined(EXPRESSION_MGR_H)

#include <vector>

#include "Expression.h"

class ExpressionManager {
public:
    ExpressionManager() = default;
    ~ExpressionManager() {
        clearMemory();
    }

    ExpressionManager(ExpressionManager const& other) = delete;
    ExpressionManager& operator=(ExpressionManager const& other) = delete;

    Expression* makeNumber(int value) {
        Expression* n = new Number(value);
        allocated.push_back(n);
        return n;
    }
    Expression* makeOperator(Operator::OpCode op, Expression* l, Expression* r) {
        Expression* o = new Operator(op, l, r);
        allocated.push_back(o);
        return o;
    }
    Expression* makeVariable(std::string const& name) {
        Expression* o = new Variable(name);
        allocated.push_back(o);
        return o;
    }

    void clearMemory() {
        auto i = allocated.begin();
        for (; i != allocated.end(); ++i) {
            delete(*i);
        }
        allocated.resize(0);
    }

private:
    std::vector<Expression*> allocated;
};

#endif

