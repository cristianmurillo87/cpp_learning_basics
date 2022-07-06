#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


int count_words(std::string line)
{
	int start_pos{0}; // starting index to search for words
	int length{1}; // how many characters after start_pos will be useg for subtringing
	int num_words{0}; // total number of words
	
	if(line.size() == 0)
		return 0; // if the line is an empty string then return zero
	else
		++num_words; // Because the last word is never counted
	
	while((start_pos + length) <= line.size()) // the count will be performed as long as the size of the line has not been reached
	{
		std::string word = line.substr(start_pos, length); // substring length characters of line starting from start_pos
		char last_character = word.at(word.size() - 1); // Last character of the word
		
		// if the last character is either a space or a new line or a end of string
		// a word was found
		if(last_character == ' ' || last_character == '\n' || last_character == '\0')
		{
			// in that case, the counter of words will be increased
			++num_words;
			// the new starting position will be the last position plus one where one of the above characters was found
			start_pos += length;
			// and the length will be reseted
			length = 1;
		}
		// if the substring is not a word, then the length of characters to search will be increased
		++length;
	}
	
	return num_words;
}
int main()
{
	std::ifstream in_file {};
	std::string word_search {};
	std::string line {};
	int total_words {0};
	int count{0};
	
	in_file.open("../romeo_juliet.txt");
	
	if(!in_file)
	{
		std::cerr << "Error opening file" << std::endl;
		return 1;
	} else {
		std::cout << "Enter the substring to search for: ";
		std::cin >> word_search;
		
		std::cout << "=== This implementation searches for substrings ===============================" << std::endl;
		
		while(std::getline(in_file, line))
		{
			// in_file >> line;
			total_words += count_words(line);
			
 			int start_pos {0};

			while((start_pos + word_search.size()) <= line.size())
			{
				std::string substring_char = line.substr(start_pos, word_search.size());
				if(substring_char == word_search)
					++count;
				++start_pos;
			}
		}
		std::cout << std::endl;
		std::cout << total_words << " words were searched... " << std::endl;
		std::cout << "The substring " << word_search << " was found " << count << " times" << std::endl;
	}
	
	in_file.close();
	
	std::cout << "=== This implementation searches for full words ===============================" << std::endl;
	
	total_words = 0;
	count = 0;
	
	in_file.open("../romeo_juliet.txt");

	if(!in_file)
	{
		std::cerr << "Error opening file" << std::endl;
		return 1;
	} else {
		while(!in_file.eof())
		{
			in_file >> line;
			++total_words;
			if(line.substr(0, word_search.size()) == word_search)
				++count;
		}
	}
	
	std::cout << total_words << " words were searched... " << std::endl;
	std::cout << "The substring " << word_search << " was found " << count << " times" << std::endl;
	
	in_file.close();
	
	return 0;
}