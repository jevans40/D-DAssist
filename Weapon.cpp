#include "Weapon.h"
#include "RollStat.h"
#include "MiscUtil.h"
#include "FileHandle.h"
#include <iostream>

using std::cout;



std::vector<std::string> Weapon::Bad;
std::vector<std::string> Weapon::Average;
std::vector<std::string> Weapon::Good;
std::vector<std::string> Weapon::Godly;
std::vector<std::string> Weapon::Magical;

Weapon::Weapon() {
	cout << "Please input a item type";
	std::string n;
	cin >> n;
	cout << "Please input a Grade (1-8)";
	int newGrade;
	std::cin >> newGrade;
	cout << "Please input a HitDie";
	int hit;
	std::cin >> hit;
	hitDie = hit;
	type = n;
	grade = newGrade;
	if (Roller::getRand(100) >= 95) {
		magical = true;
	}
	Roll();
}

Weapon::Weapon(int Grade, int HitDie, std::string type) {
	grade = Grade;
	hitDie = HitDie;
	this->type = type;
	Roll();
}

void Weapon::Stats() {
	cout << name << " is a " << numDie << "d" << hitDie << " " << type << " With " << attack << " attack \n" <<std::endl;
}

void Weapon::Init() {

	Good = GetFileStringList("Names/Weapon/WG.txt");
	Godly = GetFileStringList("Names/Weapon/WGod.txt");
	Bad = GetFileStringList("Names/Weapon/WB.txt");
	Average = GetFileStringList("Names/Weapon/WA.txt");
	Magical = GetFileStringList("Names/Weapon/WM.txt");
}

void Weapon::Roll() {
	attack = Roller::rollAtt(grade);
	numDie = Roller::rollWeapon(grade, hitDie)/hitDie;
	name = getName();

}

std::string Weapon::getName() {
	std::string mods;
	if(grade == 1) {
		mods = Bad[Roller::getRand(Bad.size())] + " " + Bad[Roller::getRand(Bad.size())] + " " + Util::getGrade(grade);
	}
	else if (grade == 2) {
		mods = Bad[Roller::getRand(Bad.size())] + " " + Average[Roller::getRand(Average.size())] + " " + Util::getGrade(grade);
	}
	else if (grade == 3) {
		mods = Average[Roller::getRand(Average.size())] + " " + Average[Roller::getRand(Average.size())] + " " + Util::getGrade(grade);
	}
	else if (grade == 4) {
		mods = Average[Roller::getRand(Average.size())] + " " + Util::getGrade(grade);
	}
	else if (grade == 5) {
		mods = Average[Roller::getRand(Average.size())] + " " + Good[Roller::getRand(Good.size())] + " " + Util::getGrade(grade);
	}
	else if (grade == 6) {
		mods = Good[Roller::getRand(Good.size())] + " " + Good[Roller::getRand(Good.size())] + " " + Util::getGrade(grade);
	}
	else if (grade == 7) {
		mods = Good[Roller::getRand(Good.size())] + " " + Godly[Roller::getRand(Godly.size())] + " " + Util::getGrade(grade);
	}
	else if (grade == 8) {
		mods = Godly[Roller::getRand(Godly.size())] + " " + Godly[Roller::getRand(Godly.size())] + " " + Util::getGrade(grade);
	}
	else {
		mods = Bad[Roller::getRand(Bad.size())] + " " + Bad[Roller::getRand(Bad.size())] + " " + Util::getGrade(grade) + " " + Bad[Roller::getRand(Bad.size())] + " " + Bad[Roller::getRand(Bad.size())] + " " + Util::getGrade(grade);
	}
	if (magical) {
		mods += Magical[Roller::getRand(Magical.size())];
	}
	mods += " " + type;
	return mods;
}