#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"


class SavingsAccount : public Account
{
public:
	double int_rate;
	SavingsAccount();
	~SavingsAccount();
	void deposit(double amount);
	void withdraw(double amount);

};

#endif // SAVINGSACCOUNT_H
