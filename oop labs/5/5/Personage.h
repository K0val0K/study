#pragma once
#include<string>
#include "Club.h"
#include "Shield.h"
#include "Sword.h"

class Personage
{
protected:
	//���
	std::string name;
	//����� � �����
	int luck_attack;
	//����� � ������
	int luck_defence;
	//��������
	int health;
	//������ ���������
	Weapon* weapon_attack;
	//������ ������
	Weapon* weapon_guard;
public:
	Personage(std::string);
	virtual void Attack(Personage*);
	virtual void Guard(int);
	//false � ����� ��� ���, ����� true
	bool IsDead(); 

	//���������� ������ �����
	void SetWeaponAttack(Weapon* w);
	
	//���������� ������ ������
	void SetWeaponGuard(Weapon* w);

	int getHealth();
	
	virtual ~Personage();
		
	
};

