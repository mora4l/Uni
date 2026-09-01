#include "Syntax.h"
#include "Visitor.h"

void Program::accept(Visitor& visitor) const {
	visitor.visit(*this);
};

void Definition::accept(Visitor& visitor) const {
	visitor.visit(*this);
};

void Operator::accept(Visitor& visitor) const {
	visitor.visit(*this);
};

void Variable::accept(Visitor& visitor) const {
	visitor.visit(*this);
};

void Constant::accept(Visitor& visitor) const {
	visitor.visit(*this);
};
