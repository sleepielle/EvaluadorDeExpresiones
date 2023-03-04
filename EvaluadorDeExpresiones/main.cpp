#include <conio.h>
#include <iostream>
#include <chrono>
#include <cstdlib> 
#include "InputValidator.h"
#include <string>
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
	validation testingCases= validation::invalid;
	string expression = "";
	InputValidator validate;
	bool containsUnary = false;
	bool express = false;
	bool ending = false;
	bool contains = false;
	bool userVars = false;
	int option = 0;




	do
	{
		cout << "*** MENU ***" << endl;
		cout << "1. Evaluar expresión.\n2. Mostrar TDD\n3. Salir\n";
		cin >> option;
		cout << endl;

	
		switch (option)
		{
		case 1:
		
			system("cls");

			

			cout << "Ingrese expresion." << endl;
			cin >> expression;


			testingCases = (validate.validateAll(expression.c_str())) ? validation::valid : validation::invalid;
			if (testingCases==validation::valid)
			{
				testingCases = (validate.identifyUserVariables(expression.c_str())) ? validation::userVariables : validation::valid;
				testingCases = (validate.validateVariablesInFile(expression.c_str())) ? validation::fileVariables : validation::valid;
				testingCases = (validate.validateVariablesInFile(expression.c_str()) && validate.identifyUserVariables(expression.c_str()))
					? validation::mixedVariables : validation::valid;

				testingCases = validate.checkIfContainsJustNumbers(expression.c_str()) ? validation::justNumbers : validation::valid;

			}
			else {
				cout << "Ingrese nueva expresion" << endl;
				break;
			}

		

			switch ( testingCases) {
			case validation::fileVariables:
				break;
			case validation::justNumbers:
				cout << expression << endl;
				break;
			case validation::mixedVariables:
				break;
			case validation::userVariables:
				break;
			}


			for (const auto& letter : validate.fileVariables) {
				std::cout << "\Variables de archivo " << letter << " ";
			}


			cout << endl;
			for (const auto& letter : validate.userVariables) {
				std::cout << "Variables de usuario " << letter << " ";
			}



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
