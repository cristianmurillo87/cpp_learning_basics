#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "========== Booleans ================================" << std::endl;
	std::cout << "noboolalpha - deafult (10 == 10): " << (10 == 10) << std::endl; // displays 1
	std::cout << "noboolalpha - deafult (10 == 20): " << (10 == 20) << std::endl; // displays 0
	
	std::cout << std::boolalpha; //from now will display true or false instead of 1 or 0
	std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl; // displays true
	std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl; // displays false
	
	std::cout << std::noboolalpha; // toggle back to 1/0
	std::cout << "noboolalpha - deafult (10 == 10): " << (10 == 10) << std::endl; // displays 1
	std::cout << "noboolalpha - deafult (10 == 20): " << (10 == 20) << std::endl; // displays 0
	
	std::cout.setf(std::ios::boolalpha); // set back to true/false with cout.setf()
	std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl; // displays true
	std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl; // displays false

	std::cout << std::resetiosflags(std::ios::boolalpha);
	std::cout << "Default (10 == 10): " << (10 == 10) << std::endl; // displays 1
	std::cout << "Default (10 == 20): " << (10 == 20) << std::endl; // displays 0

	std::cout << "========== Integers ================================" << std::endl;
	int num {255};
	
	std::cout << std::dec << num << std::endl; // Decimal
	std::cout << std::hex << num << std::endl; // Hexadecimal
	std::cout << std::oct << num << std::endl; // Octal
	
	std::cout << std::showbase; // Display the base
	std::cout << std::dec << num << std::endl; // Decimal
	std::cout << std::hex << num << std::endl; // Hexadecimal
	std::cout << std::oct << num << std::endl; // Octal

	std::cout << std::showbase << std::uppercase; // Show hexacedimal in uppercase
	std::cout << std::hex << num << std::endl; // Hexadecimal
	
	std::cout << std::showpos; // Display + sign for positive numbers
	std::cout << std::dec << num << std::endl; // Decimal
	std::cout << std::hex << num << std::endl; // Hexadecimal
	std::cout << std::oct << num << std::endl; // Octal	
	// For integers also the std.setf() manipulator can be used 
	// cout.setf(std::ios::showbase) or resetioflags(std::ios::showbase)
	std::cout << "========== Floating  ================================" << std::endl;
	double num1 {123456789.987654321};
	double num2 {1234.5678};
	double num3 {1234.0};
	
	// Defaults (precision 6 = 6 numbers in total are displayed including left and right side of the decimal separator)
	std::cout << "Default num1: "<< num1 << std::endl;
	std::cout << "Default num2: "<< num2 << std::endl;
	std::cout << "Default num3: "<< num3 << std::endl;
	
	// Set precision 5 numbers in total are displayed including left and right side of the decimal separator
	std::cout << std::setprecision(5);
	std::cout << "Precision 5 num1: "<< num1 << std::endl;
	std::cout << "Precision 5 num2: "<< num2 << std::endl;
	std::cout << "Precision 5 num3: "<< num3 << std::endl;
	
	// Using fixed the precision now only applies after the decimal
	std::cout << std::setprecision(3) << std::fixed;
	std::cout << "Precision 3 (fixed) num1: "<< num1 << std::endl;
	std::cout << "Precision 3 (fixed)  num2: "<< num2 << std::endl;
	std::cout << "Precision 3 (fixed)  num3: "<< num3 << std::endl;
	
	// Scientific notation
	std::cout << std::setprecision(3) << std::scientific;
	std::cout << "Precision 3 (scientific) num1: "<< num1 << std::endl;
	std::cout << "Precision 3 (scientific)  num2: "<< num2 << std::endl;
	std::cout << "Precision 3 (scientific)  num3: "<< num3 << std::endl;
	
	
	return 0;
}