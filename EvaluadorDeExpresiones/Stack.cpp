
#include "Stack.h"
#include <iostream>
#include <cctype>
#include <stack>
#include <future>
#include <functional>
#include <type_traits>


 float powerOperation(float back1, float back2)
{
	return pow(back1, back2);
}


Stack::Stack()  {
	stack.resize(0);
}

Stack::Stack( vector<string> _data, bool state) {
	//stack = std::move(_data); //v11 
	stack.resize(size(_data));
	std::swap(stack, _data); // v20
	if  (!state)
	{
		answer = 0;
	}
	else {

		evalInfix(stack);
	}

}

void Stack::print()
{

	cout << answer << endl;

}


void Stack::pop() {
	stack.pop_back();
}

string& Stack::top() {
	return stack.back();
}


int Stack::precedence(const std::string& op) {
	if (op == "^") {
		return 3;
	}
	else if (op == "*" || op == "/" || op == "%" ) {
		return 2;
	}
	else if (op == "+" || op == "-") {
		return 1;
	}
	else {
		return 0;
	}
}

void Stack::evalInfix(std::vector<std::string>& infix) {

	std::stack<std::string> operatorStack;
	std::vector<std::string> postfix;

	for (size_t i = 0; i < infix.size(); i++) {
		const std::string& token = infix[i];

		if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1]) && token[0] == '-')) {
			postfix.push_back(token);
		}
		else if (token == "(") {
			operatorStack.push(token);
		}
		else if (token == ")") {
			while (!operatorStack.empty() && operatorStack.top() != "(") {
				postfix.push_back(operatorStack.top());
				operatorStack.pop();
			}
			if (!operatorStack.empty() && operatorStack.top() == "(") {
				operatorStack.pop();
			}
		}
		else {
			while (!operatorStack.empty() && precedence(token) <= precedence(operatorStack.top())) {
				postfix.push_back(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.push(token);
		}
	}

	while (!operatorStack.empty()) {
		postfix.push_back(operatorStack.top());
		operatorStack.pop();
	}

	evaluatePostfix(postfix);
}





void Stack::evaluatePostfix(vector<string>& infix)
{

	vector<float> postfix;

	for (const auto& token : infix) {  //v11
		try {
		
			if (isdigit(token[0])) {
				postfix.push_back(std::stod(token));
			}
		}
		catch (const std::invalid_argument&) {
			continue;
		}
		catch (const std::out_of_range&) {
			continue;
		}




		if (token == "+") {
			auto async_add = [](float x, float y) -> std::future<float> {
				auto promise = std::promise<float>();
				auto future = promise.get_future();
				promise.set_value(x + y);
				return future;
			};

			float back1 = postfix.back();
			postfix.pop_back();
			float back2 = postfix.back();
			postfix.pop_back();

			auto result = async_add(back2, back1).get();
			postfix.push_back(result);

			//v20
		}

		else if (token=="-") {
			back1 = postfix.back();
			postfix.pop_back();
			back2 = postfix.back();
			postfix.pop_back();
			
			expression = back2 - back1;
			postfix.push_back(expression);
		}

		else if (token == "/") {
			back1 = postfix.back();
			postfix.pop_back();
			back2 = postfix.back();
			postfix.pop_back();
			if (back1 == 0)
			{
				cout << "undefined" << endl;
				answer = 0;
				return;
			}
			expression = back2 / back1;

			postfix.push_back(expression);
		}

		else if (token == "*") {
			back1 = postfix.back();
			postfix.pop_back();
			back2 = postfix.back();
			postfix.pop_back();
			expression = back2 * back1;
			postfix.push_back(expression);
		}
		else if (token == "^") {
		
			back1 = postfix.back();
			postfix.pop_back();
			back2 = postfix.back();
			postfix.pop_back();
			
			postfix.push_back(std::invoke(powerOperation, back2, back1));
		}
		else if (token == "%") {
			back1 = postfix.back();
			postfix.pop_back();
			back2 = postfix.back();
			postfix.pop_back();
			expression = fmod(back2, back1);
			postfix.push_back(expression);
		}
	}

		answer = postfix.back();


}

