#include "Weapon.h"
#include "MiscUtil.h"
#include <iostream>
using std::cout;

Weapon::Weapon() {
	cout << "Please input a Grade (1-8)";
	int grade;
	std::cin >> grade;
	cout << "Please input a HitDie";
	int hit;
	std::cin >> hit;
}