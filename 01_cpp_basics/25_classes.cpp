#include <iostream>
#include <string>
#include <vector>

class User
{
public:
    std::string first_name;
    std::string last_name;
    std::string status;
    std::string get_status()
    {
        return status;
    }
    void set_status(std::string new_status)
    {
        status = new_status;
    }
};

int add_user_if_not_exists(std::vector<User> &users, User new_user)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].first_name == new_user.first_name && users[i].last_name == new_user.last_name)
        {
            std::cout << "Error. The user already exists." << std::endl;
            return 0;
        }
    }

    users.push_back(new_user);
    std::cout << "User added successfully." << std::endl;
    return 1;
}

int main()
{

    User user1;
    user1.first_name = "Cristian";
    user1.last_name = "Murillo";

    std::vector<User> users;
    users.push_back(user1);

    User user2;
    user2.first_name = "Andres";
    user2.last_name = "Albornoz";

    add_user_if_not_exists(users, user2);

    return 0;
}