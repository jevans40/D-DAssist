#include "MiscUtil.h"

using std::cin;
using std::cout;

namespace Util {


	int getInt() {
		int intvalue;
		while (!(cin >> intvalue)) {
			cin.clear();
			cin.ignore();
		}
		return intvalue;
	}

	std::string getGrade(int g) {
		std::string Grade;
		switch (g) {
		case 2:
			Grade = "Uncommon";
			break;
		case 3:
			Grade = "Great";
			break;
		case 4:
			Grade = "Rare";
			break;
		case 5:
			Grade = "Epic";
			break;
		case 6:
			Grade = "Heroic";
			break;
		case 7:
			Grade = "Devine";
			break;
		case 8:
			Grade = "Mythic";
			break;
		default:
			Grade = "Common";
		}
		return Grade;
	}
}