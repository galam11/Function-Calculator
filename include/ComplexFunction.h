#pragma once
#include "Function.h"
#include <memory>
class ComplexFunction : public Function
{
public:
	ComplexFunction(std::shared_ptr<Function> funcA, std::shared_ptr<Function> funcB);

protected:
	std::shared_ptr<Function> m_funcA;
	std::shared_ptr<Function> m_funcB;
};

