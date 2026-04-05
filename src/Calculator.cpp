#include "Calculator.h"
#include "Calculator.h"

#include "macros.h"

#include "LogFunction.h"
#include "PolynomialFunction.h"
#include "ScaledFunction.h"
#include "AddFunction.h"
#include "MulFunction.h"

#include <cmath>
#include <sstream>

Calculator::Calculator()
{
	m_simpleFunctions.push_back(std::make_shared<LogFunction>(10));
}

void Calculator::run()
{
	handleHelp();

	while (m_run)
	{
		printFunctions();

		std::string line;
		std::getline(std::cin, line);
		
		std::stringstream stream(line);

		std::string command;
		stream >> command;


		if (command == EVAL)
			handleEval(stream);
		else if (command == LOG)
			handleLog(stream);
		else if (command == POLY)
			handlePoly(stream);
		else if (command == ADD)
			handleAdd(stream);
		else if (command == MUL)
			handleMul(stream);
		else if (command == SCALE)
			handleScale(stream);
		else if (command == DEL)
			handleDel(stream);
		else if (command == HELP)
			handleHelp();
		else if (command == EXIT)
			handleExit();
		else
			std::cout << "Invalid command" << std::endl;
	}

}

std::shared_ptr<Function> Calculator::getFunction(int index)
{
	if (!validIndex(index))
		return nullptr;
	else if (index >= complexFuncStartIndex())
		return m_complexFunction[index - complexFuncStartIndex()];
	else
		return m_simpleFunctions[index];
}

int Calculator::complexFuncStartIndex() const
{
	return m_simpleFunctions.size();
}

int Calculator::functionSize() const
{
	return m_simpleFunctions.size() + m_complexFunction.size();
}

bool Calculator::validIndex(int index) const
{
	return index >= 0 && index < functionSize();
}

bool Calculator::validSimpleFunctionIndex(int index) const
{
	return index >= 0 && index < complexFuncStartIndex();
}

bool Calculator::validComplexFunctionIndex(int index) const
{
	return index >= complexFuncStartIndex() && index < functionSize();
}

void Calculator::printFunctions() const
{
	int index = 0;
	for (const auto& func : m_simpleFunctions)
	{
		std::cout << index++ << ": ";
		func->print(std::cout);
		std::cout << std::endl;
	}

	for (const auto& func : m_complexFunction)
	{
		std::cout << index++ << ": ";
		func->print(std::cout);
		std::cout << std::endl;
	}
}

void Calculator::handleEval(std::stringstream& stream)
{
	int index = 0 , x = 0;

	if (!(stream >> index) || !validIndex(index) || !(stream >> x))
	{
		std::cout << "Invalid usage - " << EVAL_USAGE << std::endl;
		return;
	}
	
	auto result = getFunction(index)->eval(x);
	std::cout << std::round(result * 100.0) / 100.0 << std::endl;

}

void Calculator::handleLog(std::stringstream& stream)
{
	double base = 0;
	if (!(stream >> base) || base <= 1)
	{
		std::cout << "Invalid usage - " << LOG_USAGE << std::endl;
		return;
	}

	m_simpleFunctions.push_back(std::make_shared<LogFunction>(base));
}

void Calculator::handlePoly(std::stringstream& stream)
{
	int degree = 0;
	if (!(stream >> degree) || degree < 0)
	{
		std::cout << "Invalid usage - " << POLY_USAGE << std::endl;
		return;
	}

	std::vector<double> coeffs(degree);
	for (int i = 0; i < degree; i++)
	{
		double coeff = 0;
		if (!(stream >> coeff))
		{
			std::cout << "Invalid usage - " << POLY_USAGE << std::endl;
			return;
		}

		coeffs[i] = coeff;
	}
	
	m_simpleFunctions.push_back(std::make_shared<PolynomialFunction>(coeffs));
}

void Calculator::handleScale(std::stringstream& stream)
{
	int index = 0;
	if (!(stream >> index))
	{
		std::cout << "Invalid usage - " << SCALE_USAGE << std::endl;
		return;
	}

	if (!validSimpleFunctionIndex(index))
	{
		std::cout << "<" << index << "> is not a simple function" << std::endl;
		return;
	}

	double factor = 0;
	if (!(stream >> factor))
	{
		std::cout << "Invalid usage - " << SCALE_USAGE << std::endl;
		return;
	}

	m_simpleFunctions.push_back(m_simpleFunctions[index]->scale(factor));
}

void Calculator::handleAdd(std::stringstream& stream)
{
	int index1 = 0, index2 = 0;
	if (!(stream >> index1) || !validIndex(index1) || !(stream >> index2) || !validIndex(index2))
	{
		std::cout << "Invalid usage - " << ADD_USAGE << std::endl;
		return;
	}

	m_complexFunction.push_back(std::make_shared<AddFunction>(getFunction(index1), getFunction(index2)));

}

void Calculator::handleMul(std::stringstream& stream)
{
	int index1 = 0, index2 = 0;
	if (!(stream >> index1) || !validIndex(index1) || !(stream >> index2) || !validIndex(index2))
	{
		std::cout << "Invalid usage - " << MUL_USAGE << std::endl;
		return;
	}

	m_complexFunction.push_back(std::make_shared<MulFunction>(getFunction(index1), getFunction(index2)));
}

void Calculator::handleDel(std::stringstream& stream)
{
	int index = 0;
	if (!(stream >> index) || !validIndex(index))
	{
		std::cout << "Invalid usage - " << DEL_USAGE << std::endl;
		return;
	}

	if (index < complexFuncStartIndex())
		m_simpleFunctions.erase(m_simpleFunctions.begin() + index);
	
	else
		m_complexFunction.erase(m_complexFunction.begin() + (index - complexFuncStartIndex()));
}

void Calculator::handleHelp()
{
	std::cout << HELP_MESSAGE << std::endl;
}

void Calculator::handleExit()
{
	std::cout << "Exiting the calculator." << std::endl;
	m_run = false;
}