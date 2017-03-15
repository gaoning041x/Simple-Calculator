#ifndef CALCULATOR_H
#define CALCULATOR_H


#include <stack>
#include <vector>
#include <string>
#include "Token.h"
using namespace std;
class Calculator
{
	private:
		vector<string> expression;
		stack<double> valueStack;
		stack<Token> operatorStack;
		void process(Token token);
	public:
		Calculator( const vector<string> & inputEx);
		double calculate();
};

#endif // CALCULATOR_H
