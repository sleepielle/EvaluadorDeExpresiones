#include "fileVariablesClass.h"
#include <string>
using std::string;

fileVariablesClass::fileVariablesClass() :expression(nullptr)
{
}

fileVariablesClass::fileVariablesClass(const char* _expression)
{
	expression = new char[strlen(_expression) + 1];
	strcpy_s(expression, strlen(_expression) + 1, _expression);


	readVariables(expression);
	convertToVector(expression);
	replaceVariableValues();
}

void fileVariablesClass::readVariables(const char* data)
{
	std::ifstream file(this->filePath);
	std::string_view myString(data);

	std::vector<std::string_view> fileVariablesId;
	std::vector<std::string_view> fileVariablesValue;

	auto lines = std::ranges::views::split(myString, '\n');
	for (auto line : lines) {
		auto [key, val] = std::ranges::views::split(line, '=');
		auto identifier = std::string_view(key.begin(), std::distance(key.begin(), key.end()));
		auto value = std::string_view(val.begin(), std::distance(val.begin(), val.end()));

		if (std::ranges::find(fileVariablesId, identifier) == fileVariablesId.end()) {
			fileVariablesId.push_back(identifier);
		}

		fileVariablesValue.push_back(identifier.data());
		fileVariablesValue.push_back("=");
		fileVariablesValue.push_back(value.data());
		fileVariablesValue.push_back("\n");
	}

	this->fileVariablesId = std::move(fileVariablesId);
	this->fileVariablesValue = std::move(fileVariablesValue);
}


void fileVariablesClass::convertToVector(const char* data)
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
void fileVariablesClass::replaceVariableValues()
{
	int i = 0;
	int e = 0;

	for (const auto& letter : expressionToVector) {
		for (const auto& r : this->fileVariablesId) {
			if (letter == r)
			{
				expressionToVector.erase(expressionToVector.begin() + e);
				expressionToVector.insert(expressionToVector.begin() + e, this->fileVariablesValue.at(i));
			}
			i++;
		}
		e++;
		i = 0;
	}
}
//
//int fileVariables::setNumbersArraySize()
//{
//	int numbersCounter = 0;
//	//check for numbers
//	for (int i = 0; i < this->expressionToVector.size(); i++) {
//		try {
//			std::stod(this->expressionToVector[i]);
//			numbersCounter++;
//		}
//		catch (const std::invalid_argument&) {
//			continue;
//		}
//		catch (const std::out_of_range&) {
//			continue;
//		}
//	}
//
//	return numbersCounter;
//}
//int fileVariables::setSymbolslArraySize()
//{
//	int symbolsCounter = 0;
//	for (int i = 0; i < this->expressionToVector.size(); i++) {
//		{
//			for (char c : expressionToVector[i]) {
//				if ((ispunct(c)) && c != '.' || c == '-') {
//					symbolsCounter++;
//				}
//			}
//		}
//	}
//	return symbolsCounter;
//};
//
