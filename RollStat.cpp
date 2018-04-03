#include "RollStat.h"
#include <chrono>



double Roller::getDis() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::normal_distribution<double> dis(0, .3);
	return dis(generator);
}
int Roller::rollMobHealth(int level, int hitdie) {
	int healthmod = getDis() *level;
		healthmod = healthmod*hitdie;
	double health = round(((double(hitdie) / 10)* (pow(level, (3.7)) / 10 + 19.9) ) / hitdie)*hitdie + healthmod;
	return health;
}

int Roller::rollBossHealth(int level, int hitdie) {
	int healthmod = getDis() *level;
	healthmod = healthmod*hitdie;
	double health = round(((double(hitdie) / 10)* pow(level, (4.5)) * .15 + 40) / hitdie)*hitdie + healthmod;
	return health;
}

int Roller::rollWeapon(int Grade, int hitdie) {
	int healthmod = getDis();
	healthmod = healthmod*hitdie;
	double health = round(((pow(Grade, 2) * hitdie) / hitdie)*hitdie + healthmod;
	return health;
}