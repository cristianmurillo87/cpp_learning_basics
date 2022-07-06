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
	std::string get_name() const // with const the function won't change any attribute value
	{
		return name;
	}
	
	void set_name(std::string name_val)
	{
		name = name_val;
	}
	
	// Overloaded constructors
	Player();
	Player(std::string name_val);
	Player(std::string name_val, int health_val, int xp_val);
	
};

Player::Player()
	:Player{"None", 0, 0} {
}

Player::Player(std::string name_val)
	:Player{name_val, 0, 0} {
}

Player::Player(std::string name_val, int health_val, int xp_val)
	:name{name_val}, health{health_val}, xp{xp_val} {
}

void display_player_name(const Player &p)
{
	cout << p.get_name() << endl;
}

int main()
{
	
	const Player villain {"Villain", 100, 55};
	Player hero {"Hero", 100, 15};
	
	display_player_name(villain);
	display_player_name(hero);
	
	
	return 0;
}