#include <iostream>
#include <string>
#include <vector>
#include <utility>

// Template classes
// Typically contained in header files
template <typename T>
class Item
{
private:	
	std::string name;
	T value;
public:
	Item(std::string name, T value)
		:name{name}, value{value}{}
	std::string get_name() const { return name; }
	T get_value() const { return value; }
};

// Also structs can have templates
template <typename T1, typename T2>
struct My_Pair
{
	T1 first;
	T2 second;
};


// Template function
// T is a generic (Template) representation of a class that can be passed
// as argument to a function
template <typename T>
T min(T a, T b)
{
	return (a < b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b)
{
	std::cout << a << " " << b << std::endl;
}

struct Person
{
	std::string name;
	int age;
	bool operator<(const Person &rhs) const
	{
		return this->age < rhs.age;
	}
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
	os << p.name;
	return os;
}

template <typename T>
void my_swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	Person p1 {"Curly", 50};
	Person p2 {"Moe", 30};
	
	Person p3 = min(p1, p2);
	
	std::cout << p3.name << " is younger" << std::endl;
	
	std::cout << min<int>(2, 3) << std::endl; // 2
	std::cout << min(2, 3) << std::endl; // 2
	std::cout << min('A', 'B') << std::endl; // A
	std::cout << min(12.5, 9.2) << std::endl; // 9.2
	std::cout << min(5 + 2 * 2, 7 + 40) << std::endl; // 9
	
	
	func<int, int>(10, 20);
	func(10, 20);
	func<char, double>('A', 12.4);
	func('A', 12.4);
	func(1000, "Testing");
	func(2000, std::string{"Frank"});
	func(p1, p2);
	
	int x{100};
	int y{200};
	std::cout << x << " " << y << std::endl;
	
	my_swap(x, y);
	std::cout << x << " " << y << std::endl;
	
	std::cout << "========================================" << std::endl;
	
	Item<int> item1{"Frank", 100};
	std::cout << item1.get_name() << " " << item1.get_value() << std::endl;
	
	Item<std::string> item2{"Frank", "Professor"};
	std::cout << item2.get_name() << " " << item2.get_value() << std::endl;
	
	Item<Item<std::string>> item3{"Frank", {"C++", "Professor"}};
	std::cout << item3.get_name() << " "
			  << item3.get_value().get_name() << " "
			  << item3.get_value().get_value() << std::endl;
	
	std::cout << "========================================" << std::endl;
	
	std::vector<Item<double>> vec{};
	vec.push_back(Item<double>("Larry", 100.0));
	vec.push_back(Item<double>("Moe", 200.0));
	vec.push_back(Item<double>("Curly", 300.0));
	
	for(const auto &item : vec)
		std::cout << item.get_name() << " " << item.get_value() << std::endl;
		
	
	std::cout << "========================================" << std::endl;
	My_Pair<std::string, int> pair1{"Frank", 100};
	My_Pair<int, double> pair2{124, 13.6};
	
	// first and second properties are called after including the utility library
	std::cout << pair1.first << ", " << pair1.second << std::endl;
	std::cout << pair2.first << ", " << pair2.second << std::endl;
	
	return 0;
}