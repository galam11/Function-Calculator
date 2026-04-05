#include "SimpleFunction.h"
#include "ScaledFunction.h"

std::unique_ptr<SimpleFunction> SimpleFunction::clone() const
{
	return std::unique_ptr<SimpleFunction>(cloneImpl());
}

std::shared_ptr<ScaledFunction> SimpleFunction::scale(double factor) const 
{
	return std::make_shared<ScaledFunction>(this, factor);
}