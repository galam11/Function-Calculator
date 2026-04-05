#pragma once
#include "SimpleFunction.h"
#include <memory>

class ScaledFunction : public SimpleFunction
{
public:
	ScaledFunction(const SimpleFunction* func, double scale);

	double eval(double x) const override;
	void print(std::ostream& os) const override;

	std::shared_ptr<ScaledFunction> scail(double factor) const override;
	
public:
	SimpleFunction* cloneImpl() const override;
	std::unique_ptr<SimpleFunction> m_func;
	double m_scale;
};
