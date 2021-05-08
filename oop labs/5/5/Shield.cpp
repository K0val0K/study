#include "Shield.h"

Shield::Shield() : Weapon(5,30) {
	Weapon::name = "Shield";
}

//int Shield::Strike()
//{
//	int generated = rand() % Weapon::blow_power;
//	Weapon::blow_power -= generated / 10;
//	return generated;
//}
//
//int Shield::Protect(int power)
//{
//	int generated = rand() % Weapon::protect_power;
//	protect_power -= generated / 10;
//	if (power - generated > 0) {
//		return power - generated;
//	}
//	else {
//		return 0;
//	}
//}
