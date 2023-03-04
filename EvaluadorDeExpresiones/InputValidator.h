#pragma once
#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
namespace fs = std::filesystem;

class InputValidator
{


public:
	InputValidator();
	InputValidator(const char*);

	bool validateIfNotUnary(const char*);
	bool validateExpressíonEnding(const char*);
	bool validateMatchingParenthesis(const char*);
	bool validateVariablesInFile(const char*);
	//bool checkIfVarAlreadyExists

	std::vector<std::string> identifyFileVariables(std::vector<std::string>);
	std::vector<std::string> identifyUserVariables(const char*);
	std::vector<std::string> crossReferenceUserVariables(std::vector<std::string>, std::vector<std::string>);

private:
	char* data;
	fs::path filePath = "expresiones.txt";
	std::vector<std::string> fileVariables;
	std::vector<std::string> foundVariables;
	std::vector<std::string> userVariables;
};


#endif // !INPUTVALIDATOR_H


