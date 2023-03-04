#pragma once
#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <regex>
#include <vector>
namespace fs = std::filesystem;




class InputValidator
{


public:
std::vector<std::string> fileVariables;
std::vector<std::string> foundVariables;
std::vector<std::string> userVariables;


	InputValidator();
	InputValidator(const char*);

	bool validateIfContainsUnary(const char*);
	bool validateExpressíonEnding(const char*);
	bool validateMatchingParenthesis(const char*);
	bool validateVariablesInFile(const char*);
	bool validateIfHasInvalidCharacters(std::string);
	void iterateFileVariables(std::vector<std::string>);
	void iterateUserVariables(std::vector<std::string>);
	bool validateAll(const char*);
	bool checkIfContainsJustNumbers(const char*);
	bool identifyUserVariables(const char*);
	//bool checkIfVarAlreadyExists

	std::vector<std::string> identifyFileVariables(std::vector<std::string>);
	
	std::vector<std::string> crossReferenceUserVariables(std::vector<std::string>, std::vector<std::string>);



private:
	char* data;
	fs::path filePath = "expresiones.txt";


};


#endif // !INPUTVALIDATOR_H


