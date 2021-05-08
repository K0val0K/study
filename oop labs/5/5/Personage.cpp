#include "Personage.h"

Personage::Personage(std::string nm) : 
	name(nm),
	luck_attack(0),
	luck_defence(0),
	health(100),
	weapon_attack(NULL),
	weapon_guard(NULL)
{
}


void Personage::Attack(Personage* enemy)
{
	int attack_power = 0;
	if (weapon_attack != NULL) {
		attack_power = weapon_attack->Strike();

		if (attack_power != 0) {
			luck_attack += rand() % (2 * attack_power) - attack_power;
			luck_attack /= 2;
		}
	}
	enemy->Guard(luck_attack + attack_power);
}

void Personage::Guard(int attack_power)
{
	int defence_power = 0;
	if (weapon_guard != NULL) {
		defence_power = weapon_guard->Protect(attack_power);
		if (defence_power != 0) {
			luck_defence += rand() % (2 * defence_power) - defence_power;
			luck_defence /= 2;
		}
	}
	health -= (attack_power - luck_defence);
}

bool Personage::IsDead() {
	return (health <= 0);
}

void Personage::SetWeaponAttack(Weapon* w)
{
   weapon_attack = w;
}

void Personage::SetWeaponGuard(Weapon* w)
{
	weapon_guard = w;
}

int Personage::getHealth()
{
	return health;
}

Personage::~Personage() {
	if (weapon_attack != NULL) delete weapon_attack;
	if (weapon_guard != NULL) delete weapon_guard;
}
