#include <iostream>
#include <memory>
#include "Account.h"
#include "IllegalBalanceException.h"
// Custom exception classes
class DivideByZeroException{};

class NegativeValueException{};

double calculate_mpg(int miles, int gallons)
{
	// Exceptions are thrown if gallons is equal to zero or if either gallons or miles are negative values
	if(gallons == 0)
		throw DivideByZeroException();
	if(miles < 0 || gallons < 0)
		throw NegativeValueException();
	
	return static_cast<double>(miles) / gallons;
}

int main()
{
	int miles;
	int gallons;
	double miles_per_gallon;
	
	std::cout << "Enter the miles driven: ";
	std::cin >> miles;
	
	std::cout << "Enter the gallons used: ";
	std::cin >> gallons;
	
	try
	{
		miles_per_gallon = calculate_mpg(miles, gallons);
		std::cout << "Result: " << miles_per_gallon << std::endl;
	}
	catch(const DivideByZeroException &e)
	{
		std::cerr << "Error: miles driven cannot be zero" << std::endl;
	}
	catch(const NegativeValueException &e)
	{
		std::cerr << "Input values cannot be negative" << std::endl;
	}
	
	std::cout << "Bye" << std::endl;
	
	try
	{
		std::unique_ptr<Account> acc = std::make_unique<Account>("Joe", -10);
		// std::cout << *acc << std::endl;
	}
	catch(const IllegalBalanceException &e)
	{
		std::cerr << "Couldn't create account - negative balance" << std::endl;
	}
	
	std::cout << "Program completed successfully" << std::endl;
	
	return 0;
}