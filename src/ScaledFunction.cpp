#include "ScaledFunction.h"
#include "ScaledFunction.h"

ScaledFunction::ScaledFunction(const SimpleFunction* func, double scale)
	: m_func(func->clone()), m_scale(scale) { }


double ScaledFunction::eval(double x) const
{
	return m_scale * m_func->eval(x);
}

void ScaledFunction::print(std::ostream& os) const
{
	os << m_scale << " * (";
	m_func->print(os);
	os << ")";
}

std::shared_ptr<ScaledFunction> ScaledFunction::scail(double factor) const
{
	return std::make_shared<ScaledFunction>(m_func.get(), m_scale * factor);
}

SimpleFunction* ScaledFunction::cloneImpl() const
{
	return new ScaledFunction(m_func.get(), m_scale);
}