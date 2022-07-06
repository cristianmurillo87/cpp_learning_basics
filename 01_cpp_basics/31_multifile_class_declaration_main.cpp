#include <iostream>
#include <string>
#include "31_multfile_class_declaration.h"

// compile all *.cpp  files using:
//  g++ 31_multifile_class_declaration_main.cpp 31_multfile_class_declaration.cpp -std=c++11
int main()
{
    User user1("Cristian", "Murillo", "Gold");
    std::cout << user1 << std::endl;

    User user2("", "", "Golden");
    std::cin >> user2;
    std::cout << user2 << std::endl;

    std::cout << User::get_user_count() << std::endl;

    return 0;
}