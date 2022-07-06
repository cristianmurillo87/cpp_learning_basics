#include "TrustAccount.h"


TrustAccount::TrustAccount(std::string name, double deposit, double int_rate)
	:SavingsAccount{name, deposit, int_rate}, count_withdrawals{0} {
}

bool TrustAccount::deposit(double amount)
{
	if(amount >= min_bonus_deposit)
	{
		amount += bonus;
		return SavingsAccount::deposit(amount);
	} else
		return SavingsAccount::deposit(amount);
}

bool TrustAccount::withdraw(double amount)
{
	double max_withd = balance * max_pctg_withd; // 20% of the account balance
	// Maximum 20% of the total balance can be withdrawn and maximum 3 withdrawals per year
	if(count_withdrawals <= max_withdrawals && amount <= max_withd)
	{
		count_withdrawals += 1;
		return SavingsAccount::withdraw(amount);
	} else{
		return false;
	}
}

std::ostream &operator<<(std::ostream &os, const TrustAccount &account)
{
	os << "[Trust Account: " << account.name << ": " << account.balance << ", "<< account.int_rate << "%, withdrawals: " << account.count_withdrawals << "]";
	return os;
}