#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>


bool is_palindrome(const std::string &word)
{
	std::deque<char> word_ordered;
	std::deque<char> word_reversed;
	
	for(int i = 0; i < word.length(); ++i)
	{
		if(isalpha(word[i]))
		{
			word_ordered.push_back(std::toupper(word[i]));
			word_reversed.push_front(std::toupper(word[i]));
		}
	}
	
	for(int i = 0; i < word_ordered.size(); i++)
	{
		if(word_ordered.at(i) != word_reversed.at(i))
			return false;
	}
	return true;
}


int main()
{
	std::vector<std::string> words {"abuyta", "aba", "madam", "C++", "aca", "football"};
	
	std::cout << std::boolalpha;
	std::cout << "Is Palindrome? String" << std::endl;
	for(auto word : words)
		std::cout << is_palindrome(word) << " " << word << std::endl;
	
	return 0;
}