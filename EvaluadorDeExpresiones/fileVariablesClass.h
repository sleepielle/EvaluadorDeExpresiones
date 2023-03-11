#pragma once

#ifndef FILEVARIABLES_H
#define FILEVARIABLES_H
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
#include <fstream>        // for std::ifstream
#include <ranges>         // for std::ranges::views::split
#include <string>         // for std::string
#include <string_view>    // for std::string_view
#include <vector>         // for std::vector
#include <algorithm>      // for std::ranges::find

#include "Stack.h"
class fileVariablesClass : public InputType
{
public:

	fileVariablesClass();
	fileVariablesClass(const char*);

	//from virtual class

	void readVariables(const char*);
	void convertToVector(const char*);
	void replaceVariableValues();
	//int setNumbersArraySize();
	//int setSymbolslArraySize();

	
	InputValidator* validate = new InputValidator();
	std::vector<std::string> expressionToVector;
	std::vector<std::string> fileVariablesId;
	std::vector<std::string> fileVariablesValue;

private:
	char* expression;
	fs::path filePath = "expresiones.txt";

};

#endif // !FILEVARIABLES_H
