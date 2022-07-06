#include <iostream>
#include <memory>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

int main()
{
	try
	{
		std::unique_ptr<Account> acc1 = std::make_unique<CheckingAccount>("Joe", 100.0);
		std::cout << "Use acc1" << std::endl;
		acc1->withdraw(200.0);
	}
	catch(const IllegalBalanceException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const InsufficientFundsException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}