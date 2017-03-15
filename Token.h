#ifndef TOKEN_H
#define TOKEN_H
#include<string>
using namespace std;
class Token
{
    private:
        double value;
        int precedence;
        bool isNumber;
        string myOperator;
    public:
        Token(string input);
        bool getIsNumber();
        double getValue();
        int getPrecedence();
        string getMyOperator();
};

#endif // TOKEN_H
