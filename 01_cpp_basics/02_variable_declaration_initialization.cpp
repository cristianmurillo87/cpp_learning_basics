#include <iostream>

int main()
{
    int slices = 5;
    std::cout << "You've declared an int with value " << slices << std::endl;
    int old_value = slices;
    slices = 1000;
    std::cout << "The value of slices has been changed from " << old_value << " to " << slices << std::endl;
    return 0;
}