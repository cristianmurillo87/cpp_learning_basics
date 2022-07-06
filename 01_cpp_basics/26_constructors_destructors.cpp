#include <iostream>
#include <string>

class User
{
    // private
    std::string status;

public:
    std::string first_name;
    std::string last_name;

    // Constructor
    User(std::string first_name, std::string last_name, std::string status)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->status = status;
    }

    // Destructor
    ~User()
    {
        std::cout << "User destroyed: " << this->first_name << std::endl;
    }

    // Getter
    std::string get_status()
    {
        return this->status;
    }

    // Setter
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

int main()
{
    User user1("Cristian", "Murillo", "Gold");
    std::cout << user1.first_name << std::endl;
    return 0;
}