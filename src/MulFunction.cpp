#include "MulFunction.h"


MulFunction::MulFunction(std::shared_ptr<Function> funcA, std::shared_ptr<Function> funcB)
	: ComplexFunction(funcA, funcB) {
}


double MulFunction::eval(double x) const
{
	return m_funcA->eval(x) * m_funcB->eval(x);
}

void MulFunction::print(std::ostream& os) const
{
	os << "(";
	m_funcA->print(os);
	os << ") * (";
	m_funcB->print(os);
	os << ")";
}