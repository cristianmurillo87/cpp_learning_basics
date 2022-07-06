#include <cstring>
#include <iostream>
#include "Mystring.h"

Mystring::Mystring()
	:str{nullptr} {
	str = new char[1];
	*str = '\0'; // Assign the value '\0' (null terminator) to the memory location referenced by the pointer
}

// Overloaded constructor
Mystring::Mystring(const char *s)
	:str{nullptr} {
	if(s == nullptr)
	{
		str = new char[1];
		*str = '\0';
	} else {
		str = new char[std::strlen(s) + 1];
		std::strcpy(str, s);
	}
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
	:str{nullptr} {
	str = new char[std::strlen(source.str) + 1];
	std::strcpy(str, source.str);
	std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source)
	:str(source.str) {
	source.str = nullptr;
	std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring()
{
	if(str == nullptr)
	{
		std::cout << "Calling destructor for Mystring : nullptr" << std::endl;
	} else {
		std::cout << "Calling destructor for Mystring : " << str << std::endl;
	}
	delete [] str;
}

// Display method
void Mystring::display() const {
	std::cout << str << " : " << get_length() << std::endl;
}


// Copy assignment
Mystring &Mystring::operator =(const Mystring &rhs)
{
	std::cout << "Copy assignment" << std::endl;
	if(this == &rhs)
		return *this;
	delete [] this->str;
	str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(this->str, rhs.str);
	return *this;
}

// Move assignment
Mystring &Mystring::operator =(Mystring &&rhs)
{
	std::cout << "Using move assignment" << std::endl;
	if(this == &rhs)
		return *this;
	delete [] str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}

// Equality
bool Mystring::operator ==(const Mystring &rhs) const
{
	return (std::strcmp(str, rhs.str) == 0);
}

// Make lowercase
Mystring Mystring::operator -() const
{
	char *buff = new char[std::strlen(str) + 1];
	std::strcpy(buff, str);
	for(size_t i = 0; i < std::strlen(buff); i++)
		buff[i] = std::tolower(buff[i]);
	Mystring temp{buff};
	delete [] buff;
	return temp;
}

// Concatenate
Mystring Mystring::operator +(const Mystring &rhs) const
{
	char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
	std::strcpy(buff, str);
	std::strcat(buff, rhs.str);
	Mystring temp{buff};
	delete [] buff;
	return temp;
}


// Length getter
int Mystring::get_length() const {return std::strlen(str);}

// String getter
const char *Mystring::get_str() const { return str;}