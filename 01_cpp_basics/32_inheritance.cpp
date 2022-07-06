#include <iostream>
#include <vector>
#include "32_inheritance.h"

Teacher::Teacher()
{
    std::cout << "Teacher created" << std::endl;
}

// Using the super constructor (the constructor of the parent class)
Teacher::Teacher(std::string first_name, std::string last_name, std::string status)
    : User(first_name, last_name, status) {}

// Using the super constructor (the constructor of the parent class)
Teacher::Teacher(std::string first_name, std::string last_name, std::string status, int experience)
    : User(first_name, last_name, status)
{
    this->experience = experience;
}

void Teacher::output()
{
    std::cout << "output" << std::endl;
    /*for (int i = 0; i < this->classes_teaching.size(); i++)
    {
        std::cout << this->classes_teaching[i] << std::endl;
    }*/
}