#include <iostream>
#include <string>

int main()
{
    std::string not_initialized_string;   // "" -> default value
    std::string greeting = "Hello world"; // double quotes

    std::cout << greeting[0] << std::endl;     // can be treated as an array
    std::cout << greeting.size() << std::endl; // same as length()

    std::string name = "Cristian";

    std::cout << greeting + ", " + name << std::endl;

    for (short i = 0; i < greeting.length(); i++)
    {
        std::cout << greeting[i] << std::endl;
    }

    // Insert characters in a string
    greeting.insert(3, " "); //

    // Remove characters
    greeting.erase(3, 5); // Erases 'lo '

    // Remove the last character
    greeting.pop_back();

    // Replacing (from, how many, replacement)
    greeting.replace(3, 4, "****"); // Hel****orld

    std::string phrase = "This is a new phrase";

    // find(search_term) -> returns the index (int) where the search term was found
    greeting.replace(greeting.find("new"), 3, "***"); // This is a *** phrase

    /* C style strings */
    char a_name[] = "Cristian"; // once declared it can only be replaced by a string of exactly the same size
    // a_name = "Andres";  // Error, the new value hast less characters than the original value

    return 0;
}