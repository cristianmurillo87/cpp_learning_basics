#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
	vector <int> numbers {};
	char selection {};
	
	do
	{
		cout << "---------------------------------" << endl;
		cout << "P - Print numbers" << endl;
		cout << "A - Add a number" << endl;
		cout << "M - Display mean of the numbers" << endl;
		cout << "S - Display the smallest numbers" << endl;
		cout << "L - Display the largest numbers" << endl;
		cout << "Q - Quit" << endl;
		
		cout << "Enter your choice: ";
		cin >> selection;
		
		switch(selection){
			case 'P':
			case 'p':
			{
				if (numbers.size() == 0)
					cout << "[] - The list is empty" << endl;
				else
				{
					cout << "[ ";
					for(auto val : numbers)
						cout << val << " ";
					cout << "]";
					cout << endl;
				}
				
			} break;
			case 'A':
			case 'a':
			{
				int new_item {};
				cout << "Enter the value to add to the list: ";
				cin >> new_item;
				numbers.push_back(new_item);
				cout << new_item <<" added to the list" << endl;
				
			} break;
			case 'M':
			case 'm':
			{
				if(numbers.size() > 0)
				{
					float mean {0.0};
					float sum_items {0.0};
					
					for(auto val : numbers)
						sum_items += val;
					mean = sum_items / numbers.size();
					cout << "The mean of the elements in the list is " << fixed << setprecision(1) << mean << endl;					
				}
				else
				{
					cout << "Unable to calculate the mean - no data" << endl;
				}
				
			} break;
			case 'S':
			case 's':
			{
				if(numbers.size() == 0)
				{
					cout << "Unable to determine the smallest number - list is empty" << endl;
				}
				else
				{
					int smallest {numbers.at(0)};
					for(auto val : numbers)
					{
						if(val < smallest)
							smallest = val;
					}		
					cout << "The smallest value of the list is " << smallest << endl;
				
				}
				
			} break;
			case 'L':
			case 'l':
			{
				if(numbers.size() == 0)
				{
					cout << "Unable to determine the largest number - list is empty" << endl;
				}
				else
				{
					int largest {numbers.at(0)};
					for(auto val: numbers)
					{
						if( val > largest)
							largest = val;
					}
					cout << "The largest value of the list is " << largest << endl;
				}
				
			} break;
			case 'Q':
			case 'q':
				cout << "Goodbye!" << endl;
				break;
			default:
				cout << "Unknown selection, please try again" << endl;
				break;
		}
	} while(selection != 'q' && selection != 'Q');
	return 0;
}