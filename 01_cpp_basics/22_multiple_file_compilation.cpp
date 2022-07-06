#include <iostream>
#include "22_multiple_compilation/math_utils.h"

// to compile this program, use
// g++ 22_multiple_file_compilation.cpp 22_multiple_compilation/math_utils.cpp
int main()
{
    Rectangle rect;
    rect.width = 5;
    rect.length = 10;

    std::cout << matutils::area(rect) << std::endl;
    std::cout << matutils::area(7.2, 2.4) << std::endl;
    std::cout << matutils::area(7.4) << std::endl;

    std::cout << matutils::pow(5) << std::endl;
    std::cout << matutils::pow(2, 8) << std::endl;

    return 0;
}