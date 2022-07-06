#include <iostream>

using namespace std;

void double_data(int *int_ptr)
{
	*int_ptr *= 2;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int value {10};
	int *int_ptr {nullptr};
	int x {100}, y {200};
	
	cout << "Value: " << value << endl;
	double_data(&value);
	cout << "Value: " << value << endl;
	
	cout << "--------------------" << endl;
	int_ptr = &value;
	double_data(int_ptr);
	cout << "Value: " << value << endl;
	
	cout << "\n---------------Swap Function---------------" << endl;
	cout << "X: " << x << " Y: " << y << endl;
	swap(&x, &y);
	cout << "X: " << x << " Y: " << y << endl;
	
	
	return 0;
}