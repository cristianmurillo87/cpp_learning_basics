#include <iostream>
#include <string>

struct User
{
    std::string first_name;
    std::string last_name;
    std::string get_status()
    {
        return status;
    };
    void set_status(std::string new_status)
    {
        status = new_status;
    };

private:
    std::string status;
};

int main()
{
    User me;
    me.first_name = "Cristian";
    me.last_name = "Murillo";
    me.set_status("Gold");

    std::cout << "First Name: " << me.first_name << "\nLast Name: " << me.last_name << "\nStatus: " << me.get_status() << std::endl;
    return 0;
}