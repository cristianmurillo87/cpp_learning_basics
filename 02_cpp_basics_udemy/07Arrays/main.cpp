#include <iostream>

using namespace std;

int main()
{
	// Unidimensional arrays
	char vowels[] {'a', 'e', 'i', 'o', 'u'};
	cout << "\nThe first vowel is: " << vowels[0] << endl;
	cout << "The last vowel is: " << vowels[4] << endl;
	
	//Multidimensional arrays
	int movie_rating [3] [4] {
		{0, 4, 3, 5},
		{2, 3, 3, 5},
		{1, 4, 4, 5}
	};
	
	cout << movie_rating[2][3] << endl;
	
	return 0;
	
}