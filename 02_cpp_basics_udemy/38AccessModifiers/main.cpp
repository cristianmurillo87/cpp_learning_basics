#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
	string name {"Player"};
	int health;
	int xp;
public:
	void talk(string text_to_say)
	{
		cout << name << " says " << text_to_say << endl;
	}
	
	bool is_dead();
};

int main()
{
	Player frank;
	frank.name = "Franky" //	Error, attribute name is private
	frank.talk("Hello there"); // OK, talk is a public method
	return 0;
}