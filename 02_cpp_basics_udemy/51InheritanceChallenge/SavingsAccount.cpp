#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string name, double balance, double int_rate)
	:Account{name, balance}, int_rate{int_rate}{
}


bool SavingsAccount::deposit(double amount)
{
	amount *= 1 + (int_rate / 100);
	return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &account)
{
	os << "[Savings Account: " << account.name << ": " << account.balance << ", "<< account.int_rate <<"%]";
	return os;
}