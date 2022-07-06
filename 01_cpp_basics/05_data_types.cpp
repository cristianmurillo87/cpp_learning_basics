#include <iostream>
#include <climits>

int main()
{
    int x = 5;
    // std::cout << "The value of x is " << x << " and the number of bytes it uses is " << sizeof(x) << " (" << sizeof(x) * 8 << "bits)." << std::endl;

    /* Integer data types */
    // Signed
    short a;
    int b;
    long c;
    long long d;

    // Unsigned
    unsigned short aa;
    unsigned int bb;
    unsigned long cc;
    unsigned long long dd;

    std::cout << "Signed data types" << std::endl;
    std::cout << "The limits for short data type are min: " << SHRT_MIN << " and max: " << SHRT_MAX << std::endl;
    std::cout << "The limits for int(32) data type are min: " << INT32_MIN << " and max: " << INT32_MAX << std::endl;
    std::cout << "The limits for long data type are min: " << LONG_MIN << " and max: " << LONG_MAX << std::endl;
    std::cout << "The limits for long long data type are min: " << LLONG_MIN << " and max: " << LLONG_MAX << std::endl;

    std::cout << "Unsigned data types" << std::endl;
    std::cout << "The limits for short data type are max: " << USHRT_MAX << std::endl;
    std::cout << "The limits for int(32) data type are min: " << UINT32_MAX << std::endl;
    std::cout << "The limits for long data type are min: " << ULONG_MAX << std::endl;
    std::cout << "The limits for long long data type are min: " << ULLONG_MAX << std::endl;

    /* Char data type */
    // Char can store both characters (a single one) and numbers, -128 to 127 (singned char) or 0 to 255 (unsigned char)

    char char_x = 'a';
    std::cout << char_x << std::endl;
    std::cout << "char_x converted to charater is: " << (int)x << std::endl;
    std::cout << "The limits for the char data type are min: " << CHAR_MIN << " and max: " << CHAR_MAX << std::endl;
    std::cout << "The limits for the char data type are min: " << UCHAR_MAX << std::endl;

    /* Boolean data type */

    bool is_good = true;
    bool sky_is_green = false;

    if (sky_is_green)
    {
        std::cout << "The sky is green!" << std::endl;
    }
    else
    {
        std::cout << "The sky is blue, not green!!" << std::endl;
    }

    // when printing a bool variable, std::cout prints either 0 (false) or 1 (true)
    // to change this behavior, use std::boolalpha
    std::cout << "Is the sky green?: " << std::boolalpha << sky_is_green << std::endl;

    /* Floating point data types */

    // The diference between float and double is basically the precision
    // double variables are more precise (can store more decimal digits) and can store larger
    // than float variables
    // WARNING: For high precision applications (e.g financing) search for more precise data types
    float fl = 7.7E-4;
    double dbl;
    double result = fl * 10000000000;
    long double ldbl;

    // prints the variable using scientific notation
    std::cout << result << std::endl;
    // deactivate scientific notation
    std::cout << std::fixed << result << std::endl;

    return 0;
}