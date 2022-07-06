#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string name, double balance, double int_rate)
	:Account{name, balance}, int_rate{int_rate}{
}


bool SavingsAccount::deposit(double amount)
{
	amount *= 1 + (int_rate / 100);
	return Account::deposit(amount);
}


bool SavingsAccount::withdraw(double amount)
{
	return Account::withdraw(amount);
}

void SavingsAccount::print(std::ostream &os) const
{
	os.precision(2);
	os << std::fixed;
	os << "[Savings Account: " << name << ": " << balance << ", " << int_rate << "%]";
}
