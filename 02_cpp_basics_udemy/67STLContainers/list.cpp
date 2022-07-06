#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>


class Person
{
	friend std::ostream &operator<<(std::ostream &os, const Person &p);
	std::string name;
	int age;
public:
	Person() : name{"Unknown"}, age{0}{}
	Person(std::string name, int age)
		:name{name}, age{age}{}
	bool operator<(const Person &rhs) const
	{
		return this->age < rhs->age;
	}
	bool operator==(const Person &rhs) const
	{
		return (this->name == rhs->name && this->age == rhs->age);
	}
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
	os << p.name << " : " << p.age;
	return os;
}

template <typename T>
void display(std::list<T> &l)
{
	std::cout << "[ ";
	for(const auto &elem : l)
		std::cout << elem << " ";
	std::cout << "]" << std::endl;
}

void test()
{
	std::cout << "--------Test 1---------------" << std::endl;
	std::list<int> l1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	display(l1);
	
	std::list<std::string> l2;
	l2.push_back("Back");
	l2.push_front("Front");
	display(l2);
	
	std::cout << "--------Test 2---------------" << std::endl;
	
	std::cout << "Size: " << l1.size() << std::endl;
	std::cout << "Front: " << l1.front() << std::endl;
	std::cout << "Back: " << l1.back() << std::endl;
	
	l2.clear();
	display(l2);
	std::cout << "Size: " << l2.size() << std::endl;
	
	std::cout << "--------Test 3---------------" << std::endl;
	
	l1.resize(5); // will shrink the list to the first 5 elements
	display(l1); // [1 2 3 4 5]
	
	l1.resize(10); // will create 5 additional 5 locations to the list, their values will be the default values for the data type
	display(l1); // [1 2 3 4 5 0 0 0 0 0]
	
	std::cout << "--------Test 4---------------" << std::endl;
	
	l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	display(l1);
	auto it = std::find(l1.begin(), l1.end(), 5); // searching 5 in the list, will return the index in which 5 is located (the returned value behaves like a pointer)
	if(it != l1.end())
	{
		l1.insert(it, 100) // inserts the value 100 in the index corresponding to 5 (not replacement, moves 5 and the elements after the index in order to allocate 100)
	}
	
	display(l1); // [1 2 3 4 100 5 6 7 8 9 10]
	
	std::list<int> l3 {1000, 2000, 3000};
	l1.insert(it, l3.begin(), l3.end()); // inserts the elements of l3 into l1 at the specified index
	display(l1) // [1 2 3 4 100 1000 2000 3000 5 6 7 8 9 10]
	
	// "it" was declared to point to the location of 5
	// std::advance can change to the left (negative) or the right (positive) the location an iterators points to
	std::advance(it, -4 ); // now points to 100 (4 locations to the left of 5)
	std::cout << *it << std::endl; // 100
	
	l1.erase(it); // removes 100 - "it" becomes invalid
	
	std::cout << "--------Test 5---------------" << std::endl;
	
	std::list<Person> stooges {
		{"Larry", 18},
		{"Moe", 25},
		{"Curly", 30}
	};
	
	display(stooges);
	
	stooges.emplace_back("James", 35);
	display(stooges);
	
	auto it2 = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25});
	if(it2 != stooges.end())
		stooges.emplace("Frank", 18);
	
	display(stooges);
	stooges.sort();
	display(stooges);
}


int main()
{
	test();
	return 0;
}