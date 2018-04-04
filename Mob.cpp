#include "Weapon.h"
#include "RollStat.h"
#include "MiscUtil.h"
#include "FileHandle.h"
#include "Mob.h"
#include <iostream>

using std::cout;



std::vector<std::string> Mob::Strong;
std::vector<std::string> Mob::Average;
std::vector<std::string> Mob::Weak;
std::vector<std::string> Mob::Magical;
std::vector<std::string> Mob::Title;
std::vector<std::string> Mob::Elf;
std::vector<std::string> Mob::Orc;
std::vector<std::string> Mob::HumanM;
std::vector<std::string> Mob::HumanW;
std::vector<std::string> Mob::Hobbit;
std::vector<std::string> Mob::Monster;



Mob::Mob(int lvl, Weapon w, int grade, int hitdie, std::string race, bool bossman, bool magicalman) {
	this->level = lvl;
	this->hitDie = hitdie;

	this->boss = bossman;
	this->magical = magicalman;
	this->killBro = w;
	this->race = race;

	this->ac = Roller::rollDef(grade);

	Roll();
	

}

void Mob::Stats() {
	cout << name << " is a  level " << level << ' ' << race << std::endl;
	cout << "They have " << health << " Health and " << ac << " AC and drop " << Exp << " XP when they die" << std::endl;
	cout << "They also have " << will << " will " << ref << " ref " << fort << "fort" << std::endl;
	cout << "They weild a " << killBro.getName() << " That does " << killBro.getNumDie() << 'd' << killBro.getHitDie() << " and has " << killBro.getAttack() << " attack\n" << std::endl;

}

void Mob::Init() {

	Strong = GetFileStringList("Names/Names/Title/Strong.txt");
	Average = GetFileStringList("Names/Names/Title/Average.txt");
	Weak = GetFileStringList("Names/Names/Title/Weak.txt");
	Magical = GetFileStringList("Names/Names/Title/Magical.txt");
	Title = GetFileStringList("Names/Names/Title/Title.txt");
	Elf = GetFileStringList("Names/Names/Race/Elf.txt");
	HumanM = GetFileStringList("Names/Names/Race/HumanM.txt");
	HumanW = GetFileStringList("Names/Names/Race/HumanW.txt");
	Orc = GetFileStringList("Names/Names/Race/Orc.txt");
	Hobbit = GetFileStringList("Names/Names/Race/Hobbit.txt");
	Monster = GetFileStringList("Names/Names/Race/Monster.txt");
}

void Mob::Roll() {
	if (boss) {
		this->health = Roller::rollBossHealth(level, hitDie);
		this->Exp = Roller::rollXP(level)*10;

		this->will = Roller::getRand(20 + level*2);
		this->ref = Roller::getRand(20 + level*2);
		this->fort = Roller::getRand(20 + level*2);
	}
	else {

	this->will = Roller::getRand(20+level);
	this->ref = Roller::getRand(20+level);
	this->fort = Roller::getRand(20 +level);
	this->health = Roller::rollMobHealth(level, hitDie);
	this->Exp = Roller::rollXP(level);
	}



	name = makeName();
}

std::string Mob::makeName() {
	std::string mobname;

	if (boss) {
		if (race == "Orc") {
			mobname += Orc[Roller::getRand(Orc.size())] + " The " + Title[Roller::getRand(Title.size())];
		}
		else if (race == "HumanM") {
			mobname += HumanM[Roller::getRand(HumanM.size())] + " The " + Title[Roller::getRand(Title.size())];
		}
		else if(race == "HumanW") {
			mobname += HumanW[Roller::getRand(HumanW.size())] + " The " + Title[Roller::getRand(Title.size())];
		}
		else if (race == "Elf") {
			mobname += Elf[Roller::getRand(Elf.size())] + " The " + Title[Roller::getRand(Title.size())];
		}
		else if (race == "Hobbit") {
			mobname += Hobbit[Roller::getRand(Hobbit.size())] + " The " + Title[Roller::getRand(Title.size())];
		}
		else {
			mobname += Monster[Roller::getRand(Monster.size())] + " The " + Title[Roller::getRand(Title.size())];
		}
		
	}
	else {
		if (level < 7) {
			mobname += Weak[Roller::getRand(Weak.size())];
		}
		else if (level < 15) {
			mobname += Average[Roller::getRand(Average.size())];
		}
		else {
			mobname += Strong[Roller::getRand(Strong.size())];
		}

		if (race == "Orc") {
			mobname += "Orc";
		}
		else if(race == "HumanM") {
			mobname += "HumanM";
		}
		else if (race == "HumanW") {
			mobname += "HumanW";
		}
		else if (race == "Elf") {
			mobname += "Elf";
		}
		else if(race == "Hobbit") {
			mobname += "Hobbit";
		}
		else {
			mobname += "Monster";
		}
	}
	return mobname;
}


const int Mob::getHitDie() {
	return Mob::hitDie;
}


const void Mob::getAttack() {
	killBro.Stats();
}

const int Mob::getHealth() {
	return health;
}

const int Mob::getHealthLeft() {
	return healthleft;
}

void Mob::setHealthLeft(int newHealth) {
	healthleft = newHealth;
}

const std::string Mob::getName() {
	return name;
}

const Weapon* Mob::getWeapon() {
	return &killBro;
}

const int Mob::getAC() {
	return ac;
}