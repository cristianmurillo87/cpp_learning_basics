#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream in_file {};
	std::string correct_answer {};
	std::string name {};
	std::string std_answer {};
	std::vector<std::string> names {};
	std::vector<int> grades {};
	int total_grade{0};
	
	
	in_file.open("../report.txt");
	
	if(!in_file)
	{
		std::cout << "Error opening file" << std::endl;
		return 1;
	}
	 
	in_file >> correct_answer;
	
	
	while(!in_file.eof())
	{
		in_file >> name >> std_answer;
		names.push_back(name);
		
		int score {0};
		for(int i = 0; i < std_answer.length(); ++i)
		{
			if(std_answer[i] == correct_answer[i])
				score++;
		}
		
		grades.push_back(score);
		total_grade += score;
	}
	
	
	std::cout << "====================" << std::endl;
	std::cout << std::setw(10) << std::left  << "Student" << std::setw(10) << std::right << "Score" << std::endl;
	std::cout << "--------------------" << std::endl;
	for(int i = 0; i < names.size(); i++)
		std::cout << std::setw(10) << std::left << names.at(i) << std::setw(10) << std::right << grades.at(i) << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::setw(10) << std::left << "Average score" << std::setw(7) << std::right << (static_cast<double>(total_grade) / grades.size()) << std::endl;
	
	
	
	in_file.close();
	return 0;
}
