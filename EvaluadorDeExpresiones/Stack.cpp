#include "Stack.h"

#include <cctype>
#include <stack>
Stack::Stack()  {
	stack.resize(0);
}

Stack::Stack( vector<string> _data) {
	stack = _data;

	evalInfix(stack);


}

Stack::~Stack() {
	//delete[] this->stackArray;
}

void Stack::pop() {
	stack.pop_back();
}

string& Stack::top() {
	return stack.back();
}

bool Stack::isEmpty() {
	return stack.empty();
}

int Stack::precedence(const std::string& op) {
	if (op == "*" || op == "/") {
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
	
	std::vector<std::string> postfix;
	std::stack<std::string> operatorStack;

	for (const auto& token : stack) {
		if (isdigit(token[0])) {
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

	//for (const auto& letter : postfix) {
	//	std::cout  << letter << " ";
	//}

	evaluatePostfix(postfix);
}



int Stack::evaluatePostfix(vector<string>& infix)
{
	vector<double> postfix;
	double expression = 0;
	double back1 = 0;
	double back2 = 0;

	for (const auto& token : infix) {
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
			back1 = postfix.back();
			postfix.pop_back();
			back2 = postfix.back();
			postfix.pop_back();
			expression = back2 + back1;
		//	cout << expression << endl;
			postfix.push_back(expression);
		}
		else if (token=="-") {
			back1 = postfix.back();
			postfix.pop_back();
			back2 = postfix.back();
			postfix.pop_back();
			expression = back2 - back1;
		//	cout << expression << endl;
			postfix.push_back(expression);
		}
		else if (token == "/") {
			back1 = postfix.back();
			postfix.pop_back();
			back2 = postfix.back();
			postfix.pop_back();
			expression = back2 / back1;
		//	cout << expression << endl;
			postfix.push_back(expression);
		}
		else if (token == "*") {
			back1 = postfix.back();
			postfix.pop_back();
			back2 = postfix.back();
			postfix.pop_back();
			expression = back2 * back1;
			//cout << expression << endl;
			postfix.push_back(expression);
		}
	}

	for (const auto& letter : postfix) {
		cout << letter << "\n"<< endl;
		answer = letter;
		return letter;
	}


}

double Stack::print() 
{
	return this->answer;
}



/*
	//check for numbers
	//for (int i = 0; i < topIndex; i++) {
	//	try {
	//		std::stod(stack[i]);
	//		numbersCounter++;
	//	}
	//	catch (const std::invalid_argument&) {
	//		continue;
	//	}
	//	catch (const std::out_of_range&) {
	//		continue;
	//	}
	//}

	////check for symbols
	//for (int i = 0; i < topIndex; i++)
	//{
	//	for (char c : stackArray[i]) {
	//		if ((ispunct(c)) || c == '-') {
	//			symbolsCounter++;
	//		}
	//	}
	//}

	////initilize
	//for (int i = 0; i < numbersCounter; i++) {
	//    infixArrayNumbers[i] = ""; // default constructor
	//}

	////agregando numeros
	//for (int i = 0; i < numbersCounter; i++) {
	//    try {
	//        double num = std::stod(stack[i]);
	//        std::string number = std::to_string(num);
	//       infixArrayNumbers[numbersCounter] = number;
	//        numbersCounter++;
	//    }
	//    catch (const std::invalid_argument&) {
	//        continue;
	//    }
	//    catch (const std::out_of_range&) {
	//        continue;
	//    }
	//}

	//for (int i = 0; i < numbersCounter; i++) {
	//    cout << infixArrayNumbers[i] << " ";
	//}

	//for (int i = 0; i < topIndex; i++) {
	//    for (char c : stackArray[i]) {
	//        if ((isdigit(c)) || c == '-') {
	//            this->infixArrayNumbers[i] += c;
	//
	//        }

	//        else if (c == '.')
	//        {
	//           this->infixArrayNumbers[i] += c;
	//

	//        }
	//        else {
	//            this->infixArraySymbols[i] += c;
	//

	//        }
	//    }
	//}
	//

	//cout << "FROM INFIX ARRAY" << endl;
	//for (int i = 0; i < topIndex; i++) {
	//    cout << infixArrayNumbers[i] << "\n" << endl;

	//    for (char c : infixArrayNumbers[i]) {
	//        if ((isdigit(c)) || c == '-' || c == '.') {
	//
	//            numbersCounter++;
	//
	//        }
	//    }
	//}

	//    cout << "FROM STACK ARRAY" << endl;
	//    for (int i = 0; i < topIndex; i++) {
	//        for (char c : infixArraySymbols[i]) {
	//            if ((isdigit(c)) || c == '-' || c == '.') {  // check if it is a number or negative sign
	//                // add to infixArray
	//                numbersCounter++;
	//                cout << infixArraySymbols[i] << "\n" << endl;
	//            }
	//        }
	//    }
	//

*/

/*

//for (int i = 0; i < stack.size(); i++) {
//	for (char c : stack[i]) {
//		if (c == '+' || c == '-' || c == '*' || c == '/') {
//			continue;
//		}
//	}
//}

//for (int i = 0; i < stack.size(); i++) {
//	for (char c : stack[i]) {
//		if (c == ')' || c == '(') {
//			auto position = std::find(stack.begin(), stack.end(), stack[i]);
//			stack.erase(position);
//			this->infixArrayNumbers.push_back(stack[i-1]);
//			position = std::find(stack.begin(), stack.end(), stack[i]);
//			stack.erase(position);

//		}
//	}
//}

//for (const auto& letter : this->stack) {
//	std::cout << "\nPOP " << letter << " ";
//}

//int numbersCounter = 0;
////check for numbers
//for (int i = 0; i < this->stack.size(); i++) {
//	try {
//
//		this->infixArrayNumbersDouble.push_back(std::stod(this->stack[i]));
//		this->infixArrayNumbers.push_back(stack[i]);
//	}
//	catch (const std::invalid_argument&) {
//		continue;
//	}
//	catch (const std::out_of_range&) {
//		continue;
//	}
//}

//for (int i = 0; i < this->stack.size(); i++) {
//	{
//		for (char c : stack[i]) {
//			if ((ispunct(c)) && c != '.' || c == '-') {
//
//			}
//		}
//	}
//}

//this->infixArrayJoined.insert(infixArrayJoined.end(), infixArrayNumbers.begin(), infixArrayNumbers.end());
//this->infixArrayJoined.insert(infixArrayJoined.end(), infixArraySymbols.begin(), infixArraySymbols.end());

//for (const auto& letter : this->infixArrayJoined) {
//	std::cout << "\nJOINED " << letter << " ";
//}

/*for (const auto& letter : this->infixArrayNumbers) {
	std::cout << "\nNUMEROS " << letter << " ";
}*/

//int symbolsCounter = 0;
//

//this->infixArraySymbols.erase(std::remove(infixArraySymbols.begin(), infixArraySymbols.end(), "("), infixArraySymbols.end());
//this->infixArraySymbols.erase(std::remove(infixArraySymbols.begin(), infixArraySymbols.end(), ")"), infixArraySymbols.end());


/*

//void Stack::joinInfixArrays(int numbersSize, int symbolsSize)
//{
	/*   string* infixArrayJoined = new string[numbersSize + symbolsSize];
	   for (int i = 0; i < numbersSize; i++)
	   {
		   infixArrayJoined[i] = infixArrayNumbers[i];
	   }
	   for (int i = numbersSize; i < symbolsSize; i++)
	   {
		   infixArrayJoined[i] = infixArraySymbols[i];
	   }

	   cout << "FROM JOINED" << endl;

	   for (int i = 0; i < infixArrayJoined->size(); i++) {
		   cout << infixArrayJoined[i] << " ";
	   }*/
	   //}
