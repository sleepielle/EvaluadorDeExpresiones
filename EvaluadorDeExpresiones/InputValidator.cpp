#include "InputValidator.h"


InputValidator::InputValidator() : data(nullptr)
{
}

InputValidator::InputValidator(const char* _data)
{
	data = new char[strlen(_data) + 1];
	strcpy_s(data, strlen(_data) +1, _data);

}

bool InputValidator::validateIfNotUnary(const char* _data)
{
		return (_data[0] != '-') ? true : false;
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

	while (arrayComplete==false)
	{
		while (std::getline(file, line))
		{

			const char* toChar = line.c_str();
			for (int i = 0; i < strlen(_data); i++)
			{


				if (toChar[0] == _data[i]) {
					std::cout << "Variable encontrada fue: " << toChar[0] << std::endl;
					std::string letters(1, toChar[0]);


					this->fileVariables.push_back(letters);
				}
			}
		}

		file.close();

			
			for (const auto& letters : this->fileVariables) {
				std::cout << letters << " ";
			}


			return (fileVariables.size() != 0) ? true : false;


		}

}

std::vector<std::string> InputValidator::identifyUserVariables(const char* _data)
{
	
	for (int i = 0; i < strlen(_data); i++){

				if (std::isalpha(_data[i]) ) {
					std::cout << "Se encuentran letras " << _data[i] << std::endl;
					std::string letter(1, _data[i]);
					this->foundVariables.push_back(letter);
				}
	}

	for (const auto& letter : this->foundVariables) {
		std::cout << letter << " ";
	}


	if (this->foundVariables.size() != 0)
	{
		this->userVariables =	crossReferenceUserVariables(this->fileVariables, this->foundVariables);
		for (const auto& letter : userVariables) {
			std::cout <<"\nDE RESULTADO" << letter << " ";
		}
		return this->userVariables;
	
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


