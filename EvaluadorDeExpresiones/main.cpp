#include <conio.h>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include "InputValidator.h"
#include "InputType.h"
#include "fileVariablesClass.h"
#include <string>
#include "Stack.h"
#include "justNumbersClass.h"
#include "userVariablesClass.h"
#include "mixedVariablesClass.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;

enum validation {
	userVariables,
	fileVariables,
	mixedVariables,
	justNumbers,
	invalid,
	valid
};

int main()
{
	//variables
	vector<string> stack;
	string expression = "";
	string value = "";
	int option = 0;
	double answer = 0;

	//clases
	validation testingCases = validation::invalid;

	InputValidator validate;
	fileVariablesClass* files;
	justNumbersClass* numbers;
	userVariablesClass* users;
	mixedVariablesClass* mixed;
	Stack* s;

	do
	{
		cout << "*** MENU ***" << endl;
		cout << "1. Evaluar expresión.\n2. Mostrar TDD\n3. Salir\n";
		cin >> option;
		cout << endl;

		switch (option)
		{
		case 1:

			cout << "Ingrese expresion." << endl;
			cin.ignore();
			getline(cin, expression);

			//generic lambda
			expression.erase(std::remove_if(expression.begin(), expression.end(),
				[](char& c) {
					return std::isspace<char>(c, std::locale::classic());
				}),
				expression.end());

			testingCases = (validate.validateAll(expression.c_str())) ? validation::valid : validation::invalid;
			if (testingCases == validation::valid)
			{
				testingCases = (validate.validateVariablesInFile(expression.c_str())==true) ? validation::fileVariables : validation::valid;
				

				if (validate.identifyUserVariables(expression.c_str()) && testingCases == validation::fileVariables)
				{
					testingCases = validation::mixedVariables;
				}
				else if (validate.identifyUserVariables(expression.c_str()) && testingCases == validation::valid) {
					testingCases = validation::userVariables;
				}
				 if (testingCases == validation::valid) {
					testingCases = validation::justNumbers;
				}
			}
			else {
				cout << "Ingrese nueva expresion" << endl;
				break;
			}

			switch (testingCases) {
			case validation::fileVariables:

				files = new fileVariablesClass(expression.c_str());
				s = new Stack(files->expressionToVector);

				break;
			case validation::justNumbers:

				numbers = new justNumbersClass(expression.c_str());
				s = new Stack(numbers->expressionToVector);

				break;
			case validation::userVariables:
				users = new userVariablesClass(validate.userVariables, expression.c_str());

				for (int i = 0; i < validate.userVariables.size(); i++) {
					std::cout << validate.userVariables[i] << " : ";
					std::cin >> value;
					users->userVariablesValue.push_back(value);
				}

				users->readVariables(expression.c_str());
				users->convertToVector(expression.c_str());
				users->replaceVariableValues();
				s = new Stack(users->expressionToVector);

				break;
			case validation::mixedVariables:
				files = new fileVariablesClass(expression.c_str());
				users = new userVariablesClass(validate.userVariables, expression.c_str());
				for (int i = 0; i < validate.userVariables.size(); i++) {
					std::cout << validate.userVariables[i] << " : ";
					std::cin >> value;
					users->userVariablesValue.push_back(value);
				}

				mixed = new mixedVariablesClass(files->fileVariablesId,files->fileVariablesValue,users->userVariablesId,users->userVariablesValue, expression.c_str());
				s = new Stack(mixed->expressionToVector);
			
				break;
			}

			// !! TODO: FIX PI VALUE WHEN READ FROM FILE.

			//for (const auto& letter : validate.fileVariablesId) {
			//	std::cout << "Variables de archivo " << letter << " ";
			//}

			//cout << endl;
	/*		for (const auto& letter : validate.userVariables) {
				std::cout << "Variables de usuario " << letter << " ";
			}*/

			break;
		case 2:
			system("cls");
			cout << "Mostrando TDD." << endl;

			cin >> option;
			break;
		case 3:

			cout << "Saliendo ..." << endl;

			break;
		default:
			break;
		}
	} while (option != 3);
	_getch();

	return 0;
}

//cout << (containsUnary ?  " contiene el unario" :  " no Contiene unario")<<endl;
	//		cout << (express ? "Si cierra" : "No  cierra") << endl;
	//		cout << (ending ? "No  Termina con operadores" : "Si termina con operadores") << endl;
		//	cout << (userVars ? "Tiene variables de usuario" : "No tiene") << endl;