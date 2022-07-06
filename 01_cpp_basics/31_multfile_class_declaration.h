#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User
{
    std::string status;

public:
    std::string first_name;
    std::string last_name;
    static int user_count;
    User();
    User(std::string first_name, std::string last_name, std::string status);
    ~User();
    static int get_user_count();
    friend void print_status(User user);
    friend std::ostream &operator<<(std::ostream &output, const User user);
    friend std::istream &operator>>(std::istream &input, User &user);
};

#endif