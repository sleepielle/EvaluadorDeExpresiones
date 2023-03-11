#pragma once

#ifndef TDD_H
#define TDD_H
#include "fileVariablesClass.h"
#include "justNumbersClass.h"
#include "mixedVariablesClass.h"
#include "userVariablesClass.h"
#include "Stack.h"
#include <iostream>
using std::cout; using std::endl;

class TDD
{
public:
	TDD();
	void printScreenSuccess();
	void printScreenFailure();

	void successTestCases();
	void failureTestCases();

private:

	Stack* stack;
	justNumbersClass* numbers;
	fileVariablesClass* file;
	mixedVariablesClass* mixed;
	userVariablesClass* users;
};
#endif // !TDD_H
