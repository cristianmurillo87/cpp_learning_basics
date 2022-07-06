#ifndef TRUSTACCOUNT_H
#define TRUSTACCOUNT_H
#include "SavingsAccount.h"


class TrustAccount : public SavingsAccount
{
private:
	static constexpr const char *def_name = "Unnamed Trust Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0;
	static constexpr const double max_pctg_withd = 0.2;
	static constexpr const int max_withdrawals = 3;
	static constexpr double min_bonus_deposit = 5000.0;
	static constexpr double bonus = 50.0;
protected:
	int count_withdrawals;
public:
	TrustAccount(std::string=def_name, double balance=def_balance, double int_rate=def_int_rate);
	virtual ~TrustAccount() = default;
	virtual bool deposit(double amount) override;
	virtual bool withdraw(double amount) override;
	virtual void print(std::ostream &os) const override;
};

#endif // TRUSTACCOUNT_H
