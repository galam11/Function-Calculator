#pragma once
#include "ComplexFunction.h"

class MulFunction : public ComplexFunction
{
public:
	MulFunction(std::shared_ptr<Function> funcA, std::shared_ptr<Function> funcB);

	double eval(double x) const override;
	void print(std::ostream& os) const override;
};
