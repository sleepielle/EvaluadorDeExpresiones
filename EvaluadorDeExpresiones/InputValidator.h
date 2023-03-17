#pragma once
#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <regex>
#include <vector>
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
#include <algorithm>
#include <cctype>
namespace fs = std::filesystem;

class InputValidator
{
public:

	InputValidator();
	InputValidator(const char*);

	constexpr bool validateIfContainsUnary(const char*); //v11
	bool validateExpressíonEnding(const char*);
	bool validateMatchingParenthesis(const char*);
	bool validateVariablesInFile(const char*);
	bool validateIfHasInvalidCharacters(std::string);
	void iterateFileVariables(std::vector<std::string>);
	void iterateUserVariables(std::vector<std::string>);
	bool validateAll(const char*);
	bool checkIfContainsJustNumbers(const char*);
	bool identifyUserVariables(const char*);
	string removeWhiteSpaces(string data);
	void convertToVector(const char*);

	//bool checkIfVarAlreadyExists

	std::vector<std::string> identifyFileVariables(std::vector<std::string>);

	std::vector<std::string> crossReferenceUserVariables(std::vector<std::string>, std::vector<std::string>);
	std::vector<std::string> fileVariablesId;
	std::vector<std::string> fileVariablesValue;
	std::vector<std::string> foundVariables;
	std::vector<std::string> userVariables;
	std::vector<std::string> expressionToVector;

private:
	char* data;
	fs::path filePath = "expresiones.txt";
};

#endif // !INPUTVALIDATOR_H
