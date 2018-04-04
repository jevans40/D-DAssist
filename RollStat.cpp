#include "RollStat.h"
#include <chrono>
#include <iostream>


double Roller::getDis(double mod) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	if (mod <= 0) {
		mod = .1;
	}
	std::normal_distribution<double> dis(0, mod);
	return dis(generator);
}
int Roller::rollMobHealth(double level, double hitdie) {
	int healthmod = getDis(level/10) *level;
	healthmod = healthmod*hitdie; // Get a dispersion
	double health = round((pow(level, 3.7)/ 10 + 19.9)*.1)*hitdie;
	health += healthmod;
	return health;
}

int Roller::rollBossHealth(double level, double hitdie) {
	int healthmod = getDis(level/10) *level;
	healthmod = healthmod*hitdie;
	double health = round((pow(level, (4.5)) * .15 + 40)* .10)*hitdie + healthmod;
	health = health;
	return health;
}

int Roller::rollWeapon(double Grade, double hitdie) {
	int hitmod = getDis(Grade/4)*Grade;
	hitmod = hitmod*hitdie;
	double health = round((pow(Grade, 2)))*hitdie + hitmod;
	return health;
}

int Roller::rollMoney(double mun) {
	return (pow(mun, 3) * .5 + 15) * getDis(mun / 10)*mun;
}

int Roller::rollXP(double lvl) {
	return (pow(lvl, (1.125))) * 75 + getDis(lvl/10)*lvl;
}

int Roller::rollDef(double Grade) {
	int hitmod = getDis(Grade / 4)*Grade;
	double health = round((1.75*pow(Grade, 2.1))) + hitmod;
	return health;
}

int Roller::rollAtt(double Grade) {
	int hitmod = getDis(Grade / 4)*Grade;
	double health = round((pow(Grade, 2.9)+8)) + hitmod;
	return health;
}


int Roller::getMagic(double lvl) {
	return  pow(2, (lvl)) * 5;
}

int Roller::getHealing(double lvl) {
	return  pow(2, (0.8 *lvl)) * 5;
}

int Roller::getEnhance(double lvl) {
	return round(pow(lvl, (3.2)) + 9);
}