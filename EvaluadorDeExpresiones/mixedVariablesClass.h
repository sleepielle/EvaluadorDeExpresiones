#pragma once

#ifndef MIXEDVARIABLESCLASS_H
#define MIXEDVARIABLESCLASS_H
#include <sstream>
#include <string>
#include <vector>
#include "InputType.h"
#include "InputValidator.h"
#include <iostream>
#include <ranges>
#include <string_view>
#include <iomanip>
#include <regex>
#include <cstring>

class mixedVariablesClass : public InputType
{
public:

	mixedVariablesClass();
	mixedVariablesClass(std::vector<string>, std::vector<string>,std::vector<string> , std::vector<string> , const char*);

	//from virtual class
	void readVariables(const char*);
	void convertToVector(const char*);
	void replaceVariableValues();

	InputValidator* validate = new InputValidator();

	std::vector<std::string> expressionToVector;
	std::vector<std::string> userVariablesValues;
	std::vector<string> fileVariablesValues;

	std::vector<std::string> userVariablesId;
	std::vector<string> fileVariablesId;

private:
	char* expression;

};

#endif // !USERVARIABLESCLASS_H