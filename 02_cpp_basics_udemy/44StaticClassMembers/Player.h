#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
private:
	static int num_players; // static to count how many instances of the class are created and active
	std::string name;
	int health;
	int xp;
public:
	std::string get_name() {return name;}
	int get_health() {return health;}
	int get_xp() {return xp; }
	Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
	// Copy constructor
	Player(const Player &source);
	// Destructor
	~Player();
	
	static int get_num_players(); // Only has access to static variables of the class

};

#endif // PLAYER_H
