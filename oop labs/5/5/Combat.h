#pragma once

#include "Personage.h"
#include "Monster.h"
#include "Warrior.h"
class Combat
{
	Personage* warrior; //игрок 1
	Personage* monster; //игрок 2
	Personage* attack_player; //атакующий игрок
	Personage* defence_player; //защищающийся игрок
public:
	Combat();
	~Combat();
	void Start();
};

