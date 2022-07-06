#include "Player.h"

int Player::num_players{0};

Player::Player(std::string name_val, int health_val, int xp_val)
	:name{name_val}, health{health_val}, xp{xp_val} {
	++num_players; // Increase by 1 the value of num_players everytime an instance is created
}

Player::Player(const Player &source)
	:Player(source.name, source.health, source.xp){
}


Player::~Player()
{
	--num_players; // Decrease by 1 the value of num_players everytime an instance is destroyed
}

int Player::get_num_players()
{
	return num_players;
}