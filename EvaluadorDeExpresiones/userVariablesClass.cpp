#include "userVariablesClass.h"
#include <string>
using std::string;
userVariablesClass::userVariablesClass() :expression(nullptr)  //v11
{
}

userVariablesClass::userVariablesClass(std::vector<string> userVariables, const char* _expression)
{
	expression = new char[strlen(_expression) + 1];
	strcpy_s(expression, strlen(_expression) + 1, _expression);

	this->userVariablesId = userVariables;
}

void userVariablesClass::readVariables(const char* _data)
{
	//
}

void userVariablesClass::convertToVector(const char* data)
{
	string myString(data);
	string regex2 = "[\\d.a-zA-Z]+|[-+*/()%^]";
	std::smatch matcher;
	std::regex pattern2(regex2);
	int i = 0;
	int e = 0;

	while (regex_search(myString, matcher, pattern2)) {
		this->expressionToVector.push_back(matcher.str());
		myString = matcher.suffix().str();
	}
}

void userVariablesClass::replaceVariableValues()
{
	int i = 0;
	int e = 0;

	for (const auto& letter : expressionToVector) {
		for (const auto& r : this->userVariablesId) {
			if (letter == r)
			{
				expressionToVector.erase(expressionToVector.begin() + e);
				expressionToVector.insert(expressionToVector.begin() + e, this->userVariablesValue.at(i));
			}
			i++;
		}
		e++;
		i = 0;
	}

	//cout << endl;
	//for (const auto& letter : this->expressionToVector) {
	//	std::cout  << letter << " ";
	//}
}