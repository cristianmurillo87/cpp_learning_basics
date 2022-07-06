#include <iostream>
#include <regex>
#include <string>

void print_matches(std::string str, std::regex reg)
{
    std::smatch matches;
    std::cout << std::boolalpha;

    while (std::regex_search(str, matches, reg))
    {
        std::cout << "Is there a match: " << matches.ready() << std::endl;
        std::cout << "Are there no matches: " << matches.empty() << std::endl;
        std::cout << "Number of matches: " << matches.size() << std::endl;
        std::cout << matches.str(1) << std::endl;
        str = matches.suffix().str();
        std::cout << str << std::endl;
        std::cout << std::endl;
    }
}

void print_matches_with_iterator(std::string str, std::regex reg)
{
    std::sregex_iterator current_match(str.begin(), str.end(), reg);
    std::sregex_iterator last_match;

    while (current_match != last_match)
    {
        std::smatch match = *current_match;
        std::cout << match.str() << std::endl;
        current_match++;
    }
    std::cout << std::endl;
}

int main()
{
    std::string str = "The ape was at the apex";
    // search for anything that has a "ape" that might or not be followed by an space
    std::regex reg("(ape)[^ ]?");

    print_matches(str, reg);

    std::string str2 = "I picked the pickle";
    // matches everythin that has pick followed by any character or none
    std::regex reg2("(pick([^ ]+)?)");
    print_matches_with_iterator(str2, reg2);

    // Specific individual characters
    // Cat is not printed since there are no uppercases in the expression
    std::string str3 = "Cat mat rat fat pat";
    std::regex reg3("([cmrfp]at)");
    print_matches_with_iterator(str3, reg3);

    // string ranges
    std::regex reg4("([C-Fc-f]at)");
    print_matches_with_iterator(str3, reg4);

    // excluding characters
    std::regex reg5("([^Cr]at)");
    print_matches_with_iterator(str3, reg4);

    // replace matches
    std::regex reg6("([Cr]at)");
    std::string owl_food = std::regex_replace(str3, reg6, "Owl");
    std::cout << owl_food << std::endl;

    // match dots
    std::string str7 = "F.B.I. I.R.S. CIA";
    std::regex reg7("([^ ]\..\..\.)");
    print_matches(str7, reg7);

    return 0;
}