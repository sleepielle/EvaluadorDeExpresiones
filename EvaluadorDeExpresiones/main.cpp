#include <conio.h>
#include <iostream>
#include <chrono>
#include <optional>
#include <algorithm>
#include <memory>
#include <cstdlib>
#include "InputValidator.h"
#include "InputType.h"
#include "fileAndNumbersVariablesClass.h"
#include <string>
#include "Stack.h"
#include "TDD.h"
#include "justNumbersClass.h"
#include "userVariablesClass.h"
#include "mixedVariablesClass.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;

enum validation { //v11
	userVariables,
	fileVariables,
	mixedVariables,
	justNumbers,
	invalid,
	valid
};


string expression = "";
validation testingCases = validation::invalid;
float answer = 0;

InputValidator validate;

void expressionInput() {


	//std::string message = std::format("The answer is {}.", 42);
	//cout << message << endl;
		cout << "Ingrese expresion." << endl;
		cin.ignore();
		getline(cin, expression);

		//generic lambda v14
		expression.erase(std::remove_if(expression.begin(), expression.end(),
			[](auto& c) {
				return std::isspace(c, std::locale::classic());
			}),
			expression.end());


}

void validations() {
	std::optional<bool> allValid = validate.validateAll(expression.c_str());
	if (allValid.has_value() && allValid.value())
	{
		std::optional<bool> varsInFile = validate.validateVariablesInFile(expression.c_str()); //v17
		if (varsInFile.has_value() && varsInFile.value())
		{
			if (validate.identifyUserVariables(expression.c_str()))
			{
				testingCases = validation::mixedVariables;
			}
			else
			{
				testingCases = validation::fileVariables;
			}
		}
		else
		{
			if (validate.identifyUserVariables(expression.c_str())) {
				testingCases = validation::userVariables;
			}
			else {
				testingCases = validation::justNumbers;
			}
		}
	}
	else
	{
		testingCases = validation::invalid;
	}
}

int main()
{
	

	string value = "";
	int option = 0;
	int tddOption = 0;
	std::unique_ptr<justNumbersClass> numbers;
	std::unique_ptr<mixedVariablesClass> mixed;
	std::unique_ptr<Stack> s;
	std::unique_ptr<TDD> tdd;

	std::shared_ptr<fileAndNumbersVariablesClass> files;
	std::shared_ptr<userVariablesClass> users;

	do
	{


		option = 0;
		cout << "*** MENU ***" << endl;
		cout << "1. Evaluar expresión.\n2. Mostrar TDD\n3. Salir\n";
		cin >> option;
		cout << endl;

		switch (option)
		{
		case 1:

			expressionInput();
			validations();

			files = std::make_shared<fileAndNumbersVariablesClass>(expression.c_str());   //v20
			users = std::make_shared<userVariablesClass>(validate.userVariables, expression.c_str());

			switch (testingCases) {

				case validation::fileVariables:

					s.reset(new Stack(files->expressionToVector, true));
					s->print();
					break;
				case validation::justNumbers:

					numbers.reset(new justNumbersClass(expression.c_str()));
					s.reset(new Stack(numbers->expressionToVector, true));
					s->print();
					break;
				case validation::userVariables:
					for (int i = 0; i < validate.userVariables.size(); i++) {
						std::cout << validate.userVariables[i] << " : ";
						std::cin >> value;
						users->userVariablesValue.push_back(value);
					}

					users->readVariables(expression.c_str());
					users->convertToVector(expression.c_str());
					users->replaceVariableValues();
					s.reset(new Stack(users->expressionToVector, true));
					s->print();

					break;
				case validation::mixedVariables:


					for (int i = 0; i < validate.userVariables.size(); i++) {
						std::cout << validate.userVariables[i] << " : ";
						std::cin >> value;
						users->userVariablesValue.push_back(value);
					}

					mixed = std::make_unique<mixedVariablesClass>(files->fileVariablesId, files->fileVariablesValue,   //v14
						users->userVariablesId, users->userVariablesValue, expression.c_str());

					s.reset(new Stack(mixed->expressionToVector, true));
					s->print();

					break;
				case validation::invalid:

					numbers.reset(new justNumbersClass(expression.c_str()));
					s.reset(new Stack(numbers->expressionToVector, false));
					s->print();
					break;
				}
			break;
			case 2:
				cout << "Mostrando TDD.\n1.Success TDD\n2.Failure TDD" << endl;
				cin >> tddOption;
				tdd.reset(new TDD());
				switch (tddOption)
				{
				case 1:

					tdd->printScreenSuccess();
					break;
				case 2:

					tdd->printScreenFailure();
					break;
				default:
					break;
				}
				
				
				break;

			case 3:
				return 0;
				break;

			default:
				std::cout << "Expresión inválida. Ingrese una nueva expresión." << std::endl;
				break; // Continúa con la siguiente iteración del ciclo

		}

		

	} while (option != 3);

	
	_getch();

	return 0;
}

