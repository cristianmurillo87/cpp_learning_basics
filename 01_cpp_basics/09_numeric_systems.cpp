#include <iostream>

void print_integer(const int value)
{
    std::cout << value << std::endl;
}

void print_integet_fmt(const int value)
{
    std::cout << "Decimal: " << std::dec << value << std::endl;
    std::cout << "Hexadecimal: " << std::hex << value << std::endl;
    std::cout << "Octal: " << std::oct << value << std::endl;
}

int main()
{
    int decimal = 30;       // 30
    int hexadecimal = 0x30; // 48
    int octal = 030;        // 24

    print_integer(decimal);
    print_integer(hexadecimal);
    print_integer(octal);

    print_integet_fmt(decimal);

    return 0;
}