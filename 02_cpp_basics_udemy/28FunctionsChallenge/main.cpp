#include <iostream>
#include <iomanip>
#include <vector>
#include <cctype>

using namespace std;
//	Display menu options
void display_menu();
//	Print numbers of a vector
void print_vector(const vector<int> &v);
void handle_print(const vector<int> &v);
//	Calculate the mean of a vector
float calculate_mean(const vector<int> &v);
void handle_mean(const vector<int> &v);
//	Smallest number in a vector
int get_smallest(const vector<int> &v);
void handle_min(const vector<int> &v);
//	Largest number in a vector
int get_largest(const vector<int> &v);
void handle_max(const vector<int> &v);
//	Add numbers to a vector
void add_vector_element(const vector<int> &v, int number);
void handle_add(const vector<int> &v);
//	Clear the vector
void clear_vector(const vector<int> &v);


int main()
{
	vector<int> numbers {};
	char selection {};
	
	do
	{
		display_menu();
		cin >> selection;
		
		switch(toupper(selection))
		{
			case 'P':
				handle_print(numbers);
				break;
			case 'A':
				handle_add(numbers);
				break;
			case 'M':
				handle_mean(numbers);
				break;
			case 'S':
				handle_min(numbers);
				break;
			case 'L':
				handle_max(numbers);
				break;
			case 'Q':
				cout << "Goodbye!" << endl;
				break;
			default:
				cout << "Unknown selection, please try again" << endl;
				break;
		}
		
	} while(toupper(selection) != 'Q');
	
	clear_vector(numbers);
	
	return 0;
}


void display_menu()
{
		cout << "---------------------------------" << endl;
		cout << "P - Print numbers" << endl;
		cout << "A - Add a number" << endl;
		cout << "M - Display mean of the numbers" << endl;
		cout << "S - Display the smallest numbers" << endl;
		cout << "L - Display the largest numbers" << endl;
		cout << "Q - Quit" << endl;
		cout << "Enter your choice: ";
}

void print_vector(vector<int> &v)
{
	if(v.size() == 0)
	{
		cout << "[] - The list is empty" << endl;
	}
	else
	{
		cout << "[ ";
		for(auto num : v)
			cout << num << " ";
		cout << "]" << endl;
	}
}

float calculate_mean(vector<int> &v)
{
	float sum {0.0};
	
	for(auto num : v)
		sum += num;
		
	return sum / v.size();
}

int get_smallest(vector<int> &v)
{
	int smallest {v.at(0)};
	
	for(auto num : v)
	{
		if(num < smallest)
			smallest = num;
	}
	
	return smallest;
}

int get_largest(vector<int> &v)
{
	int largest {v.at(0)};
	
	for(auto num : v)
	{
		if(num > largest)
			largest = num;
	}
	
	return largest;
}

void add_vector_element(vector<int> &v, int number)
{
	v.push_back(number);
}

void clear_vector(vector<int> &v)
{
	v.clear();
}

void handle_print(vector<int> &v)
{
	print_vector(v);
}

void handle_mean(vector<int> &v)
{
	if(v.size() == 0)
		cout << "Unable to calculate the mean - no data" << endl;
	else
	{
		cout << "The mean of the elements in the list is " << fixed << setprecision(1) << calculate_mean(v) << endl;
	}
}

void handle_add(vector<int> &v)
{
	int new_item {};
	cout << "Enter the value to add to the list: ";
	cin >> new_item;
	add_vector_element(v, new_item);
	cout << new_item <<" added to the list" << endl;
}

void handle_min(vector<int> &v)
{
	if(v.size() ==0)
		cout << "Unable to determine the smallest number - list is empty" << endl;
	else
	{
		cout << "The smallest value of the list is " << get_smallest(v) << endl;
	}
}

void handle_max(vector<int> &v)
{
	if(v.size() ==0)
		cout << "Unable to determine the largest number - list is empty" << endl;
	else
	{
		cout << "The largest value of the list is " << get_largest(v) << endl;
	}
}