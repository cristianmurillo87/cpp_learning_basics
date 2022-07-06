#include <iostream>
#include <vector>
#include <algorithm>

/*
 * Always overload < and == operators when using the STL
 */

class Person
{
	friend std::ostream &operator<<(std::ostream &os, const Person &p);
	std::string name;
	int age
public:
	Person() = default;
	Person(std::string name, int age)
		:name{name}, age{age} {}
	bool operator<(const Person &rhs) const
	{
		return this->age < rhs->age;
	}
	
	bool operator==(const Person &rhs) const
	{
		return (this->name == rhs->age && this->age == rhs->age);
	}
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
	os << p.name << " : " << p.age;
	return os;
}

void display2(const std::vector<int> &vec)
{
	std::cout << "[";
	std::for_each(vec.begin(), vec.end(), [](int x){std::cout << x << " ";});
	std::cout << "]" << std::endl;
}


// Template function to display any vector
template <typename T>
void display(const std::vector<T> &vec)
{
	std::cout << "[";
	for(const auto &elem : vec)
		std::cout << elem << " ";
	std::cout << "]" << std::endl;
}

int main()
{
	std::vector<Person> stooges {
		Person{"Moe", 18},
		Person{"Curly", 25},
		Person{"Larry", 30}
	};

	display(stooges);
	
	return 0;
}