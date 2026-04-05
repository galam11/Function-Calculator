#pragma once
#include "Function.h"
#include <memory>

class ScaledFunction;

class SimpleFunction : public Function
{
public:
    std::unique_ptr<SimpleFunction> clone() const;

	virtual std::shared_ptr<ScaledFunction> scale(double factor) const;
private:
	virtual SimpleFunction* cloneImpl() const = 0;
};
