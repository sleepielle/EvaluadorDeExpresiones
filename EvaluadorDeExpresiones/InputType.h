#pragma once
#ifndef INPUTTYPE_H
#define INPUTTYPE_H
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;

class InputType
{
public:

	//virtual void readExpression(const char*) = 0;
//	virtual void evaluateInfix(const char*) = 0;
	//virtual void evaluatePostFix(const char*) = 0;
	//virtual void printExpression(int) = 0;
	virtual void convertToVector(const char*) = 0;
	virtual void readVariables(const char*) = 0;
	virtual void replaceVariableValues() = 0;
};

#endif // !INPUTTYPE_H