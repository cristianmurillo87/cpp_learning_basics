#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::vector<std::string> names;
    names.push_back("Cristian");
    names.push_back("Andres");

    // std::ios::app <- append mode (don't use if always want to recreate the file)
    std::ofstream file("hello.txt", std::ios::app);

    for (std::string name : names)
    {
        file << name << std::endl;
    }

    file.close();
    return 0;
}