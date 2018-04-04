#include <iostream>
#include <string>
#include "Commands.h"
#include "Weapon.h"


using std::cout;
using std::endl;
using std::cin;

int main() {
	std::string cmd;
	Weapon::Init();
	while (cmd != "end") {
		cout << "D&D Calculator v.5" << endl << "Type cmd for commands or end to end" << endl;
		cin >> cmd;
		if(cmd != "end")
			Command(cmd);
	}
}