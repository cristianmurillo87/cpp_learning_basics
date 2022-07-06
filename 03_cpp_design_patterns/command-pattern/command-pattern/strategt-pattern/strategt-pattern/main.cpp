//
//  main.cpp
//  strategt-pattern
//
//  Created by Cristian on 16/04/22.
//

#include <iostream>

class GreetingStrategy
{
public:
    virtual void greet(const std::string &name) = 0;
};

class FormalGreetingStrategy: public GreetingStrategy
{
public:
    void greet(const std::string &name)
    {
        std::cout << "Good morning, " << name << ", how do you do?\n";
    }
};

class NormalGreetingStrategy: public GreetingStrategy
{
public:
    void greet(const std::string &name)
    {
        std::cout << "Hi, " << name << ", how are you?\n";
    }
};

class InformalGreetingStrategy: public GreetingStrategy
{
public:
    void greet(const std::string &name)
    {
        std::cout << "Hey, " << name << ", what's up?\n";
    }
};

class Person
{
    GreetingStrategy *greeting_strategy;
public:
    Person(GreetingStrategy *greeting_strategy)
    :greeting_strategy(greeting_strategy) {};
    
    ~Person() {delete greeting_strategy;};
    
    void greet(const std::string &name)
    {
        greeting_strategy->greet(name);
    }
};

int main(int argc, const char * argv[]) {
    Person business_person(new FormalGreetingStrategy());
    Person normal_person(new NormalGreetingStrategy());
    Person cool_person(new InformalGreetingStrategy());
    Person politian(new FormalGreetingStrategy());
    
    std::cout << "The business person says: ";
    business_person.greet("Cris");
    
    std::cout << "The normal person says: ";
    normal_person.greet("Cris");
    
    std::cout << "The cool person says: ";
    cool_person.greet("Cris");
    
    std::cout << "The politian says: ";
    politian.greet("Cris");
    
    return 0;
}
