#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

// Display any vector of integers using rage-based loop
void display(const std::vector<int> &vec)
{
	
}


void test1()
{
	std::cout << "\n===============================================" << std::endl;
	std::vector<int> nums1 {1, 2, 3, 4, 5};
	
	auto it = nums1.begin(); // points to 1	
	std::cout << *it << std::endl;
	
	it++; // points to 2
	std::cout << *it << std::endl;
	
	it += 2; // points to 4
	std::cout << *it << std::endl;
	
	it -= 2; // points to 2
	std::cout << *it << std::endl;
	
	it = nums1.end() - 1; // points to 5
	std::cout << *it << std::endl; 
}

void test2()
{
	std::cout << "\n===============================================" << std::endl;
	std::vector<int> nums1 {1, 2, 3, 4, 5};
	
	std::vector<int>::iterator it = nums1.begin(); // using the standard sintaxis instead of auto
	while(it != nums1.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	
	it = nums1.begin();
	while(it != nums1.end())
	{
		*it = 0;
		it++;
	}
	
	// display(nums1);
}

void test3()
{
	std::cout << "\n===============================================" << std::endl;
	std::vector<int> nums1 {1, 2, 3, 4, 5};
	
	std::vector<int>::const_iterator it1 = nums1.begin(); // const iterator; the values it points to cannot be changed
	// auto it1 = nums1.cbegin(); // equivalent to the line above; cbegin instead of begin for const iterator
	
	while(it1 != nums1.end())
	{
		std::cout << *it1 << std::endl;
		it1++;
	}
	
	// Compiler error when trying to change element
	it1 = nums1.begin();
	while(it1 != nums1.end())
	{
		// *it1 = 0; // compiler error - read only
		it1++;
	}
}

void test4()
{
	std::vector<int> vec {1, 2, 3, 4};
	auto it1 = vec.rbegin(); // reverse iterator over vector of ints starts at 4
	while(it1 != vec.rend())
	{
		std::cout << *it1 << std::endl;
		it1++;
	}
	
	std::list<std::string> name {"Larry", "Moe", "Curly"};
	auto it2 = name.crbegin(); // iterator over list of strings point to Curly
	std::cout << *it2 << std::endl;
	it2++; // point to Moe
	std::cout << *it2 << std::endl;
	
	std::map<std::string, std::string> favorites{
		{"Frank", "C++"},
		{"Bill", "Java"},
		{"James", "Haskell"}
	};
	
	auto it3 = favorites.begin(); // iterator over a map of string pairs
	while(it3 != favorites.end())
	{
		std::cout << it3->first << " : " << it3->second << std::endl;
		it3++;
	}
}

void test5()
{
	std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto start = vec.begin() + 2;
	auto finish = vec.end() - 3;
	
	while(start != finish)
	{
		std::cout << *start << std::endl;
		start++;
	}
}

int main()
{
	// test1();
	// test2();
	// test3();
	// test4();
	// test5();
	
	return 0;
}