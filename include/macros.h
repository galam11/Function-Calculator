
#pragma once
#include <string>

const std::string EVAL			= "eval";
const std::string LOG			= "log";
const std::string POLY			= "poly";
const std::string ADD			= "add";
const std::string MUL			= "mul";
const std::string SCALE			= "scale";
const std::string DEL			= "del";

const std::string HELP			= "help";
const std::string EXIT			= "exit";

const std::string EVAL_USAGE	= "eval(uate) <num> <x>";
const std::string LOG_USAGE		= "log <X>";
const std::string POLY_USAGE	= "poly(nom) <n> <c0> <c1> ... <cn-1>";
const std::string ADD_USAGE		= "add <num1> <num2>";
const std::string MUL_USAGE		= "mul(tiply) <num1> <num2>";
const std::string SCALE_USAGE	= "scale <num> <c>";
const std::string DEL_USAGE		= "del(ete) <num>";

const std::string EVAL_DESC		= "Calculates the value of the function at a given point x";
const std::string LOG_DESC		= "Adds a logarithm function with a specified base to the list";
const std::string POLY_DESC		= "Adds a polynomial with n coefficients to the list";
const std::string ADD_DESC		= "Adds a new function that is the sum of two existing functions";
const std::string MUL_DESC		= "Adds a new function that is the product of two existing functions";
const std::string SCALE_DESC	= "Adds a copy of a simple function multiplied by a scalar";
const std::string DEL_DESC		= "Removes a function from the list by its index";
const std::string HELP_DESC		= "Displays the help screen with available commands";
const std::string EXIT_DESC		= "Terminates the program";

const std::string HELP_MESSAGE =
	std::string("Following is the list of the calculator's available commands:\n") +
	"\t" + EVAL_USAGE	+ " - " + EVAL_DESC		+ "\n" +
	"\t" + LOG_USAGE	+ " - " + LOG_DESC		+ "\n" +
	"\t" + POLY_USAGE	+ " - " + POLY_DESC		+ "\n" +
	"\t" + ADD_USAGE	+ " - " + ADD_DESC		+ "\n" +
	"\t" + MUL_USAGE	+ " - " + MUL_DESC		+ "\n" +
	"\t" + SCALE_USAGE	+ " - " + SCALE_DESC	+ "\n" +
	"\t" + DEL_USAGE	+ " - " + DEL_DESC		+ "\n" +
	"\t" + HELP			+ " - " + HELP_DESC		+ "\n" +
	"\t" + EXIT			+ " - " + EXIT_DESC;