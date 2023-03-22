#pragma once

#ifndef TDD_H
#define TDD_H
#include "fileAndNumbersVariablesClass.h"
#include "justNumbersClass.h"
#include "mixedVariablesClass.h"
#include "userVariablesClass.h"
#include "Stack.h"
#include <iostream>
#include <memory>

using std::cout; using std::endl;

class TDD
{
public:
	TDD();
	void printScreenSuccess();
	void printScreenFailure();

	string simpleOperation();
	string moduleOperation();
	string divisionOperation();
	string fileVariablesOperation();
	string multipleParenthesis();

	string unaryOperation();
	string mismatchedParenthesisOperation();
	string divisionOverZeroOperation();
	string invalidEndingOperation();
	string invalidCharacterOperation();

private:

	std::unique_ptr<justNumbersClass> numbers;
	std::unique_ptr<Stack> stack;
	std::unique_ptr<fileAndNumbersVariablesClass> file;
	std::unique_ptr<mixedVariablesClass> mixed;
	std::unique_ptr<userVariablesClass> users;
	std::unique_ptr<InputValidator> validate;

	string expression = "";
	float output = 0;
	bool success = false;
	bool failure = false;
};
#endif // !TDD_H
