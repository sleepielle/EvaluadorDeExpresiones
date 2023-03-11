#include "justNumbersClass.h"

justNumbersClass::justNumbersClass():expression(nullptr)
{

}


justNumbersClass::justNumbersClass(const char* _expression)
{
	expression = new char[strlen(_expression) + 1];
	strcpy_s(expression, strlen(_expression) + 1, _expression);

	convertToVector();
}

void justNumbersClass::convertToVector()
{
	string myString(this->expression);
	string regex2 = "[\\d.a-zA-Z]+|[-+*/()%]";
	std::smatch matcher;
	std::regex pattern2(regex2);
	int i = 0;
	int e = 0;

	while (regex_search(myString, matcher, pattern2)) {
		this->expressionToVector.push_back(matcher.str());
		myString = matcher.suffix().str();
	}

	for (const auto& letter : expressionToVector) {
	std::cout  << letter << " ";
}
}

