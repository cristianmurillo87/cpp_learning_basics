#include <iostream>

using namespace std;

int main()
{
	// Characer type
	char middle_initial = 'A';
	cout << "My middle initial is " << middle_initial << endl;
	
	//Integer types
	unsigned short int exam_score = 55;
	cout << "My exam score was " << exam_score << endl;
	
	int countries_represented = 65;
	cout << "There were " << countries_represented << " countries represented in my meeting" << endl;
	
	long people_in_florida = 20610000;
	cout << "There are about " << people_in_florida << " people in Florida" << endl;
	
	long people_on_earth = 7600000000;
	cout << "There are about " << people_on_earth << " people on Earth" << endl;
	
	// Floating point types
	float car_payment = 401.23;
	cout << "My car payment is " << car_payment << endl;
	
	double pi = 3.14159;
	cout << "Pi is " << pi << endl;
	
	long double large_amount = 2.7e120;
	cout << large_amount << " is a very big number" << endl;
	
	//Boolean types
	bool game_over = false;
	cout << "The value of game_over is " << game_over << endl;
	
	//Overflow example
	short value1 = 30000;
	short value2 = 1000;
	short product = value1 * value2;
	
	cout << "The product of " << value1 << " and " << value2 << " is " << product << endl;
	
	return 0;
}