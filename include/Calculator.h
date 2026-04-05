#pragma once
#include "SimpleFunction.h"
#include "ComplexFunction.h"

#include <vector>

class Calculator
{
public:
	Calculator();
	void run();

    
private:
    bool m_run = true;
	std::vector<std::shared_ptr<SimpleFunction>> m_simpleFunctions;
	std::vector<std::shared_ptr<ComplexFunction>> m_complexFunction;

    std::shared_ptr<Function> getFunction(int index);
    int complexFuncStartIndex() const;
    int functionSize() const;
    bool validIndex(int index) const;
	bool validSimpleFunctionIndex(int index) const;
	bool validComplexFunctionIndex(int index) const;

    void printFunctions() const;

    void handleEval(std::stringstream& stream);
    void handleLog(std::stringstream& stream);
    void handlePoly(std::stringstream& stream);
    void handleAdd(std::stringstream& stream);
    void handleMul(std::stringstream& stream);
    void handleScale(std::stringstream& stream);
    void handleDel(std::stringstream& stream);
    void handleHelp();
    void handleExit();

};
