#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::vector<std::string> names;
    std::ifstream file("hello.txt");

    std::string input;

    // check if the file exists
    if (file.is_open())
    {
        while (file >> input)
        {
            names.push_back(input);
        }
    }

    for (std::string name : names)
    {
        std::cout << name << std::endl;
    }

    return 0;
}