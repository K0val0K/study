#pragma once

#include "Personage.h"
#include "Monster.h"
#include "Warrior.h"
class Combat
{
	Personage* warrior; //����� 1
	Personage* monster; //����� 2
	Personage* attack_player; //��������� �����
	Personage* defence_player; //������������ �����
public:
	Combat();
	~Combat();
	void Start();
};

