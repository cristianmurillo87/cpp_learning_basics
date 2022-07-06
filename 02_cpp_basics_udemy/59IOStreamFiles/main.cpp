#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main()
{
	std::ifstream in_file;
	std::ofstream out_file{"../output.txt", std::ios::app};
	std::string line;
	char c;
	int num;
	double total;
	
	in_file.open("../test.txt");
	if(!in_file)
	{
		std::cerr << "Problem opening file" << std::endl;
		return 1;
	}
	while(!in_file.eof())
	{
		in_file >> line >> num >> total;
		std::cout << std::setw(10) << std::left << line
					<< std::setw(10) << num
					<< std::setw(10) << total
					<< std::endl;
	}
	
	in_file.close();
	
	std::cout << "=============================================" << std::endl;
	
	in_file.open("../poem.txt");
	if(!in_file)
	{
		std::cerr << "Problem opening file" << std::endl;
		return 1;
	}
	
	while(std::getline(in_file, line))
	{
		std::cout << line << std::endl;
	}
	
	in_file.close();
	
	std::cout << "=============================================" << std::endl;
	
	in_file.open("../poem.txt");
	if(!in_file)
	{
		std::cerr << "Problem opening input file" << std::endl;
		return 1;
	}
	if(!out_file)
	{
		std::cerr << "Problem opening output file" << std::endl;
	}
	
	while(in_file.get(c))
	{
		out_file.put(c);
	}
	
	std::cout << std::endl;
	
	
	in_file.close();
	out_file.close();
//	std::string new_line;
//	std::cout << "Enter something to write to the file " << std::endl;
//	std::getline(std::cin, new_line);
//	out_file << new_line << std::endl;
	
	
	return 0;
	
}