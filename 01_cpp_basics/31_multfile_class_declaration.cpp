#include <iostream>
#include <string>
#include "31_multfile_class_declaration.h"

int User::user_count = 0;

User::User()
{
    std::cout << "user created" << std::endl;
}

User::User(std::string first_name, std::string last_name, std::string status)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->status = status;
    User::user_count++;
}

User::~User()
{
    User::user_count--;
}

int User::get_user_count()
{
    return user_count;
}

void print_status(User user)
{
    std::cout << user.status;
}

std::ostream &operator<<(std::ostream &output, const User user)
{
    // using the friend function
    output << "First Name: " << user.first_name << " Last Name: " << user.last_name << " Status: " << user.status;
    return output;
}

std::istream &operator>>(std::istream &input, User &user)
{
    input >> user.first_name >> user.last_name >> user.status;
    return input;
}