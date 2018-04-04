#pragma once
#include <string>
#include <vector>

class Weapon {

private:
	int attack;
	int hitDie;
	int numDie;
	int grade;
	bool magical = false;

	std::string name;
	std::string type;

	static std::vector<std::string> Bad;
	static std::vector<std::string> Average;
	static std::vector<std::string> Good;
	static std::vector<std::string> Godly;
	static std::vector<std::string> Magical;
	
public:

	Weapon(int Grade = 1, int Hitdie = 2, std::string type = "carrot");

	//Prints out the weapons stats
	void Weapon::Stats();
	void Weapon::Roll();

	const std::string Weapon::getName();

	const int Weapon::getHitDie();

	const int Weapon::getNumDie();

	const int Weapon::getAttack();


	static void Weapon::Init();

	std::string Weapon::makeName();
};