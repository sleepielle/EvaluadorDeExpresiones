#include "fileAndNumbersVariablesClass.h"
#include <string>
using std::string;

fileAndNumbersVariablesClass::fileAndNumbersVariablesClass() :expression(nullptr)
{
}

fileAndNumbersVariablesClass::fileAndNumbersVariablesClass(const char* _expression)
{
	expression = new char[strlen(_expression) + 1];
	strcpy_s(expression, strlen(_expression) + 1, _expression);

	readVariables(expression);
	convertToVector(expression);
	replaceVariableValues();

	delete[] expression; // v14
}
void fileAndNumbersVariablesClass::readVariables(const char* data)
{
	std::ifstream file(this->filePath);
	std::string line;
	std::string identifier;
	std::string value;
	std::string myString(data);

	std::regex pattern("\n|=");
	std::smatch matcher;

	while (getline(file, line)) {
		while (regex_search(line, matcher, pattern)) {
			if (!(std::find(this->fileVariablesId.begin(), fileVariablesId.end(), matcher.prefix().str()) != fileVariablesId.end())) {
				this->fileVariablesId.push_back(matcher.prefix().str());
			}

			line = matcher.suffix().str();

			std::string line2 = matcher.prefix().str() + matcher.str() + matcher.suffix().str();
			this->fileVariablesValue.push_back(line2);
			line = matcher.prefix().str();
		}
	}
}

void fileAndNumbersVariablesClass::convertToVector(const char* data)
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

void fileAndNumbersVariablesClass::replaceVariableValues()
{
	int i = 0;
	int e = 0;

	auto size = std::ssize(fileVariablesId); //v20

	for (const auto& letter : expressionToVector) {
		for (int i = 0; i < size; i++)
		{
			if (letter == fileVariablesId[i])
			{
				expressionToVector.erase(expressionToVector.begin() + e);

				expressionToVector.insert(expressionToVector.begin() + e, this->fileVariablesValue.at(i));
			}
		}
		e++;
		i = 0;
	}
}

bool fileAndNumbersVariablesClass::identifyFileVariables(const char*)
{
	for (int i = 0; i < std::size(fileVariablesId); i++) // v17
	{
		if (!(std::find(this->expressionToVector.begin(), expressionToVector.end(), fileVariablesId[i]) != expressionToVector.end())) {
			return false;
		}
	}
	return true;
}