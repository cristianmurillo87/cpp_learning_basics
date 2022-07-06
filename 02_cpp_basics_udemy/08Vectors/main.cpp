#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <char> vowels {'a', 'e', 'i', 'o', 'u'};
	
	cout << vowels[0] << endl;
	cout << vowels[4] << endl;
	
	vector <int> test_scores {100, 98, 89};
	
	cout << "Test scores using array sintax" << endl;
	cout << test_scores[0] << endl;
	cout << test_scores[1] << endl;
	cout << test_scores[2] << endl;
	
	cout << "Test scores using vector sintax" << endl;
	cout << test_scores.at(0) << endl;
	cout << test_scores.at(1) << endl;
	cout << test_scores.at(2) << endl;
	cout << "There are " << test_scores.size() << " scores in the vector" << endl;
	
	//Example of a 2D vector
	vector <vector<int>> movie_ratings {
		{1, 2, 3, 4},
		{2, 3, 4, 5},
		{3, 4, 5, 6}
	};
	
	//Using array format
	cout << movie_ratings[1][3] << endl;
	
	//Using vector format
	cout << movie_ratings.at(2).at(3) << endl;
	
	return 0;
}