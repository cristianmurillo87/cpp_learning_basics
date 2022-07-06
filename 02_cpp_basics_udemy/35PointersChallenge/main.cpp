#include <iostream>

using namespace std;

void print(const int *const array, size_t size)
{
	cout << "[ ";
	for(size_t i = 0; i < size; ++i)
		cout << array[i] << " ";
	cout << "]" << endl;
}


int *apply_all(const int *const array1, size_t size1, const int *const array2, size_t size2)
{
	
	int *new_array = nullptr;
	int new_array_size = size1 * size2;
	int array_el = 0;
	
	new_array = new int[new_array_size];
	
	for(size_t j = 0; j < size2; ++j)
	{
		for(size_t i = 0; i < size1; ++i)
		{
			new_array[array_el] = array2[j] * array1[i];
			array_el++;
		}
	}
	
	return new_array;
}





int main()
{
	int array1[] {1, 2, 3, 4, 5};
	int array2[] {10, 20, 30};
	
	const size_t array1_size = 5;
	const size_t array2_size = 3;
	constexpr size_t new_array_size = array1_size * array2_size;
	
	int *new_array = nullptr;
	
	cout << "Array 1: ";
	print(array1, array1_size);
	
	cout << "Array 2: ";
	print(array2, array2_size);
	
	
	cout << "---------------------" << endl;
	
	new_array = apply_all(array1, array1_size, array2, array2_size);
	cout << "Result: ";
	print(new_array, new_array_size);
	delete [] new_array;
	
	return 0;
}

