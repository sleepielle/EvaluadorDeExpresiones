#include "TDD.h"
#include <cassert>
#include <iomanip>


TDD::TDD()
{
	string expression = "";
	float output = 0;
	bool success = false;
	bool failure = false;
}

void TDD::printScreenSuccess()
{

	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "              TDD SUCCESS SCREEN                       " << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "	Test Case: Expression Validator              " << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	string test = std::format(" {:<10}     {:>20} {:>15}", "Test", "Expected Result", "Actual Result");
	cout << test << endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << simpleOperation() << endl;
	std::cout << fileVariablesOperation() << endl;
	std::cout << moduleOperation() << endl;
	std::cout << divisionOperation() << endl;
	std::cout << multipleParenthesis() << endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "| Test Case Status:                                   |" << std::endl;
	std::cout << "|   Total Tests: 5                                    |" << std::endl;
	std::cout << "|   Tests Passed: 5                                   |" << std::endl;
	std::cout << "|   Tests Failed: 0                                   |" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;



}

string TDD::simpleOperation()
{
	expression = "3*4+12";
	file.reset(new fileAndNumbersVariablesClass(expression.c_str()));
	stack.reset(new Stack(file->expressionToVector, true));


	float output = stack->answer;
	assert(output == 20);


	std::string message = std::format(" {:<15}    {:>15}  {:>15} ", expression, 24, output);

	return message;
}

string TDD::moduleOperation()
{

	expression = "50 % 5 * 10";

	file.reset(new fileAndNumbersVariablesClass(expression.c_str()));
	stack.reset(new Stack(file->expressionToVector, true));


	float output = stack->answer;
	assert(output == 0);



	std::string message = std::format(" {:<15}   {:>15}   {:>15} ", expression,0, output);

	return message;
}

string TDD::divisionOperation()
{


	expression = "pi*212/2";
	file.reset(new fileAndNumbersVariablesClass(expression.c_str()));
	stack.reset(new Stack(file->expressionToVector, true));


	float output = stack->answer;
	float expected_output = 333.008759;
	assert(std::abs(output - expected_output) < 0.0001);


	std::string message = std::format(" {:<15}   {:>15}    {:>15} ", expression, 333.008759, output);

	return message;
}



string TDD::fileVariablesOperation()
{
	expression = "pi*(3+g)-5^6/e+8";
	file.reset(new fileAndNumbersVariablesClass(expression.c_str()));
	stack.reset(new Stack(file->expressionToVector, true));


	float output = stack->answer;
	float expected_output = -5699.87646;
	assert(std::abs(output - expected_output) < 0.0001);



	std::string message = std::format(" {:<15}   {:>15}   {:>15} ", expression, -5699.8765, output);

	return message;

}

string TDD::multipleParenthesis()
{

	expression = "(12+(12-1*3/3))*212";
	file.reset(new fileAndNumbersVariablesClass(expression.c_str()));
	stack.reset(new Stack(file->expressionToVector, true));


	float output = stack->answer;
	assert(output == 4876);


	std::string message = std::format(" {:<15}    {:>10}        {:>10} ", expression, 4876, output);

	return message;
}


void TDD::printScreenFailure()
{

	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "              TDD FAILURE SCREEN                       " << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "	Test Case: Expression Validator              " << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	string test = std::format(" {:<10}     {:>20} {:>15}", "Test", "Expected Result", "Actual Result");
	cout << test << endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << unaryOperation() << endl;
	std::cout << mismatchedParenthesisOperation() << endl;
	std::cout << divisionOverZeroOperation() << endl;
	std::cout << invalidEndingOperation() << endl;
	std::cout << invalidCharacterOperation() << endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "| Test Case Status:                                   |" << std::endl;
	std::cout << "|   Total Tests: 5                                    |" << std::endl;
	std::cout << "|   Tests Passed: 0                                   |" << std::endl;
	std::cout << "|   Tests Failed: 5                                   |" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;


}


string TDD::unaryOperation()
{
	/*expression = "3*4+12";
	file.reset(new fileAndNumbersVariablesClass(expression.c_str()));
	stack.reset(new Stack(file->expressionToVector, true));


	float output = stack->answer;
	assert(output == 20);


	std::string message = std::format(" {:<15}    {:>15}  {:>15} ", expression, 24, output);

	return message;*/

	expression = "-20^3*10";
	file.reset(new fileAndNumbersVariablesClass(expression.c_str()));
	stack.reset(new Stack(file->expressionToVector, false));


	float output = stack->answer;
	assert(output == 0);


	std::string message = std::format(" {:<15}   {:>10}    {:>15} ", expression, 0, output);

	return message;
}

string TDD::mismatchedParenthesisOperation()
{
	expression = "30*(34";
	file.reset(new fileAndNumbersVariablesClass(expression.c_str()));
	stack.reset(new Stack(file->expressionToVector, false));


	float output = stack->answer;
	assert(output == 0);


	std::string message = std::format(" {:<15}   {:>10}    {:>15} ", expression, 0, output);

	return message;
}

string TDD::divisionOverZeroOperation()
{
	expression = "40+1/0";
	file.reset(new fileAndNumbersVariablesClass(expression.c_str()));
	stack.reset(new Stack(file->expressionToVector, false));


	float output = stack->answer;
	assert(output == 0);


	std::string message = std::format(" {:<15}   {:>10}    {:>15} ", expression, 0, output);

	return message;
}

string TDD::invalidEndingOperation()
{
	expression = "5^2*1/";
	file.reset(new fileAndNumbersVariablesClass(expression.c_str()));
	stack.reset(new Stack(file->expressionToVector, false));


	float output = stack->answer;
	assert(output == 0);


	std::string message = std::format(" {:<15}   {:>10}    {:>15} ", expression, 0, output);

	return message;
}

string TDD::invalidCharacterOperation()
{
	expression = "4*2/3}";
	file.reset(new fileAndNumbersVariablesClass(expression.c_str()));
	stack.reset(new Stack(file->expressionToVector, false));


	float output = stack->answer;
	assert(output == 0);


	std::string message = std::format(" {:<15}   {:>10}    {:>15} ", expression, 0, output);

	return message;
}


