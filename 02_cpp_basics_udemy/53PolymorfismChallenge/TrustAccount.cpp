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

void TrustAccount::print(std::ostream &os) const
{
	os.precision(2);
	os << std::fixed;
	os << "[Trust Account: " << name << ": " << balance << ", "<< int_rate << "%, withdrawals: " << count_withdrawals << "]";
}
