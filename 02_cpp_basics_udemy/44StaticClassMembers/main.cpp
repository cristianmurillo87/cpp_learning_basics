#include <iostream>
#include "Player.h"

using namespace std;

void display_active_players()
{
	cout << "Active Players: " << Player::get_num_players() << endl;
}

int main()
{
	display_active_players(); // 0 Active players
	Player hero {"Hero"};
	display_active_players(); // 1 Active players
	
	{
		Player frank {"Frank"};
		display_active_players(); // 2 Active players (the local Player will be destroyed after reaching the end of the scope)
	}
	
	display_active_players(); // 1 Active players
	
	Player *enemy = new Player("Enemy", 100, 100);
	display_active_players(); // 2 Active players
	delete enemy;
	display_active_players(); // 1 Active players
	
	return 0;
}