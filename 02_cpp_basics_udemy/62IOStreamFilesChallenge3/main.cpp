#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream in_file{"../romeoandjuliet.txt"};
	std::ofstream out_file{"../romeoandjuliet_copy.txt"};
	std::string line;
	int num_line{1};
	
	if(!in_file)
	{
		std::cerr << "Error opening input file" << std::endl;
		return 1;
	}
	
	if(!out_file)
	{
		std::cerr << "Error opening output file" << std::endl;
		return 1;
	}
	
	
	while(std::getline(in_file, line))
	{
		if(line.size() > 0)
		{
			out_file << num_line << "\t\t\t" << line << std::endl;
			++num_line;
		}
		else
			out_file << line << std::endl;
	}
	
	in_file.close();
	out_file.close();
	
	std::cout << "Copy completed" << std::endl;

 
	return 0;
}