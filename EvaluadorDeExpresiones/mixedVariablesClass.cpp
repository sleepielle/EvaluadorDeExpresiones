#include "mixedVariablesClass.h"

#include "fileVariablesClass.h"
#include <string>
using std::string;

mixedVariablesClass::mixedVariablesClass() :expression(nullptr)
{
}

mixedVariablesClass::mixedVariablesClass(std::vector<string> _fileVariablesId, std::vector<string> _fileVariablesValues,
	std::vector<string> _userVariablesId, std::vector<string> _userVariablesValues, const char* _expression)
{
	expression = new char[strlen(_expression) + 1];
	strcpy_s(expression, strlen(_expression) + 1, _expression);

	this->fileVariablesId = _fileVariablesId;
	this->fileVariablesValues = _fileVariablesValues;
	this->userVariablesId = _userVariablesId;
	this->userVariablesValues = _userVariablesValues;

	//readVariables(expression);
	convertToVector(expression);
	replaceVariableValues();
}

void mixedVariablesClass::readVariables(const char* data)
{
	cout << endl;
}

void mixedVariablesClass::convertToVector(const char* data)
{
	string myString(data);
	string regex2 = "[\\d.a-zA-Z]+|[-+*/()]";
	std::smatch matcher;
	std::regex pattern2(regex2);
	int i = 0;
	int e = 0;

	while (regex_search(myString, matcher, pattern2)) {
		this->expressionToVector.push_back(matcher.str());
		myString = matcher.suffix().str();
	}
}
void mixedVariablesClass::replaceVariableValues()
{
	int i = 0;
	int e = 0;

	for (const auto& letter : expressionToVector) {
		for (const auto& r : this->fileVariablesId) {
			if (letter == r)
			{
				expressionToVector.erase(expressionToVector.begin() + e);
				expressionToVector.insert(expressionToVector.begin() + e, this->fileVariablesValues.at(i));
			}

			i++;
		}
		e++;
		i = 0;
	}
	e = 0; i = 0;
	for (const auto& letter : expressionToVector) {
		for (const auto& r : this->userVariablesId) {
			if (letter == r)
			{
				expressionToVector.erase(expressionToVector.begin() + e);
				expressionToVector.insert(expressionToVector.begin() + e, this->userVariablesValues.at(i));
			}

			i++;
		}
		e++;
		i = 0;
	}
}

	