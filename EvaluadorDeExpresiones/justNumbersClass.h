#pragma once

#ifndef JUSTNUMBERSCLASS_H
#define JUSTNUMBERSCLASS_H
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
#include "Stack.h"

class justNumbersClass
{
public:

	justNumbersClass();
	justNumbersClass(const char*);

	void convertToVector();
	InputValidator* validate = new InputValidator();
	std::vector<std::string> expressionToVector;

private:
	char* expression;
};

#endif // !JUSTNUMBERSCLASS_H
