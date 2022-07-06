#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <double> temps {87.2, 77.1, 80.0, 72.5};
	
	double average_temp {};
	double running_sum {};
	
	// auto : let C++ to deduce the type of variable on its own
	for(auto temp : temps)
		running_sum += temp;
	
	if(temps.size() != 0)	
		average_temp = running_sum / temps.size();
	
	cout << "The average temperature is: " << average_temp << endl;
		
	return 0;
}