#include "AddFunction.h"

AddFunction::AddFunction(std::shared_ptr<Function> funcA, std::shared_ptr<Function> funcB)
	: ComplexFunction(funcA, funcB) { }


double AddFunction::eval(double x) const
{
	return m_funcA->eval(x) + m_funcB->eval(x);
}

void AddFunction::print(std::ostream& os) const
{
	os << "(";
	m_funcA->print(os);
	os << ") + (";
	m_funcB->print(os);
	os << ")";
}