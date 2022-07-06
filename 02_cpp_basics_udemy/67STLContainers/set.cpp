#include <iostream>
#include <set>



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
	std::set<int> s1 {1, 1, 2, 2, 3, , 4, 5};
	display(s1); //[1 2 3 4 5] - sets do not allow duplicates and elements are ordered
	
	s1.insert(0);
	s1.insert(10);
	
	display(s1); // [0 1 2 3 4 5 10]
	
	if(s1.count(10))
		std::cout << "10 is in the set" << std::endl;
	else
		std::cout << "10 is NOT in the set" << std::endl;
		
	std::cout << "--------Test 2---------------" << std::endl;
	
	std::set<Person> stooges {
		{"Larry", 18},
		{"Moe", 25},
		{"Curly", 30}
	};
	
	display(stooges);
	
	stooges.emplace("James", 50);
	stooges.emplace("Frank", 50); // will not be inserted in the set since "James" already has 50 (would be duplicate)
	
	auto it = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25});
	if(it != stooges.end())
		stooges.erase(it); // deletes Person("Moe", 25) and invalites "it"
	display(it);
}

int main()
{
	return 0;
}