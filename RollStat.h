#pragma once
#include <random>
class Roller {
private:


public:

	static double getDis();

	static int rollMobHealth(int level = 0, int hitDie = 2);

	static int rollWeapon(int grade = 0, int hitDie = 2);
	static int rollBossHealth(int level = 0, int hitDie = 2);
};