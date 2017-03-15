#include "Calculator.h"
#include <stack>
#include <cstdlib>
#include <string>
Calculator::Calculator(const vector<string> & inputEx)
{
	expression=inputEx;
}
void Calculator::process (Token token)
{
	double topValue=valueStack.top();
    valueStack.pop();
    double secValue=valueStack.top();
    valueStack.pop();
    double result;
    if(token.getMyOperator()=="*")
    {
        result=secValue*topValue;
    }
    else if (token.getMyOperator()=="/")
    {
        result=secValue/topValue;
    }
    else if (token.getMyOperator()=="+")
    {
        result=secValue+topValue;
    }
    else
    {
        result=secValue-topValue;
    }
    valueStack.push(result);
}

double Calculator::calculate()
{
	for(int i=0; i<expression.size(); ++i)
	{
		string input=expression[i];
		Token token(input);
        if(token.getIsNumber())
        {
            valueStack.push(token.getValue());
        }
        else
        {
            if(operatorStack.empty())
            {
                operatorStack.push(token);
            }
            else
            {
                if(token.getPrecedence()!=-1)
                {

                    if((operatorStack.top()).getPrecedence()>token.getPrecedence() && (operatorStack.top()).getPrecedence() != 2)
                    {
                        process(operatorStack.top());
                        operatorStack.pop();
                        operatorStack.push(token);
                    }
                    else
                    {
                        operatorStack.push(token);
                    }
                }
                else
                {
                    while((operatorStack.top()).getPrecedence()!=2)
                    {
                        process(operatorStack.top());
                        operatorStack.pop();
                    }
                    operatorStack.pop();
                }
            }
        }
	}
	 while(operatorStack.empty()==false)
    {
        process(operatorStack.top());
        operatorStack.pop();
    }
    return valueStack.top();
}
