#include <iostream>
#include <string>

class User
{
    std::string status;

public:
    std::string first_name;
    std::string last_name;
    // static member
    static int user_count;

    // static method
    static int get_user_count()
    {
        // static methods can only access other static methods or members
        return user_count;
    }

    User(std::string first_name, std::string last_name, std::string status)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->set_status(status);
        User::user_count++;
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

// static members must be initialized somewhere outside the class definition
int User::user_count = 0;

int main()
{
    User user1("Cristian", "Murillo", "Gold");
    User user2("Andres", "Albornoz", "Silver");
    std::cout << User::get_user_count() << " users created." << std::endl;
    return 0;
}