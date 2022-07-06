#include <iostream>
#include <string>

class User
{
    std::string status;

public:
    std::string first_name;
    std::string last_name;

    User(std::string first_name, std::string last_name, std::string status)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->status = status;
    }

    ~User()
    {
        std::cout << "User destroyed: " << this->first_name << std::endl;
    }

    std::string get_status()
    {
        return this->status;
    }

    void set_status(std::string status)
    {
        if (status == "Gold" || status == "Silver" || status == "Bronze")
        {
            this->status = status;
        }
        else
        {
            std::cout << "Error: " << status << " is not a valid value." << std::endl;
        }
    }
};

// Overload the insertion operator (<<)
// This operator is used to print in the console
// std::cout is of type std::ostream and must be passed by reference
// the operator must also return an object if type std::ostream (as reference)
// the other argument of the function must be the object to be printed,
// such argument is defined as constant to assure it won't be modified inside the function
// this method has no access to private properties of the object
std::ostream &operator<<(std::ostream &output, const User user)
{
    output << "First Name: " << user.first_name << " Last Name: " << user.last_name;
    return output;
}

// Overload the asignation operator (>>)
// Used to assign properties for objects from the console
// it functions in a similar way as the overloaded insertion operator
// the second argument (the object the given properties are going to be assigned to)
// must also be passed as reference
// this method has no access to private properties of the object
std::istream &operator>>(std::istream &input, User &user)
{
    input >> user.first_name >> user.last_name;
    return input;
}

int main()
{
    User user1("Cristian", "Murillo", "Gold");
    std::cout << user1 << std::endl;

    User user2("", "", "Golden");
    std::cin >> user2;
    std::cout << user2 << std::endl;
    return 0;
}