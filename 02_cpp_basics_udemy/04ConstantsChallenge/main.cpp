#include <iostream>

using namespace std;

int main()
{
	const float SM_ROOM_PRICE = 25.0f;
	const float LG_ROOM_PRICE = 35.0f;
	const float TAX_RATE = 0.06f;
	const short VALID_ESTIMATE = 30;
	
	float serv_cost, tax_cost, total_cost;
	short rooms_lg, rooms_sm;
	
	cout << "Frank's Carpet Cleaning Service" << endl;
	cout << "================================" << endl;
	
	cout << "How many small rooms would you like to clean ?\n> ";
	cin >> rooms_sm;
	cout << "\nHow many large rooms would you like to clean ?\n> ";
	cin >> rooms_lg;
	
	cout << "Estimate for carpet cleaning service" << endl;
	cout << "Number of small rooms: " << rooms_sm << endl;
	cout << "Number of large rooms: " << rooms_lg << endl;
	cout << "Price per small room: $" << SM_ROOM_PRICE << endl;
	cout << "Price per large room: $" << LG_ROOM_PRICE << endl;
	
	serv_cost = (rooms_sm * SM_ROOM_PRICE) + (rooms_lg * LG_ROOM_PRICE);
	tax_cost = serv_cost * TAX_RATE;
	total_cost = serv_cost + tax_cost;
	
	cout << "Cost: $" << serv_cost << endl;
	cout << "Tax: $" << tax_cost << endl;
	cout << "================================" << endl;
	cout << "Total estimate: $" << total_cost << endl;
	cout << "This estimate is valid for " << VALID_ESTIMATE << " days." << endl;
	
	
	return 0;
}
