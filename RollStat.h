#pragma once
#include <random>
class Roller {
private:


public:
	//Get a random number normally distributed with sigma of mod
	static double getDis(double mod = .1);
	
	//Get a random Mob Health based on level and its base hitDie
	static int rollMobHealth(double level = 0, double hitDie = 2);

	//Get a random weapon damage
	static int rollWeapon(double grade = 0, double hitDie = 2);
	static int rollBossHealth(double level = 0, double hitDie = 2);
	static int rollMoney(double mun = 0);
	static int rollXP(double lvl = 0);
	static int rollDef(double grade = 0);
	static int rollAtt(double grade = 0);
	static int getMagic(double lvl = 0);
	static int getHealing(double lvl = 0);
	static int getEnhance(double lvl = 0);
};