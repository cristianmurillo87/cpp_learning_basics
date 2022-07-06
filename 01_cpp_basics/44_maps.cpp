#include <iostream>
#include <string>
#include <map>
#include <utility>

/**
 * Maps store elements as key value pairs,
 * duplicated keys are not allowed, but duplicated values might exist
*/
int main()
{
    std::map<int, std::string> map1;
    map1.insert(std::pair<int, std::string>(1, "Bart"));
    map1.insert(std::pair<int, std::string>(2, "Lisa"));
    map1.insert(std::pair<int, std::string>(1, "Marge"));

    auto match = map1.find(1);
    std::cout << match->second << std::endl;

    std::map<int, std::string>::iterator it2;

    for (it2 = map1.begin(); it2 != map1.end(); ++it2)
    {
        std::cout << "Key " << it2->first << std::endl;
        std::cout << "Value " << it2->second << std::endl;
    }

    return 0;
}