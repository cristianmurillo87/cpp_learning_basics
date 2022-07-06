#include <iostream>

// passing by reference implies no copy of the passed arguments
// are created, but that they are going to be changed in place
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 5;
    int b = 10;

    std::cout << "Value of a: " << a << "\n"
              << "Value of b: " << b << std::endl;

    std::cout << std::endl;

    swap(a, b);

    std::cout << "Value of a: " << a << "\n"
              << "Value of b: " << b << std::endl;

    return 0;
}