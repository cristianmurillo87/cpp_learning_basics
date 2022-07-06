#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string name, double balance)
	:Account{name, balance} {
}

bool CheckingAccount::withdraw(double amount)
{
	amount += withdr_fee;
	return Account::withdraw(amount);
}

bool CheckingAccount::deposit(double amount)
{
	return Account::deposit(amount);
}

void CheckingAccount::print(std::ostream &os) const
{
	os.precision(2);
	os << std::fixed;
	os << "[Checking Account: " << name << ": " << balance << "]";
}
