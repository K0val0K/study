#include "Combat.h"
#include<iostream>
Combat::Combat() : warrior(new Warrior("warrior")), monster(new Monster("monster")), attack_player(NULL), defence_player(NULL)
{
}

Combat::~Combat()
{
	delete warrior;
	delete monster;
}

void Combat::Start()
{
	std::string player_name;
	std::cout << "Hello, what is your name?\n";
	std::getline(std::cin,player_name);
	//std::cin.ignore(32767, '\n');
	std::cout <<"OK, " << player_name << " Choose your fighter 1.Monster 2.Warrior\n";
	char input;
	std::cin.get(input);
	std::cin.ignore(32767, '\n');
		while (!(input == '1' || input == '2')) {
			std::cout << "Choose correct!\n";
			std::cin.get(input);
			std::cin.ignore(32767, '\n');
		}

	Personage* player,*bot;
	if (input == '1') {
		player = warrior;
		bot = monster;
	}
	else { 
		player = monster; 
		bot = warrior; 
	}

	if (rand() % 2 == 0) {
		attack_player = player;
		defence_player = bot;
	}
	else {
		attack_player = bot;
		defence_player = player;
	}
	int player_health = player->getHealth();
	int bot_health = bot->getHealth();
	int move_number = 0;
	while (!player->IsDead() && !bot->IsDead()) {
		move_number++;
		std::cout << "Move_number " << move_number << ":  ";
		attack_player == player ? std::cout << "player attacks. " : std::cout << "bot attacks. ";
		std::cout << "player_health:" << player_health << " bot health:" << bot_health << std::endl;
		attack_player->Attack(defence_player);
		attack_player == player ? std::cout << "player dealt: " << bot_health - defence_player->getHealth() << " damage\n": 
			std::cout << "bot dealt " << player_health - defence_player->getHealth() << " damage\n";
		player_health = player->getHealth();
		bot_health = bot->getHealth();
		std::swap(attack_player, defence_player);
	}
	if (player->IsDead()) {
		std::cout << "You are dead\n";
	}
	else {
		std::cout << "You win\n";
	}



}
