#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
	std::string name;
	int health;
	int xp;
public:
//Overloaded Constructors
	Player();
	Player(std::string name);
	Player(std::string name, int health_val, int xp_val);
};

Player::Player()
	:name{"None"}, health{0}, xp{0}{
}

Player::Player(std::string name_val)
	:name{name_val}, health{0}, xp{0}{
}

Player:.Player(std::string name_val, int health_val, int xp_value)
	:name{name_val}, health{health_val}, xp{xp_value}{
}

int main()
{
	Player empty;
	Player frank {"Frank"};
	Player villain {"Villain", 100, 55};
	
	return 0;
}