#include <iostream>

using namespace std;

unsigned long long fibonacci(unsigned long long n)
{
	if(n <= 1)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned long long factorial(unsigned long long n)
{
	if(n <= 1)
		return 1;
	return n * factorial(n -1);
}

int main()
{
	unsigned long long number;
	cout << "Enter a number to calculate the fibonacci series: ";
	cin >> number;
	
	cout << "Fibonacci between 0 and " << number << " is: " << fibonacci(number) << endl;
	cout << "And its factorial is: " << factorial(number) << endl;
	cout << endl;
	return 0;
}