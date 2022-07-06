#include <iostream>
#include <memory>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"


using namespace std;

class Test
{
private:
	int data;
public:
	Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
	Test(int data) : data{data} { std::cout << "\tTest constructor(" << data << ")" << std::endl; }
	int get_data() const { return data; }
	~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

class B; // forward declaration

class A
{
	std::shared_ptr<B> b_ptr;
public:
	void set_B(std::shared_ptr<B> &b)
	{
		b_ptr = b;
	}
	A() { cout << "A constructor" << endl; }
	~A() { cout << "A destructor" << endl; }
};

class B
{
	std::weak_ptr<A> a_ptr;
public:
	void set_A(shared_ptr<A> &a)
	{
		a_ptr = a;
	}
	B() { cout << "B constructor" << endl; }
	~B() { cout << "B destructor" << endl; }
};


void func(std::shared_ptr<Test> p)
{
	std::cout << "Use count: " << p.use_count() << std::endl;
}

void my_deleter(Test *ptr)
{
	std::cout << "\tUsing my custom function deleter" << std::endl;
	delete ptr;
}

int main()
{
	// Raw pointers
	// Test *t1 = new Test{1000};
	// delete t1;
	
	// ================Unique Pointers==============================================================
	// Unique pointer creation
	// std::unique_ptr<Test> t1 {new Test{100}};
	// Unique pointer creation using the make_unique function
	// std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);
	
	// std::unique_ptr<Test> t3;
	// t3 = t1; <- Error : not allowed for unique pointers
	// t3 = std::move(t1);
	// if(!t1)
	//  	std::cout << "t1 is nullptr" << std::endl;
	
	// std::vector<std::unique_ptr<Account>> accounts;
	// accounts.push_back(make_unique<CheckingAccount>("James", 1000));
	// accounts.push_back(make_unique<SavingsAccount>("Billy", 4000, 5.2));
	// accounts.push_back(make_unique<TrustAccount>("Bobby", 5000, 4.5));
	
	// for(const auto &acc : accounts) // By reference because copying is not allowed for unique pointers
		// std::cout << *acc << std::endl;
	
	// ================Shared Pointers==============================================================
	// Can be referenced several times and allow moving and copying
	// std::shared_ptr<int> p1{new int{100}};
	// std::cout << "Use count: " << p1.use_count() << std::endl; // 1

	// std::shared_ptr<int> p2 {p1}; // shared ownership
	// std::cout << "Use count: " << p1.use_count() << std::endl; // 2
	
	// p1.reset(); // decrement the use_count, p1 is nulled out
	// std::cout << "Use count: " << p1.use_count() << std::endl; // 0
	// std::cout << "Use count: " << p2.use_count() << std::endl; // 1
	
	// std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
	// func(ptr);
	
	// std::shared_ptr<Account> acc1 = std::make_shared<TrustAccount>("Bobby", 5000, 4.5);
	// std::shared_ptr<Account> acc2 = std::make_shared<SavingsAccount>("Billy", 4000, 5.2);
	// std::shared_ptr<Account> acc3 = std::make_shared<CheckingAccount>("James", 1000);
	
	// std::vector<std::shared_ptr<Account>> accounts;
	// accounts.push_back(acc1);
	// accounts.push_back(acc2);
	// accounts.push_back(acc3);
	
	// for(const auto &acc : accounts)
	// 
		// std::cout << *acc << std::endl;
		// std::cout << "Use count: " << acc.use_count() << std::endl;
	// }
	
	// ================Weak Pointers=================================================================
	// Created from shared pointers but do not participate in the ownership relationship
	// shared_ptr<A> a = make_shared<A>();
	// shared_ptr<B> b = make_shared<B>();
	// a->set_B(b);
	// b->set_A(a);
	
	// ================Custom Deleters================================================================
	// declaring deleter as parameter when creating the smart pointer
	{
		std::shared_ptr<Test> ptr{new Test{100}, my_deleter};
	}
	// declaring deleter using lambda expressions
	{
		std::shared_ptr<Test> ptr2(new Test{1000}, 
			[] (Test *ptr)
			{
				std::cout << "\tUsing my custom lamda deleter" << std::endl;
				delete ptr;
			});
	}
	
	return 0;
}