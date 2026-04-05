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
	bool validComplaxFunctionIndex(int index) const;

    void printFunctions() const;

    void handleEval(std::stringstream& streem);
    void handleLog(std::stringstream& streem);
    void handlePoly(std::stringstream& streem);
    void handleAdd(std::stringstream& streem);
    void handleMul(std::stringstream& streem);
    void handleScale(std::stringstream& streem);
    void handleDel(std::stringstream& streem);
    void handleHelp();
    void handleExit();

};
