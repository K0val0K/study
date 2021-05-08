#pragma once
#include<string>
#include "Club.h"
#include "Shield.h"
#include "Sword.h"

class Personage
{
protected:
	//имя
	std::string name;
	//удача в атаке
	int luck_attack;
	//удача в защите
	int luck_defence;
	//здоровье
	int health;
	//оружие нападения
	Weapon* weapon_attack;
	//оружие защиты
	Weapon* weapon_guard;
public:
	Personage(std::string);
	virtual void Attack(Personage*);
	virtual void Guard(int);
	//false – игрок еще жив, иначе true
	bool IsDead(); 

	//установить оружие атаки
	void SetWeaponAttack(Weapon* w);
	
	//установить оружие защиты
	void SetWeaponGuard(Weapon* w);

	int getHealth();
	
	virtual ~Personage();
		
	
};

