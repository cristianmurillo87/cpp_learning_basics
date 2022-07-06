#include <array>
#include <algorithm>
#include <numeric>
#include <iostream>

void display(const std::array<int, 5> &arr)
{
	std::cout << "[ ";
	for(auto item : arr)
		std::cout << item << " ";
	std::cout << " ]\n";
}

void test1()
{
	std::cout << "\nTest 1 (Array) =====================================" << std::endl;
	std::array<int, 5> arr1 {1, 2, 3, 4, 5}; // double {{}} if C++11 - std::array<T, size>
	std::array<int, 5> arr2;
	
	display(arr1);
	display(arr2);
	
	arr2 = {10, 20, 30, 40, 50};
	
	display(arr1);
	display(arr2);
	
	std::cout << "Size of arr1 is: " << arr1.size() << std::endl;
	std::cout << "Size of arr2 is: " << arr2.size() << std::endl;
	
	arr1[0] = 1000;
	arr1.at(1)  =2000;
	display(arr1);
	
	std::cout << "Front of arr1 is: " << arr1.front() << std::endl;
	std::cout << "Front of arr2 is: " << arr2.front() << std::endl;

	std::cout << "========= Array Fill ==========" << std::endl;
	
	arr1.fill(0);
	
	display(arr1);
	display(arr2);
	
	std::cout << "========= Array Swap ==========" << std::endl;
	
	arr1.swap(arr2);
	
	display(arr1);
	display(arr2);
	
	std::cout << "====== Array Data Method ======" << std::endl;
	
	int *ptr = arr1.data();
	std::cout << ptr << std::endl;
	*ptr = 1000;
	
	display(arr1);
	
	std::cout << "========= Array Sort ==========" << std::endl;
	
	std::sort(arr1.begin(), arr1.end());
	display(arr1);
	
}

int main()
{
	test1();
	return 0;
}