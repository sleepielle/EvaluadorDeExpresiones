#pragma once
#ifndef STACK_H
#define STACK_H
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <cctype> 
using std::string;
using std::vector;
using std::cout;
using std::endl;
class Stack {
public:
	Stack();
	Stack( vector<string>);

	~Stack();


	void pop();
	std::string& top();
	bool isEmpty();
	int precedence(const std::string& op);
	void evalInfix(vector<string>& stack);
	int evaluatePostfix(vector<string>&);
	double print() ;


private:

	 int symbolsSize;
	 int numbersSize;

	vector<string> stack;
	double answer;
	std::vector<std::string> postfix;
};

#endif
