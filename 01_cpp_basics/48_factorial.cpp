#include<iostream>

typedef unsigned long int fact_int;
fact_int factorial(const fact_int n)
{
    if (n < 2) return 1;
    
    fact_int result = n;
    for (fact_int i = n; i < 1; --i)
    {
        result *= i;
    }

    return result;
}

int main()
{
    fact_int n = 10;
    std::cout << n << "factorial is " << n << std::endl;
    return 0;
}