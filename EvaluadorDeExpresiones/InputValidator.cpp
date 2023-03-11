#include "InputValidator.h"

InputValidator::InputValidator() : data(nullptr)
{
}

InputValidator::InputValidator(const char* _data)
{
	data = new char[strlen(_data) + 1];
	strcpy_s(data, strlen(_data) + 1, _data);
}

bool InputValidator::validateIfContainsUnary(const char* _data)
{
	return (_data[0] == '-') ? true : false;
}

bool InputValidator::validateExpressíonEnding(const char* _data)
{
	int lastItem = strlen(_data) - 1;
	return (_data[lastItem] == '+' || _data[lastItem] == '-' || _data[lastItem] == '/' || _data[lastItem] == '*' || _data[lastItem] == '(') ? false : true;
}

bool InputValidator::validateMatchingParenthesis(const char* _data)
{
	int open = 0, close = 0;
	for (int i = 0; i < strlen(_data); i++)
	{
		if (_data[i] == '(')
		{
			open++;
		}
		else if (_data[i] == ')') {
			close++;
		}
	}

	return (close == open) ? true : false;
}

bool InputValidator::validateVariablesInFile(const char* _data)
{
	std::ifstream file(this->filePath);
	if (!fs::exists(filePath))
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	
	std::regex pattern("\n|=");
	std::smatch matcher;

	
	std::string line;

	while (getline(file, line)) {
		while (regex_search(line, matcher, pattern)) {

			if (!(std::find(this->fileVariablesId.begin(), fileVariablesId.end(), matcher.prefix().str()) != fileVariablesId.end())) {

				this->fileVariablesId.push_back(matcher.prefix().str());
				line = matcher.suffix().str();
			}
		}
	}


	file.close();

	return (fileVariablesId.size() != 0) ? true : false;
}

bool InputValidator::validateIfHasInvalidCharacters(std::string _data)
{
	
	std::regex pattern("[a-zA-Z0-9()+\\-*/%]+(?!.*[{}\\[\\]])");

	
	if (std::regex_search(_data, pattern))
		return false;
	return true;
}

void InputValidator::iterateFileVariables(std::vector<std::string>)
{
}

bool InputValidator::validateAll(const char* _data)
{
	if (validateIfHasInvalidCharacters(_data) == true || validateIfContainsUnary(_data) ||
		validateMatchingParenthesis(_data) == false || validateExpressíonEnding(_data) == false)
	{
		//expression is not valid
		return false;
	}
}

bool InputValidator::checkIfContainsJustNumbers(const char* _data)
{
	std::regex pattern("\\d+");

	if (std::regex_search(_data, pattern))
		return true;
	return false;
}

bool InputValidator::identifyUserVariables(const char* _data)
{
	for (int i = 0; i < strlen(_data); i++) {
		{
			std::string letters(1, _data[i]);
			if (std::find(foundVariables.begin(), foundVariables.end(), letters) != foundVariables.end()) {
				break;
			}
			else if (std::isalpha(_data[i]) && !(std::find(foundVariables.begin(), foundVariables.end(), letters) != foundVariables.end())) {
				this->foundVariables.push_back(letters);
			}
		}
	}

	if (this->foundVariables.size() != 0)
	{
		this->userVariables = crossReferenceUserVariables(this->fileVariablesId, this->foundVariables);
		if (userVariables.size() != 0)
		{
			return true;
		}
	}
	return false;
}

void InputValidator::convertToVector(const char* _data)
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



std::vector<std::string> InputValidator::crossReferenceUserVariables(std::vector<std::string> fileVar, std::vector<std::string> userVar)
{
	std::vector<std::string> result;
	for (const auto& user : userVar)
	{
		bool found = false;
		for (const auto& file : fileVar)
		{
			if (file == user)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			result.push_back(user);
		}
	}
	return result;
}