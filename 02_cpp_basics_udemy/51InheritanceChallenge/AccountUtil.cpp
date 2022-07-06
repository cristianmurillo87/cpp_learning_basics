#include <iostream>
#include "AccountUtil.h"

// Utility helper functions for Account class
void display(const std::vector<Account> &accounts)
{
	std::cout << "\n===Accounts======================================" << std::endl;
	for(const auto &acc : accounts)
		std::cout << acc << std::endl;
}


void deposit(std::vector<Account> &accounts, double amount)
{
	
	std::cout << "\n===Depositing to Accounts=========================" << std::endl;
	for(auto &acc: accounts)
	{
		if(acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
	}
}

void withdraw(std::vector<Account> &accounts, double amount)
{
	std::cout << "\n===Withdrawing from Accounts=======================" << std::endl;
	for(auto &acc: accounts)
	{
		if(acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
	}
}


// Utility helper functions for Savings Account class
void display(const std::vector<SavingsAccount> &accounts)
{
	std::cout << "\n===Savings Accounts================================" << std::endl;
	for(const auto &acc : accounts)
		std::cout << acc << std::endl;
}


void deposit(std::vector<SavingsAccount> &accounts, double amount)
{
	
	std::cout << "\n===Depositing to Savings Accounts==================" << std::endl;
	for(auto &acc: accounts)
	{
		if(acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
	}
}


void withdraw(std::vector<SavingsAccount> &accounts, double amount)
{
	std::cout << "\n===Withdrawing from Savings Accounts===============" << std::endl;
	for(auto &acc: accounts)
	{
		if(acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
	}
}


// Utility helper functions for Checking Account class
void display(const std::vector<CheckingAccount> &accounts)
{
	std::cout << "\n===Checking Accounts================================" << std::endl;
	for(const auto &acc : accounts)
		std::cout << acc << std::endl;
}


void deposit(std::vector<CheckingAccount> &accounts, double amount)
{
	
	std::cout << "\n===Depositing to Checking Accounts==================" << std::endl;
	for(auto &acc: accounts)
	{
		if(acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
	}
}


void withdraw(std::vector<CheckingAccount> &accounts, double amount)
{
	std::cout << "\n===Withdrawing from Checking Accounts===============" << std::endl;
	for(auto &acc: accounts)
	{
		if(acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
	}
}


// Utility helper functions for Trust Account class
void display(const std::vector<TrustAccount> &accounts)
{
	std::cout << "\n===Trust Accounts===================================" << std::endl;
	for(const auto &acc : accounts)
		std::cout << acc << std::endl;
}


void deposit(std::vector<TrustAccount> &accounts, double amount)
{
	
	std::cout << "\n===Depositing to Trust Accounts====================" << std::endl;
	for(auto &acc: accounts)
	{
		if(acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
	}
}


void withdraw(std::vector<TrustAccount> &accounts, double amount)
{
	std::cout << "\n===Withdrawing from Trust Accounts=================" << std::endl;
	for(auto &acc: accounts)
	{
		if(acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
	}
}