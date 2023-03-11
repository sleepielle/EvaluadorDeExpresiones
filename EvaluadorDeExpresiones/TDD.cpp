#include "TDD.h"

void TDD::printScreenSuccess()
{
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "|                    TDD SCREEN                       |" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "|			Test Case: Expression Validator              |" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "| Test             | Expected Result | Actual Result   |" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "| Fibonacci(0)     | 0               | Not Implemented |" << std::endl;
	std::cout << "| Fibonacci(1)     | 1               | Not Implemented |" << std::endl;
	std::cout << "| Fibonacci(2)     | 1               | Not Implemented |" << std::endl;
	std::cout << "| Fibonacci(3)     | 2               | Not Implemented |" << std::endl;
	std::cout << "| Fibonacci(4)     | 3               | Not Implemented |" << std::endl;
	std::cout << "| Fibonacci(5)     | 5               | Not Implemented |" << std::endl;
	std::cout << "| Fibonacci(6)     | 8               | Not Implemented |" << std::endl;
	std::cout << "| Fibonacci(7)     | 13              | Not Implemented |" << std::endl;
	std::cout << "| Fibonacci(8)     | 21              | Not Implemented |" << std::endl;
	std::cout << "| Fibonacci(9)     | 34              | Not Implemented |" << std::endl;
	std::cout << "| Fibonacci(10)    | 55              | Not Implemented |" << std::endl;
	std::cout << "| Fibonacci(-1)    | Exception       | Not Implemented |" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "| Test Case Status:                                   |" << std::endl;
	std::cout << "|   Total Tests: 12                                   |" << std::endl;
	std::cout << "|   Tests Passed: 0                                   |" << std::endl;
	std::cout << "|   Tests Failed: 0                                   |" << std::endl;
	std::cout << "|   Tests Not Implemented: 12                        |" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;




}

void TDD::successTestCases()
{
	
	string expression = "";
	double output = 0;
	bool success = false;
	bool failure = false;


	expression = "10+(1*45)/3";
	this->numbers = new justNumbersClass(expression.c_str());
	 this->stack = new Stack(numbers->expressionToVector);
	
	if (this->stack->print() == 25)
	{
		success = true;
	}

	delete this->stack;
	delete this->numbers;

	expression = "(12+(12-1*3/3))*212";
	this->numbers = new justNumbersClass(expression.c_str());
	this->stack = new Stack(numbers->expressionToVector);

	if (this->stack->print() == 4876)
	{
		success = true;
	}

	delete this->stack;
	delete this->numbers;

	//file test cases
	expression = "pi * (3 + g) - 5 ^ 6 / e + 8";
	this->numbers = new justNumbersClass(expression.c_str());
	this->stack = new Stack(numbers->expressionToVector);

	if (this->stack->print() == 4876)
	{
		success = true;
	}

	delete this->stack;
	delete this->numbers;


}

