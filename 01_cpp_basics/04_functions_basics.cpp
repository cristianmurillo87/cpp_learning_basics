#include <iostream>
#include <cmath>

double power(double base, double exponent)
{
    return pow(base, exponent);
}

void print_power(double base, double exponent)
{
    double result = power(base, exponent);
    double squared_root = sqrt(base);
    std::cout << base << " to the power of " << exponent << " is " << result << std::endl;
    std::cout << ". And its squared root is " << squared_root << std::endl;
}

void use_cmath_functions()
{
    std::cout << remainder(10, 3) << std::endl; // returns 1 -> 10 % 3 = 1
    std::cout << INFINITY << std::endl;         // Infininty
    std::cout << -INFINITY << std::endl;        // Negative Infinity
    std::cout << M_PI << std::endl;             // PI
    std::cout << M_E << std::endl;              // E
    std::cout << ceil(1.5) << std::endl;        // 2
    std::cout << floor(1.5) << std::endl;       // 1
    std::cout << round(9.49) << std::endl;      // 9
    std::cout << trunc(9.8) << std::endl;       // 9
}

int main()
{
    int base, exponent;
    std::cout << "What is the base?: ";
    std::cin >> base;
    std::cout << "What us the exponent?: ";
    std::cin >> exponent;
    print_power(base, exponent);
    use_cmath_functions();
    return 0;
}