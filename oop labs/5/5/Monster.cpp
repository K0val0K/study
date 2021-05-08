#include "Monster.h"

Monster::Monster(std::string name): Personage(name)
{
	SetWeaponAttack(new Club());
	SetWeaponGuard(new Club());
	luck_defence += 5;
}
