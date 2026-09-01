#if !defined(VISITOR_H)
#define VISITOR_H

#include "Syntax.h"

class Visitor {
public:
	virtual void visit(Program const& p) = 0;
	virtual void visit(Definition const& d) = 0;
	virtual void visit(Operator const& o) = 0;
	virtual void visit(Variable const& v) = 0;
	virtual void visit(Constant const& c) = 0;
};


#endif
