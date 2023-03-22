#pragma once

#ifndef FILEANDNUMBERSVARIABLESCLASS_H
#define FILEANDNUMBERSVARIABLESCLASS_H
#include <sstream>
#include <string>
#include <vector>
#include "InputType.h"
#include "InputValidator.h"
#include <iostream>
#include <string_view>
#include <iomanip>
#include <regex>
#include <fstream>        // for std::ifstream
#include <ranges>         // for std::ranges::views::split
#include <string>         // for std::string
#include <string_view>    // for std::string_view
#include <vector>         // for std::vector
#include <algorithm>      // for std::ranges::find
#include <iostream>
#include <vector>
#include <algorithm>
#include <Filter.h>
#include <map>
#include "Stack.h"

class fileAndNumbersVariablesClass : public InputType
{
public:

	fileAndNumbersVariablesClass();
	fileAndNumbersVariablesClass(const char*);

	//from virtual class

	void readVariables(const char*) override;
	void convertToVector(const char*) override; // v11
	void replaceVariableValues() override;
	//int setNumbersArraySize();
	//int setSymbolslArraySize();

	bool identifyFileVariables(const char*);

	InputValidator* validate = new InputValidator();
	std::vector<std::string> expressionToVector;
	std::vector<std::string> fileVariablesId;
	std::vector<std::string> fileVariablesValue;

private:
	char* expression;
	fs::path filePath = "expresiones.txt";
};

#endif // !FILEVARIABLES_H
