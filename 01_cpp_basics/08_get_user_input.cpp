#include <iostream>
#include <string>

int main()
{
    std::string greeting;
    getline(std::cin, greeting);
    std::cout << greeting << std::endl;
    return 0;
}