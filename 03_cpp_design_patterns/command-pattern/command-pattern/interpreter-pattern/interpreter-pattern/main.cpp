//
//  main.cpp
//  interpreter-pattern
//
//  Created by Cristian on 16/04/22.
//

#include <iostream>

class Expression
{
public:
    virtual int evaluate() = 0;
};


// 5 + (10 + 1)
class OperationExpression: public Expression{
    std::string operator_symbol;
    Expression *left_handside;
    Expression *right_handside;
public:
    OperationExpression(const std::string &operator_symbol,
                        Expression *lhs,
                        Expression *rhs)
    : operator_symbol(operator_symbol), left_handside(lhs), right_handside(rhs)
    {};
    
    int evaluate() override
    {
        if (operator_symbol == "+")
        {
            return left_handside->evaluate() + right_handside->evaluate();
        } else if (operator_symbol == "-")
        {
            return left_handside->evaluate() - right_handside->evaluate();
        }
        
        std::cout << "Unrecognized operator: " << operator_symbol << "\n";
        return 0;
    }
};


class NumberExpression: public Expression
{
    std::string number_string;
public:
    NumberExpression(const std::string &number_string)
    : number_string(number_string) {};
    
    int evaluate() override
    {
        // string to int (stoi)
        return std::stoi(number_string);
    }
};


int main(int argc, const char * argv[]) {
    NumberExpression *five = new NumberExpression("5");
    NumberExpression *seven = new NumberExpression("7");
    OperationExpression *five_plus_seven =
        new OperationExpression("+", five, seven);
    
    NumberExpression *thirteen = new NumberExpression("13");
    OperationExpression *complex_op =
    new OperationExpression("-", thirteen, five_plus_seven);
    
    std::cout << "Five plus seven is: " << five_plus_seven->evaluate() << "\n";
    std::cout << "13 - (5 + 7) = " << complex_op->evaluate() << "\n";
    
    delete five;
    delete seven;
    delete five_plus_seven;
    delete thirteen;
    delete complex_op;
    
    return 0;
}
