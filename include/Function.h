#pragma once
#include <iostream>

class Function
{
public:
    virtual double eval(double x) const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual ~Function() = default;
};

std::ostream& operator<<(std::ostream& os, const Function& func);