#include <iostream>

using namespace std;

int main()
{
	char selection {};
	
	do
	{
		cout << "-------------------------------" << endl;
		cout << "1. Do this" << endl;
		cout << "2. Do that" << endl;
		cout << "3. Do something else" << endl;
		cout << "Q. Quit" << endl;
		cout << endl;
		
		cout << "Enter your selection: ";
		cin >> selection;
		
		switch(selection)
		{
			case '1':
				cout << "You chosed " << selection << " - doing this." <<endl;
				break;
			case '2':
				cout << "You chosed " << selection << " - doing that." <<endl;
				break;
			case '3':
				cout << "You chosed " << selection << " - do something else." <<endl;
				break;
			case 'q':
			case 'Q':
				cout << "Bye bye." <<endl;
				break;
			default:
				cout << "Invalid option" << endl;
		}
		
	} while(selection != 'q' && selection != 'Q');
		
	return 0;
}