#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void swap(T a[], T b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        T temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

int main()
{
    const int SIZE = 5;
    int a = 5;
    int b = 10;

    std::cout << "Value of a: " << a << "\n"
              << "Value of b: " << b << std::endl;

    std::cout << std::endl;

    swap(a, b);

    std::cout << "Value of a: " << a << "\n"
              << "Value of b: " << b << std::endl;

    std::string firstname = "Cristian";
    std::string middlename = "Andres";

    std::cout << "First name: " << firstname << "\n"
              << "Middle name: " << middlename << std::endl;

    swap(firstname, middlename);

    std::cout << "First name: " << firstname << "\n"
              << "Middle name: " << middlename << std::endl;

    int nines[] = {9, 9, 9, 9, 9};
    int ones[] = {1, 1, 1, 1, 1};

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << nines[i] << ones[i] << "\t";
    }
    std::cout << std::endl;

    swap(nines, ones, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << nines[i] << ones[i] << "\t";
    }
    std::cout << std::endl;

    return 0;
}