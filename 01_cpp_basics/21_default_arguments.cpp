#include <iostream>

double pow(double base, int pow = 2)
{
    int total = 1;
    for (int i = 0; i < pow; i++)
    {
        total *= base;
    }

    return total;
}

int main()
{
    std::cout << pow(2, 8) << std::endl;
    return 0;
}