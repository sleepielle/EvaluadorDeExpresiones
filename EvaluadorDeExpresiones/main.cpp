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

int main()
{

	string expression = "";
	InputValidator validate;
	bool isValid = false;
	bool express = false;
	bool ending = false;
	bool contains = false;
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
			isValid = validate.validateIfNotUnary(expression.c_str());
			express = validate.validateMatchingParenthesis(expression.c_str());
			ending = validate.validateExpressíonEnding(expression.c_str());
			contains = validate.validateVariablesInFile(expression.c_str());


			cout << (isValid ?  "No contiene el unario" :  " Si Contiene unario")<<endl;
			cout << (express ? "Si cierra" : "No  cierra") << endl;
			cout << (ending ? "No  Termina con operadores" : "Si termina con operadores") << endl;
			

			if (contains)
			{
				validate.identifyUserVariables(expression.c_str());
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
