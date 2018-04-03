#include <iostream>
#include <string>
#include "Commands.h"
#include <random>
#include "RollStat.h"



using std::cout;
using std::endl;
using std::cin;

int main() {
	std::string cmd;
	while (cmd != "end") {
		cout << "D&D Calculator v.1" << endl << "Type cmd for commands or end to end" << endl;
		cin >> cmd;
		if(cmd != "end")
			Command(cmd);
	}
}