#include <iostream>

using namespace std;

int main()
{
	int counter = 10;
	int result = 0;
	
	cout << "Counter: " << counter << endl;
	
	counter = counter + 1;
	cout << "Counter: " << counter << endl;
	
	counter++;
	cout << "Counter: " << counter << endl;
	
	++counter;
	cout << "Counter: " << counter << endl;
	
	// Post-increment
	counter = 10;
	result = 0;
	
	cout << "Counter: " << counter << endl;
	
	result = ++counter; // counter+=1 (11) ; result = counter (11);
	cout << "Counter: " << counter << endl;
	cout << "Result: " << result << endl;
	
	
	// Pre-increment
	counter = 10;
	result = 0;
	
	cout << "Counter: " << counter << endl;
	
	result = counter++; // result = counter (10); counter+=1 (11) ; 
	cout << "Counter: " << counter << endl;
	cout << "Result: " << result << endl;
	
	return 0;
}