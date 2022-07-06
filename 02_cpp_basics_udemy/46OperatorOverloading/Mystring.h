#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring
{
private:
	char *str; // A pointer to char[] that holds a C-style string
public:
	Mystring(); // No-args constructor
	Mystring(const char *s); // Overloaded constructor
	Mystring(const Mystring &source); // Copy constructor
	Mystring(Mystring &&source); // Move constructor
	~Mystring();
	
	Mystring &operator=(const Mystring &rhs); // Copy assignment
	Mystring &operator=(Mystring &&rhs); // Move assignment
	
	Mystring operator-() const;		  // Make lowercase
	Mystring operator+(const Mystring &rhs) const; // Concatenate
	bool operator==(const Mystring &rhs) const;
	
	void display() const;
	int get_length() const; // Getters
	const char *get_str() const;

};

#endif // MYSTRING_H

