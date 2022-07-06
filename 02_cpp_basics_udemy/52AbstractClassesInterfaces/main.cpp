#include <iostream>
#include <vector>
/*	
 * 	Static binding : definition of the type of the classes on compilation
 * 	Dynamic binding : definition of the type of the classes on runtime
 *	Abstract classes : classes that are to general to be instantiated, only a template for derived classes (upper level in inheritance)
 * 	Interfaces : similar to abstract classes in C++ (different concept in languajes like Java)
 * 	Pure virtual functions : functions without implementation and after definition they are made equal to zero (=0) and 
 *	must be implemented (overriden) in the derived classes
 * 	virtual keyword : used to create functions in the base class that are goint to be overriden in the derived classes
 * 	only implement dymanic binding when called from a base class pointer or reference, otherwise statically binding is used
 * 	override keyworkd : used to indicate that a function overrides the implementation defined in the base class
 * 	final keyworkd : used to stop allowing further overriding in derived classes
 */
 
class I_Printable
{
	friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
	virtual void print(std::ostream &os) const = 0; // Pure virtual function (with = 0) used to define abstract classes or interfaces
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
	obj.print(os);
	return os;
}

class Account : public I_Printable
{
public:
	virtual void withdraw(double amount)
	{
		std::cout << "In Account::withdraw" << std::endl;
	}
	
	virtual void print(std::ostream &os) const override
	{
		os << "Account display";
	}
	
	// Every class with a virtual function MUST have a virtual destructor
	virtual ~Account() {}
};


class Savings : public Account
{
public:
	virtual void withdraw(double amount) override
	{
		std::cout << "In Savings withdraw" << std::endl;
	}
	
	virtual void print(std::ostream &os) const override
	{
		os << "Savings display";
	}

	virtual ~Savings() {}
};


class Checking : public Account
{
public:
	virtual void withdraw(double amount) override
	{
		std::cout << "In Checking withdraw" << std::endl;
	}
	
	virtual void print(std::ostream &os) const override
	{
		os << "Checking display";
	}

	virtual ~Checking() {}
};


class Trust : public Account
{
public:
	virtual void withdraw(double amount) override
	{
		std::cout << "In Trust withdraw" << std::endl;
	}
	
	virtual void print(std::ostream &os) const override
	{
		os << "Trust display";
	}
	
	virtual ~Trust() {}
};


int main()
{

	Account *p1 = new Account();
	std::cout << *p1 << std::endl;

	// Base class pointers
	// Defined with the type of the base class (Account)
	// But implemented using a Child (concrete) class (Checking)	
	Account *p2 = new Checking();
	std::cout << *p2 << std::endl;
	
	Account *p3 = new Savings();
	std::cout << *p3 << std::endl;
	
	Account *p4 = new Trust();
	std::cout << *p4 << std::endl;
	
	std::vector <Account *> accounts {p1, p2, p3, p4};
	for(auto acc_ptr : accounts)
		acc_ptr->withdraw(1000);
	
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	
	return 0;
}