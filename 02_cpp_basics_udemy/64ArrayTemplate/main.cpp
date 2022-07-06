#include <iostream>
#include <string>

template <typename T, int N>
class Array
{
	int size{N};
	T values[N]; // N needs to be known at compile-time
	
	friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr)
	{
		os << "[ ";
		for(const auto &val : arr.values)
			os << val << " ";
		os << "]" << std::endl;
		return os;
	}
public:
	Array() = default;
	Array(int init_val)
	{
		for(auto &item:values)
			item = init_val;
	}
	
	void fill(int val)
	{
		for(auto &item: values)
			item = val;
	}
	
	int get_size() const
	{
		return size;
	}
	
	// Overloaded subscript operator for easy use
	int &operator[](int index)
	{
		return values[index];
	}
};

int main()
{
	Array<5> nums;
	
	std::cout << "The size of num is: " << nums.get_size() << std::endl;
	std::cout << nums << std::endl; // Prints the elements of the array. Uses the operator overloading function
	
	nums.fill(0); // Fills the elements of the array with zeros
	std::cout << "The size of num is: " << nums.get_size() << std::endl;
	std::cout << nums << std::endl;
	
	nums.fill(10);
	std::cout << nums << std::endl;
	
	nums[0] = 1000;
	nums[1] = 2000;
	std::cout << nums << std::endl;
	
	Array<100> nums2(1); // Creates an object of type Array with 100 elements and populates them with the value 1
	std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
	std::cout << nums2 << std::endl; 
	
	
 	return 0;
}