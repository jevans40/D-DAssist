#pragma once
#include <string>
#include <vector>
#include "Weapon.h"

class Mob {
private:
	Weapon killBro;
	int health;
	int healthleft;
	int hitDie;
	int Exp;
	int level;
	int ac;

	int will;
	int ref;
	int fort;


	bool boss = false;
	bool magical = false;

	std::string name;
	std::string race;

	static std::vector<std::string> Strong;
	static std::vector<std::string> Average;
	static std::vector<std::string> Weak;
	static std::vector<std::string> Magical;
	static std::vector<std::string> Title;
	static std::vector<std::string> Elf;
	static std::vector<std::string> Orc;
	static std::vector<std::string> HumanM;
	static std::vector<std::string> HumanW;
	static std::vector<std::string> Hobbit;
	static std::vector<std::string> Monster;

public:

	Mob();
	Mob(int lvl, Weapon w, int grade = 1, int hitdie = 10, std::string race = "Bunny", bool bossman = false, bool magicalman = false);

	//Prints out the weapons stats
	void Mob::Stats();
	void Mob::Roll();

	const std::string Mob::getName();

	const Weapon* Mob::getWeapon();

	const int Mob::getHitDie();

	const void Mob::getAttack();

	const int Mob::getHealth();

	const int Mob::getHealthLeft();

	const int Mob::getAC();

	void Mob::setHealthLeft(int newHealth =  0);


	static void Mob::Init();

	std::string Mob::makeName();
};