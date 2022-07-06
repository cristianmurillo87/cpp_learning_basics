#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

// In this class, the amount supplied to the deposit method will be 
// incremented by (account * int_rate/100) and then the updated amount
// will be deposited


class SavingsAccount: public Account
{
	friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &account);
private:
	static constexpr const char *def_name = "Unnamed Savings Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0;
protected:
	double int_rate;
public:
	SavingsAccount(std::string name=def_name, double balance=def_balance, double int_rate=def_int_rate);
	bool deposit(double amount);
	// Inherits the Account::withdraw method

};

#endif // SAVINGSACCOUNT_H
