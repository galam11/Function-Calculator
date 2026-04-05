#include "ComplexFunction.h"

ComplexFunction::ComplexFunction(std::shared_ptr<Function> funcA, std::shared_ptr<Function> funcB)
	: m_funcA(funcA), m_funcB(funcB) { }