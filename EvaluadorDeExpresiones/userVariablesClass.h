#pragma once

#ifndef USERVARIABLESCLASS_H
#define USERVARIABLESCLASS_H
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

class userVariablesClass : public InputType
{
public:

	userVariablesClass();
	userVariablesClass(std::vector<string>, const char*);

	//from virtual class
	void readVariables(const char*) override;
	void convertToVector(const char*) override;
	void replaceVariableValues() override;

	InputValidator* validate = new InputValidator();

	std::vector<std::string> expressionToVector;
	std::vector<std::string> userVariablesId;
	std::vector<string> userVariablesValue;

private:
	char* expression;
};

#endif // !USERVARIABLESCLASS_H
