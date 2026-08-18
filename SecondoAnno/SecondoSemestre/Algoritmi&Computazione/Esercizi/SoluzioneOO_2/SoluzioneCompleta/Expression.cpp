#include "Expression.h"

int Operator::interpret(Context const& c) const {
    int lval = left->interpret(c);
    int rval = right->interpret(c);
    switch (op) {
    case PLUS:
        return lval + rval;
    case MINUS:
        return lval - rval;
    case TIMES:
        return lval * rval;
    case DIV:
        return lval / rval;
    default:
        return 0;
    }
}