#include "fileVariablesClass.h"


using namespace std;
#include <ranges>
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


	//20 features
}

void fileVariablesClass::replaceVariableValues()
{
	/*int i = 0;
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
	}*/

	int i = 1;
	for (const auto& str : this->fileVariablesId) {
		std::string key = "key" + std::to_string(i);
		fileVariables.insert({ key, str });
		i++;
	}

	for (size_t i = 0; i < fileVariablesValue.size(); i++) {
		const auto& value = fileVariablesValue[i];
		for (auto& str : expressionToVector) {
			for (const auto& [r, _value] : fileVariables) {
			//structured binding v17
				size_t pos = str.find(_value);
				if (pos != std::string::npos) {
					str.replace(pos, r.length(), value);
				}
			}
		}
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
