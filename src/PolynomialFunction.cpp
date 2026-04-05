#include "PolynomialFunction.h"
#include <cmath>

PolynomialFunction::PolynomialFunction(const std::vector<double>& coefficients)
	: m_coefficients(coefficients) { }


double PolynomialFunction::eval(double x) const
{
	double result = 0.0;
	double power = 1.0; 
	for (const auto& coeff : m_coefficients)
	{
		result += coeff * power;
		power *= x; 
	}
	return result;
}

void PolynomialFunction::print(std::ostream& os) const
{
	bool printZero = true;

	for (int i = 0; i < m_coefficients.size(); i++)
	{
		int index = m_coefficients.size() - 1 - i;
		int abs = std::abs(m_coefficients[index]);

		if (abs > 0) printZero = false;

		if (m_coefficients[index] == 0)
			continue;
		
		if (i > 0)
			if (m_coefficients[index] > 0)
				os << " + ";
			else
				os << " - ";

		if (index == 0)
			os << abs;
		else if (index == 1)
			os << abs << "*(x)";
		else
			os << abs << "*(x)^" << index;
	}

	if (printZero)
		os << "0";
}

SimpleFunction* PolynomialFunction::cloneImpl() const
{
	return new PolynomialFunction(m_coefficients);
}
