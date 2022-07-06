#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>


class Account
{
private:
	static constexpr const char *def_name = "Unnamed Account";
	static constexpr double def_balance = 0.0;
protected:
	std::string name;
	double balance;
public:
	Account(std::string name=def_name, double balance=def_balance);
	~Account() = default;
	bool deposit(double amount);
	bool withdraw(double amount);
};

#endif // ACCOUNT_H
