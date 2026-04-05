#pragma once
#include "SimpleFunction.h"
#include <vector>
class PolynomialFunction : public SimpleFunction
{
public:
	PolynomialFunction(const std::vector<double>& coefficients);

	double eval(double x) const override;
	void print(std::ostream& os) const override;

private:
	SimpleFunction* cloneImpl() const override;
	std::vector<double> m_coefficients;
};
