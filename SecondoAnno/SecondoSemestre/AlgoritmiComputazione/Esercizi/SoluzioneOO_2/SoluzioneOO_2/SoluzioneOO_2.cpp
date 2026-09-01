#include <iostream>

class Context {};

// Pattern Interpreter: AbstractExpression
// Pattern Composite: Component
class Expression {

public:
    // TODO: Implementare costruttori, distruttori, ecc.

    // Metodo astratto interpret
    // Assunzione 1: le espressioni sono formate da valori interi
    // Assunzione 2: il metodo interpret non modifica il contesto di valutazione
    virtual int interpret(Context const& context) = 0;
};

// Pattern Interpreter: TerminalExpression
// Pattern Composite: Leaf
class Number : public Expression {

public:
    Number(int value) : value_{value} {}
    // TODO: Definire altri costruttori, distruttori, ecc.

    int interpret(Context const& context) override {
        return value_;
    }

private:
    int value_;
};

// Pattern Interpreter: NonterminalExpression
// Pattern Composite: Composite
class Operator : public Expression {

public:
    Operator(char op, Expression* leftOperand, Expression* rightOperand) : 
        operator_{ op }, left_{ leftOperand }, right_{ rightOperand } {}
    // TODO: Definire altri costruttori, distrutturi, ecc.

    int interpret(Context const& context) override {
        int left_value = left_->interpret(context);
        int right_value = right_->interpret(context);
        switch (operator_) {
        case '+': return left_value + right_value;
        case '-': return left_value - right_value;
        case '*': return left_value * right_value;
        case '/': return left_value / right_value;
        case '%': return left_value % right_value;
        default: return 0;
        }
    }

private:
    char operator_;
        Expression* left_;
    Expression* right_;

};



int main()
{
    Context context;

    Expression* a = new Number(5);
    Expression* b = new Number(12);
    // Ho codificato l'espressione 5 + 12
    Expression* c = new Operator('+', a, b);

    std::cout << "Il risultato della valutazione è " 
        << c->interpret(context) << std::endl;
}
