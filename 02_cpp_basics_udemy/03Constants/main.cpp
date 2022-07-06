#include <iostream>

using namespace std;

int main()
{
	int num_rooms;
	const short DAYS_VALID = 30;
	const double PRICE_PER_ROOM = 30;
	const double TAX_PERC = 0.06;
	
	cout << "Frank's Carpet Cleaning Room" << endl;
	cout << "===============================" << endl;
	
	cout << "How many rooms would you line to clean? ";
	cin >> num_rooms;
	
	cout << "\nEstimate for carpet cleaning service: " << endl;
	cout << "Number of rooms: " << num_rooms << endl;
	cout << "Price per room: $30" << endl;
	
	double cost = num_rooms * PRICE_PER_ROOM;
	double tax = cost * TAX_PERC;
	double total_estimate = cost + tax;
	
	cout << "Cost: $" << cost << endl;
	cout << "Tax: $" << tax << endl;
	cout << "===============================" << endl;
	cout << "Total estimate: $" << total_estimate << endl;
	cout << "This estimate is valid for "<< DAYS_VALID <<" days." << endl;
	
	return 0;
}