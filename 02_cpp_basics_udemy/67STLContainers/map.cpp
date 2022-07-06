#include <iostream>
#include <map>
#include <vector>

void display(std::map<std::string, std::set<int>> &m)
{
	std::cout << "[ ";
	for(const auto &elem : m)
	{
		std::cout << elem.first << " : [ ";
		for(const auto &set_elem : elem.second)
			std::cout << set_elem << " ";
		std::cout << " ]";
	}
	std::cout << " ]" << std::endl;
}

template <typename T1, typename T2>
void display(std::map<T1, T2> &l)
{
	std::cout << "[ ";
	for(const auto &elem : m)
		std::cout << elem.first << elem.second << " ";
	std::cout << "]" << std::endl;
}

int main()
{
	std::cout << "--------Test 1---------------" << std::endl;
	std::map<std::string ,int> m {
		{"Larry", 3},
		{"Moe", 1},
		{"Curly", 2}
	};
	
	display(m);
	
	m.insert(std::pair<std::string, int>("Anna", 10));
	display(m);
	
	m.insert(std::make_pair("Joe", 5));
	display(m);
	
	m["Frank"] = 18;
	display(m);
	
	m["Frank"] += 10;
	display(m);
	
	m.erase("Frank");
	display(m);
	
	std::cout << "Count for Joe: " << m.count("Joe") << std::endl;
	std::cout << "Count for Frank: " << m.count("Frank") << std::endl;
	
	auto it = m.find("Larry");
	if(it != m.end())
		std::cout << "Found: " << it->first << it->second << std::endl;
		
	m.clear();
	display(m);
	
	std::cout << "--------Test 1---------------" << std::endl;
	
	std::map<std::string, std::set<int>> grades {
		{"Larry", {100, 90}},
		{"Moe", {94}},
		{"Curly", {80, 90, 100}}
	}
	
	display(grades);
	
	grades["Larry"].insert(95); // insert 95 to the set of grades for "Larry"
	
	display(grades);
	
	auto it2 = grades.find("Moe");
	if(it2 != grades.end())
		it2->second.insert(1000); // it2->first is the key, it2->second is the value (the set in this case)
	
	display(grades);
	
}