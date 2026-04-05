#pragma once
#include "SimpleFunction.h"

class LogFunction : public SimpleFunction
{
public:
    LogFunction(double base);


    virtual double eval(double x) const override;
    virtual void print(std::ostream& os) const override;

private:
    SimpleFunction* cloneImpl() const override;

	double m_base;
	double m_log10Base;
};
