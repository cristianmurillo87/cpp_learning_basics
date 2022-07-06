#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int length {};
	int width {};
	int height {};
	
	const int MAX_SIZE {10};
	const int THRESHOLD1 {100};
	const int THRESHOLD2 {500};
	const float BASE_COST {2.50f};
	const float SUBCHARGE1 {0.1f};
	const float SUBCHARGE2 {0.25f};
	
	cout << "Shipping Cost Calculator" << endl;
	cout << "============================" << endl;
	
	cout << "Please enter the dimensions (width, length and height)\nof the package in inches: " << endl;
	cin >> width >> length >> height;
	
	
	
	if(width <= MAX_SIZE && length <= MAX_SIZE && height <= MAX_SIZE)
	{
		int total_volume = width * length * height;
		float total_cost {BASE_COST};
		
		cout << "===============================" << endl;
		
		cout << "The volumen of your package is: " << total_volume << " cubic inches." << endl;
		
		if (total_volume > THRESHOLD2)
		{
			total_cost += BASE_COST * SUBCHARGE2;
			
		} else if (total_volume > THRESHOLD1)
		{
			total_cost += BASE_COST * SUBCHARGE1;
		}
		
		cout << fixed << setprecision(2);
		cout << "The cost of your shipment is: $" << total_cost << endl;
		
		
	} else
	{
		cout << "Sorry, your package cannot be shipped,\none of its dimensions exceeds " << MAX_SIZE << " cubic inches." << endl;
	}
	
	return 0;
}