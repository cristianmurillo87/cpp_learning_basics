#include <iostream>

// Macros - C format for declaring constants (not recommended for C++)
#define X 10

// MONDAY = 0, TUESDAY = 1, ...etc
enum Weekday
{
    MONDAY = 0,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

int main()
{
    // the const keyword forbids a variable from being modified
    const int value = 5;

    // value = 6; Error (value cannot be changed)

    Weekday today = TUESDAY;

    // auto is a C++ 11 feature to use it use the c++11 flag for compilation
    auto x = 5U; // U -> assignes x the data type unsigned int

    return 0;
}