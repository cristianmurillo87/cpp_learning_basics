#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"

using namespace std;

int main()
{
	
	Account *p1 = new SavingsAccount("Curly", 2500);

	Account *p2 = new CheckingAccount("Moe", 540);
	
	Account *p3 = new SavingsAccount("Larry", 2000);
	
	Account *p4 = new TrustAccount("James", 500);
	
	std::vector <Account *> accounts {p1, p2, p3, p4};
	
	display(accounts);
	deposit(accounts, 500);
	withdraw(accounts, 200);
	
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	
	return 0;
}