#include <iostream>

#include "Expression.h"
#include "ExpressionManager.h"

void leaks_memory(Context const& c, int n, int m) {
	// (n * m) + n
	Expression* a = new Number(n);
	Expression* b = new Number(m);
	Expression* e = new Operator(Operator::TIMES, a, b);
	std::cout << "The result is: " << e->interpret(c) << std::endl;
}

void does_not_leak_memory(Context const& c, ExpressionManager& mgr,
	int n, int m) {
	Expression* a = mgr.makeNumber(n);
	Expression* b = mgr.makeNumber(m);
	Expression* e = mgr.makeOperator(Operator::TIMES, a, b);
	std::cout << "The result is: " << e->interpret(c) << std::endl;
}

int main() {
	// An empty context
	Context myContext;

	// This code causes a memory leak: objects created locally in 
	// the function are no longer accessible after the call returns
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			leaks_memory(myContext, i, j);
		}
	}

	// This code does not cause a memory leak: objects created locally
	// through the manager remain accessible through the manager for 
	// deallocation
	ExpressionManager mgr;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			does_not_leak_memory(myContext, mgr, i, j);
		}
	}

	// Add a variable to the context
	myContext.setValue("x", 20);
	// The variable can be used in expressions
	Expression* v = mgr.makeVariable("x");
	Expression* n = mgr.makeNumber(10);
	Expression* e = mgr.makeOperator(Operator::PLUS, v, n);
	std::cout << e->interpret(myContext) << std::endl;

	return 0;
}
