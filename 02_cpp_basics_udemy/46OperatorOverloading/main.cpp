#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main()
{
	Mystring larry{"Larry"};
	Mystring moe{"Moe"};
	
	Mystring stooge  = larry;
	
	larry.display();
	moe.display();
	
	cout << (larry == moe) << endl;
	cout << (larry == stooge) << endl;
	
	larry.display();
	Mystring larry2 = -larry;
	larry2.display();
	
	Mystring stooges = larry + "Moe";
	
	Mystring two_stooges = moe + " " + "Larry";
	two_stooges.display();
	/*
	Mystring a {"Hello"}; // Overloaded constructor
	a = Mystring{"Hola"}; // Overloaded constructor then move assignment
	a = "Bonjour";		  //  Overloaded constructor then move assignment
	
	Mystring b;			   // No-args constructor
	b = a;				   // copy assignments
						   // b.operator=(a)
	
	b = "This is a test"; // b.operator=("This is a text")
	
	
	Mystring empty;			 // No-args constructor
	Mystring larry{"Larry"};// Overloaded constructor
	Mystring stooge{larry}; // Copy constructor
	Mystring stooges;		 // No-args constructor
	
	empty = stooge;			 // Copy assignment operator
							 // Stooge is an l-value
	
	empty = "Funny";		 // Move assignment operator
							 // "Funnny" is an r-value
							 
	
	empty.display();
	larry.display();
	stooge.display();
	empty.display();
	
	stooges = "Larry, Moe and Curly";
	stooges.display();
	
	vector<Mystring> stooges_vec;
	stooges_vec.push_back("Larry");
	stooges_vec.push_back("Moe");
	stooges_vec.push_back("Curly");
	
	cout << "=== Loop 1 ======================" << endl;
	for(const Mystring &s: stooges_vec)
		s.display();
	
	
	cout << "=== Loop 2 ======================" << endl;
	for(const Mystring &s: stooges_vec)
		s = "Changed";		// Move assignment
		
	cout << "=== Loop 2 ======================" << endl;
	for(const Mystring &s: stooges_vec)
		s.display();
	*/
		
	return 0;
}
