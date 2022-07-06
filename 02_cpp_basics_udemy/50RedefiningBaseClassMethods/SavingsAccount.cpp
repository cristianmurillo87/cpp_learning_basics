#include "SavingsAccount.h"

SavingsAccount::SavingsAccount()
	:SavingsAccount{0.0, 0.0}{
}

SavingsAccount::SavingsAccount(double balance, double int_rate)
	:Account{balance}, int_rate{int_rate}{
}

SavingsAccount::~SavingsAccount()
{
}

void SavingsAccount::deposit(double amount){
	amount = amount + (amount * int_rate/100);
	Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &account)
{
	os << "Savings account balance: " << account.balance << " Interest rate: " << account.int_rate;
	return os;
}