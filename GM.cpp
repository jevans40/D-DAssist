#include "GM.h"
#include <iostream>
#include "MiscUtil.h"
#include "Mob.h"
#include "Weapon.h"
#include <vector>

std::vector<Mob*>  Mobs;
std::vector<Weapon*>  Weapons;

using std::cin;
using std::cout;

void RunGame() {
	std::string cmd = "lol";
	while (cmd != "exit") {
		cout << "Please enter a command, or exit to exit DM mode" << std::endl;
		cout << "Command: ";
		cin >> cmd;
		gameCommands(cmd);
	}
}


void gameCommands(std::string cmd) {
	if (cmd == "MakeWeapon") {
		gameMakeWeapon();
	}
	else if (cmd == "MakeMob") {
		gameMakeMob();
	}
	else if (cmd == "GetWeapon") {
		cout << "Please enter a weapon Index: ";
		gameGetWeapon(Util::getInt());
	}
	else if (cmd == "GetMob") {
		cout << "Please enter a Mob Index: ";
		gameGetMob(Util::getInt());
	}
	else if (cmd == "DeleteMobs") {
		gameDeleteMobs();
	}
	else if (cmd == "DeleteWeapons") {
		gameDeleteWeapons();
	}
	else if (cmd == "DamageMob") {
		cout << "Please enter a Mob Index , then damage, then attack: ";
		gameDamageMob(Util::getInt(), Util::getInt(), Util::getInt());
	}
}

void gameMakeWeapon() {
	cout << "Please input a item type ";
	std::string n;
	cin >> n;
	cout << "Please input a Grade (1-8) ";
	int newGrade;
	newGrade = Util::getInt();
	cout << "Please input a HitDie ";
	int hit;
	hit = Util::getInt();
	Weapon * w = new Weapon(newGrade, hit, n);
	Weapons.push_back(w);
	cout << "Created new weapon with index " << Weapons.size()-1 << std::endl;
}

void gameMakeMob() {
	cout << "Please enter a Weapon Index: ";
	int weaponIndex = Util::getInt();
	if (Weapons.size() != 0) {
		while (weaponIndex < 0 || weaponIndex >= Weapons.size()) {
			cout << "Your value was not found, please try again: ";
			weaponIndex = Util::getInt();
		}
		cout << "Please input a level: ";
		int level = Util::getInt();
		cout << "Please input a race: ";
		std::string race;
		cin >> race;
		cout << "Please input a armor grade: ";
		int grade = Util::getInt();
		cout << "Please input a hitdie: ";
		int hitdie = Util::getInt();
		cout << "Is this a boss? (0 no, 1 yes) ";
		bool boss = Util::getInt();
		Mob *m = new Mob(level, *Weapons[weaponIndex], grade, hitdie, race, boss, false);
		Mobs.push_back(m);
		cout << "Created new weapon with index " << Mobs.size()-1 << std::endl;
	}
}

void gameGetWeapon(int num) {
	if (num < 0 || num >= Weapons.size()) {
		cout << "We could not find your weapon";
	}
	else {
		Weapons[num]->Stats();
	}
}

void gameGetMob(int num) {
	if (num < 0 || num >= Mobs.size()) {
		cout << "We could not find your mob";
	}
	else {
		Mobs[num]->Stats();
	}
}

void gameDeleteMobs() {
	while (!Mobs.empty()) {
		Mobs.pop_back();
	}
}

void gameDeleteWeapons() {
	while (!Weapons.empty()) {
		Weapons.pop_back();
	}
}

void gameDamageMob(int index, int damage, int attack) {
	if (index >= 0 && index < Mobs.size()) {
		if (Mobs[index]->getAC() > attack) {
			cout << "Your attack failed!";
		}
		else {
			Mobs[index]->setHealthLeft(Mobs[index]->getHealthLeft() - damage);
			cout << Mobs[index]->getName() << " Has " << Mobs[index]->getHealthLeft() << " / " << Mobs[index]->getHealth() << "HP after taking " << damage << " damage \n" << std::endl;
		}
	}
	else {
		cout << "Could not find mob\n";
	}
}