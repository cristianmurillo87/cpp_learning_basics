#include <iostream>

using namespace std;

int main()
{
	int scores[] {100, 95, 89};
	int high_score {100};
	int low_score {65};
	
	cout << "Value of scores: " << scores << endl;
	
	int *score_ptr {scores};
	cout << "Value of score_ptr: " << score_ptr << endl;
	
	cout << "\nArray subscript notation----------------------------" << endl;
	cout << scores[0] << endl;
	cout << scores[1] << endl;
	cout << scores[2] << endl;
	
	cout << "\nPointer subscript notation----------------------------" << endl;
	cout << score_ptr[0] << endl;
	cout << score_ptr[1] << endl;
	cout << score_ptr[2] << endl;
	
	cout << "\nPointer offset notation----------------------------" << endl;
	cout << *score_ptr << endl;
	cout << *(score_ptr + 1) << endl; //	1 means 1 integer because score_ptr points to an array of integers 
	cout << *(score_ptr + 2) << endl; // 	2 means 2 integers
	
	cout << "\nArray offset notation----------------------------" << endl;
	cout << *scores << endl;
	cout << *(scores + 1) << endl;
	cout << *(scores + 2) << endl;
	
	//	Const and Pointers
	//	Pointers to constants
	const int *score_ptr2 {&high_score};
	*score_ptr2 = 86 //	Error
	score_ptr2 = &low_score //	OK
	
	//	Constant pointers
	int *const score_ptr3 {&high_score};
	*score_ptr3 = 86 // OK
	score_ptr3 = &low_score //	Error
	
	//Constant pointers to constants
	const int *const score_ptr4 {&high_score};
	*score_ptr4 = 86; //	Error
	score_ptr4 = &low_score; //	Error
	
	
	return 0;
}