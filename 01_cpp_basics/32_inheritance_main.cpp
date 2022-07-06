#include <iostream>
#include "31_multfile_class_declaration.h"
#include "32_inheritance.h"

// compile all *.cpp  files using:
//  g++ 31_multifile_class_declaration_main.cpp 31_multfile_class_declaration.cpp 32_inheritance.cpp -std=c++11
int main()
{
    User user;
    std::cin >> user;
    std::cout << user << std::endl;

    Teacher teacher;
    teacher.output();
    return 0;
}