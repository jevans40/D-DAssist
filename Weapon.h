#pragma once
#include <string>

class Weapon {
private:
	int Attack;
	int HitDie;
	int NumDie;
	std::string Grade;
	
public:

	Weapon();
	Weapon(int Grade = 1, int Hitdie = 2);

	//Prints out the weapons stats
	void Weapon::Stats();
	void Weapon::Roll();
};