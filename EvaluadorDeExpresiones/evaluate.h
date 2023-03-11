#pragma once
#ifndef  EVALUATEEXPRESSION_H
#define EVALUATEEXPRESSION_H

class evaluate
{
public:
	virtual void readExpression(const char*)=0;
	virtual void evaluateExpression(const char*)=0;
	virtual void saveToFile()=0;


};


#endif // ! EVALUATEEXPRESSION_H




