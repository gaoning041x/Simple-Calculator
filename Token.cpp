#include "Token.h"
#include<cstdlib>
#include<string>
/*dealing with the token, deciding wether it is a number or operator */
Token::Token(string input)
{
    if(input[0]=='*')
    {
        value=0;
        isNumber=false;
        precedence=1;
        myOperator=input.at(0);
    }
    else if(input[0]=='/')
    {
        value=0;
        isNumber=false;
        precedence=1;
        myOperator=input.at(0);
    }
    else if(input[0]=='+')
    {
        value=0;
        isNumber=false;
        precedence=0;
        myOperator=input.at(0);
    }
    else if(input[0]=='-')
    {
        value=0;
        isNumber=false;
        precedence=0;
        myOperator=input.at(0);
    }
    else if(input[0]=='(')
    {
        value=0;
        isNumber=false;
        precedence=2;
        myOperator=input.at(0);
    }
    else if (input[0]==')')
    {
        value=0;
        isNumber=false;
        precedence=-1;
        myOperator=input.at(0);
    }
    else
    {
        value=atof(input.c_str());
        isNumber=true;
        precedence=3;
        myOperator="N";
    }
}
bool Token::getIsNumber()
{
    return isNumber;
}
int Token::getPrecedence()
{
    return precedence;
}
double Token::getValue()
{
    return value;
}
string Token::getMyOperator()
{
    return myOperator;
}
