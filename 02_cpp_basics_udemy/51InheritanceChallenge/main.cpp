#include <iostream>
#include <vector>
#include "AccountUtil.h"

using namespace std;

int main()
{
	cout.precision(2);
	cout << fixed;
	
	// Accounts
	vector<Account> accounts;
	accounts.push_back(Account{});
	accounts.push_back(Account{"Larry"});
	accounts.push_back(Account{"Moe", 2000});
	accounts.push_back(Account{"Curly", 5000});
	
	display(accounts);
	deposit(accounts, 1000);
	withdraw(accounts, 2000);
	
	// Savings
	vector<SavingsAccount> sav_accounts;
	sav_accounts.push_back(SavingsAccount{});
	sav_accounts.push_back(SavingsAccount{"Superman"});
	sav_accounts.push_back(SavingsAccount{"Batman", 2000});
	sav_accounts.push_back(SavingsAccount{"Wonderwoman", 5000, 5});
	
	display(sav_accounts);
	deposit(sav_accounts, 1000);
	withdraw(sav_accounts, 2000);
	
	
	// Checking
	vector<CheckingAccount> chk_accounts;
	chk_accounts.push_back(CheckingAccount{});
	chk_accounts.push_back(CheckingAccount{"Superman"});
	chk_accounts.push_back(CheckingAccount{"Batman", 2000});
	chk_accounts.push_back(CheckingAccount{"Wonderwoman", 5000});
	
	display(chk_accounts);
	deposit(chk_accounts, 1000);
	withdraw(chk_accounts, 2000);
	
	// Trust
	vector<TrustAccount> trust_accounts;
	trust_accounts.push_back(TrustAccount{});
	trust_accounts.push_back(TrustAccount{"Larry"});
	trust_accounts.push_back(TrustAccount{"Moe", 2000});
	trust_accounts.push_back(TrustAccount{"Curly", 5000, 5});
	
	display(trust_accounts);
	deposit(trust_accounts, 1000);
	withdraw(trust_accounts, 100);
	withdraw(trust_accounts, 100);
	withdraw(trust_accounts, 100);
	withdraw(trust_accounts, 100);
	return 0;
}
