#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"


class CheckingAccount : public Account
{
private:
	static constexpr const char *def_name = "Unnamed Checking Account";
	static constexpr double def_balance = 0.0;
	static constexpr double withdr_fee = 1.5;
public:
	CheckingAccount(std::string name=def_name, double balance=def_balance);
	virtual ~CheckingAccount() = default; // the compiler will provide a default destructor
	virtual bool withdraw(double amount) override;
	virtual bool deposit(double amount) override;
	virtual void print(std::ostream &os) const override;
};

#endif // CHECKINGACCOUNT_H
