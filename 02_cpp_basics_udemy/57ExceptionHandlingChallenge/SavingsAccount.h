#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <iostream>
#include "Account.h"

// In this class, the amount supplied to the deposit method will be 
// incremented by (account * int_rate/100) and then the updated amount
// will be deposited


class SavingsAccount: public Account
{
private:
	static constexpr const char *def_name = "Unnamed Savings Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0;
protected:
	double int_rate;
public:
	SavingsAccount(std::string name=def_name, double balance=def_balance, double int_rate=def_int_rate);
	virtual ~SavingsAccount() = default;
	virtual bool deposit(double amount) override;
	virtual bool withdraw(double amount) override;
	virtual void print(std::ostream &os) const override;
};

#endif // SAVINGSACCOUNT_H
