#include <iostream>
#include<stack>
#include<cstdlib>
#include "Token.h"

using namespace std;

void process(stack<double> & valueStack, Token token)
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
int main()
{
    stack<double>valueStack;
    stack<Token>operatorStack;
    string input;
    //cout<<"Please input the expression.\n";
    while(cin>>input)
    {
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
                        process(valueStack, operatorStack.top());
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
                        process(valueStack, operatorStack.top());
                        operatorStack.pop();
                    }
                    operatorStack.pop();
                }
            }
        }
    }
    while(operatorStack.empty()==false)
    {
        process(valueStack, operatorStack.top());
        operatorStack.pop();
    }
    cout<<"The result is: "<<valueStack.top()<<endl;
    return 0;
}
