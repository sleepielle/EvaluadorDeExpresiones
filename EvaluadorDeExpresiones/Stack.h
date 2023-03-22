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
	Stack(vector<string>, bool);

	void pop();
	std::string& top();
	bool isEmpty();
	int precedence(const std::string& op);
	void evalInfix(vector<string>& stack);
	void evaluatePostfix(vector<string>&);
	void print();
	float answer;

private:

	std::vector<std::string> postfix;
	vector<string> stack;
	float expression = 0,back1 = 0,back2 = 0;
};

#endif
