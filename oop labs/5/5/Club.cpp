#include "Club.h"

Club::Club():Weapon(35,5) {
	Weapon::name = "Club";
}

//int Club::Strike()
//{
//	int generated = rand() % Weapon::blow_power;
//	Weapon::blow_power -= generated / 10;
//	return generated;
//}
//
//int Club::Protect(int power)
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
