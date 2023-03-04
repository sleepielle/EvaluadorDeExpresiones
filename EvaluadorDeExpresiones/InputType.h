#pragma once
#ifndef INPUTTYPE_H
#define INPUTTYPE_H



class InputType
{
public:
	virtual void printExpression(const char*) = 0;
	virtual void evaluateExpression(const char*) = 0;

};

#endif // !INPUTTYPE_H