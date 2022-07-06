#include <iostream>

using namespace std;

int main()
{
	bool done = false;
	int number = 0;
	
	while(!done)
	{
		cout << "Enter an integer between 1 and 5: ";
		cin >> number;
		if(number <= 1 || number >= 5)
			cout << "Out of range, try again" << endl;
		else
		{
			cout << "Thanks!" << endl;
			done = true;
		}
	}
	
	return 0;
}