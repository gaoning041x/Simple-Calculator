#include"Token.h"
#include "Calculator.h"
#include <vector>
#include <string>
#include<iostream>
using namespace std;
int main()
{
    vector<string> inputEx;
    string input;
    while(cin>>input)
    {
        inputEx.push_back(input);
    }
    Calculator calculator(inputEx);
    cout<<"the result is: "<<calculator.calculate()<<"\n";
    return 0;
}
