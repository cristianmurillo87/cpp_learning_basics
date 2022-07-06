#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"


class CheckingAccount : public Account
{
	friend std::ostream &operator<<(std::ostream &os, const CheckingAccount &account);
private:
	static constexpr const char *def_name = "Unnamed Checking Account";
	static constexpr double def_balance = 0.0;
	static constexpr double withdr_fee = 1.5;	
public:
	CheckingAccount(std::string name=def_name, double balance=def_balance);
	bool withdraw(double amount);
};

#endif // CHECKINGACCOUNT_H
