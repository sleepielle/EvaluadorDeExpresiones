#include "InputValidator.h"


InputValidator::InputValidator() : data(nullptr)
{
}

InputValidator::InputValidator(const char* _data)
{
	data = new char[strlen(_data) + 1];
	strcpy_s(data, strlen(_data) +1, _data);

}

bool InputValidator::validateIfContainsUnary(const char* _data)
{
		return (_data[0] == '-') ? true : false;
}

bool InputValidator::validateExpressíonEnding(const char* _data)
{
	int lastItem = strlen(_data)-1;
	return (_data[lastItem] == '+' || _data[lastItem] == '-' || _data[lastItem] == '/' || _data[lastItem] == '*' ||  _data[lastItem] == '(') ? false : true;


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


	if (!fs::exists(filePath))
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	std::ifstream file(this->filePath);
	std::string line;
	bool arrayComplete = false;


		while (std::getline(file, line))
		{

			const char* toChar = line.c_str();
			for (int i = 0; i < strlen(_data); i++)
			{
				

				std::string letters(1, toChar[0]);
				if (toChar[0] == _data[i] && std::find(fileVariables.begin(), fileVariables.end(),letters ) != fileVariables.end()) {
					break;
				}
				else if(toChar[0]==_data[i]) {
						this->fileVariables.push_back(letters);
				}
			}
		}


		file.close();

		

			return (fileVariables.size() != 0) ? true : false;


}

bool InputValidator::validateIfHasInvalidCharacters(std::string _data)
{

	// Regular expression pattern to match alphanumeric, parenthesis, and arithmetic operators
	std::regex pattern("[a-zA-Z0-9()+\\-*/%]+(?!.*[{}\\[\\]])");

	// Check if the string contains any characters that don't match the pattern
	if (std::regex_search(_data, pattern)) 
		return false;
	return true;
	
}

void InputValidator::iterateFileVariables(std::vector<std::string>)
{

}

bool InputValidator::validateAll(const char* _data)
{

	if (validateIfHasInvalidCharacters(_data) == true|| validateIfContainsUnary(_data) ||
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
		this->userVariables = crossReferenceUserVariables(this->fileVariables, this->foundVariables);
		return true;
	}
	return false;
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


