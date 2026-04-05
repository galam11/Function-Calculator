#include "LogFunction.h"
#include <cmath>

LogFunction::LogFunction(double base) : 
	m_base(base),
	m_log10Base(std::log10(base)) 
{ }

double LogFunction::eval(double x) const
{
	return std::log10(x) / m_log10Base;
}

void LogFunction::print(std::ostream& os) const
{
	os << "log"<< m_base <<"(x)";
}

SimpleFunction* LogFunction::cloneImpl() const
{
	return new LogFunction(m_base);
}