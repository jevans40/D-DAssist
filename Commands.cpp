#include "Commands.h"

using std::cout;
using std::cin;
using std::endl;

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

void Command(std::string cmd) {
	if (cmd == "cmd") {
		printHelp();
	}
	else if (cmd == "ACI") {
		ACInfo();
	}
	else if (cmd == "ACL" ) {
		ACCalcL();
	}
	else if (cmd == "ACM") {
		ACCalcM();
	}
	else if (cmd == "ACH") {
		ACCalcH();
	}
	else if (cmd == "ham") {
		hamGap();
	}
	else if (cmd == "Enh") {
		enhanceCalc();
	}


	//exraCommands
	else if (cmd == "Magic") {
		magicCalc();
	}
	else if (cmd == "Melee") {
		meleeCalc();
	}
	else if (cmd == "Heal") {
		healCalc();
	}
	else if (cmd == "Skill") {
		skillCalc();
	}
	else if (cmd == "Enemy") {
		enemyCalc();
	}
	else if (cmd == "Boss") {
		bossCalc();
	}
	else if (cmd == "XP") {
		XPCalc();
	}
	else if (cmd == "Money") {
		moneyCalc();
	}
}

void printHelp() {
	cout << "Commands" << endl;
	cout << "cmd \t \t Print Commands" << endl;
	cout << "ACI \t \t Info on how armor works" << endl;
	cout << "ACL \t \t Get %AC For Light Armor" << endl;
	cout << "ACM \t \t Get %AC For Medium Armor" << endl;
	cout << "ACH \t \t Get %AC For Heavy Armor" << endl;
	cout << "ham \t \t Calculate Hammer the Gap Bonus" << endl;
	cout << "Enh \t \t Tells you what the next enhancement level will cost" << endl;
	cout << "end \t \t End the Program" << endl << endl;
}


void ACCalcL() {
	double num(0);
	while(num >= 0){
		cout << "L AC Calc, enter an AC or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			int num2 =  (100 - ((((-100 * (num*num) + 400 * num) / (2 * num*num)) + 60) * 2.5)) * (-1);
			cout << "You would take " << num2 << " Percent of incoming damage" << endl << endl;
		}
	}
}

void ACInfo() {
	cout << "New AC System \n \n";
	cout << "This tool will tell you how much damage resistance you have \n";
	cout << "The command you use will be based on the lighest peice of armor you are using \n \n";
}

void ACCalcM() {
	double num(0);
	while (num >= 0) {
		cout << "M AC Calc, enter an AC or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			int num2 = (100 - ((((-100 * (num*num) + 400 * num) / (2 * num*num)) + 60) * 5)) * (-1);
			cout << "You would take " << num2 << " Percent of incoming damage" << endl << endl;
		}
	}
}

void ACCalcH() {
	double num(0);
	while (num >= 0) {
		cout << "H AC Calc, enter an AC or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			int num2 = (100 - ((((-100 * (num*num) + 400 * num) / (2 * num*num)) + 60) * 10)) * (-1);
			cout << "You would take " << num2 << " Percent of incoming damage" << endl << endl;
		}
	}
}

void hamGap() {
	double num(0);
	while (num >= 0) {
		cout << "Hammer The Gap Calc Calc, enter num of shots or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			num = num*(num+1)/2;
			cout << "You deal " << num << " damage" << endl << endl;
		}
	}
}

void magicCalc() {
	double num(0);
	while (num >= 0) {
		cout << "MagicScaling for ship, enter level of magic or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			int num2 = pow(2,num)*5;
			cout << "A level  " << num << " Spell would do " << num2 << " damage" << endl << endl;
		}
	}
}

void meleeCalc() {
	double num(0);
	while (num >= 0) {
		cout << "MeleeScaling for ship, enter grade or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			int num2 = pow(num, 2) * 12;
			cout << "A " << getGrade(num) << " grade weapon would do " << num2 << " damage" << endl << endl;
		}
	}
}

void healCalc() {
	double num(0);
	while (num >= 0) {
		cout << "HealScaling for ship, enter level of spell or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			int num2 = pow(2,(0.8 * num)) * 5;
			cout << "A grade  " << num << " weapon would do " << num2 << " damage" << endl << endl;
		}
	}
}

void skillCalc() {
	double num(0);
	while (num >= 0) {
		cout << "Skill Calc, enter skill or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			int num2 = (100 - ((((-50 * (num*num) + 100 * num) / (2 * num*num)) + 35) * 10)) * (-1);
			cout << "Your skill on a 1-100 scale is " << num2 << endl << endl;
		}
	}
}

void enemyCalc() {
	double num(0);
	while (num >= 0) {
		cout << "EnemyScaling for ship, enter level or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			int num2 = pow(num, (3.7))/10 + 19.9;
			cout << "A level " << num  << "enemy should have " << num2 << " Health" << endl << endl;
		}
	}
}

void bossCalc() {
	double num(0);
	while (num >= 0) {
		cout << "BossScaling for ship, enter level or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			int num2 = pow(num, (4.5)) * .15 + 40;
			cout << "A level " << num << "boss should have " << num2 << " Health" << endl << endl;
		}
	}
}

void XPCalc() {
	double num(0);
	while (num >= 0) {
		cout << "XPScaling for ship, enter level or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			int num2 = pow(num, (1.125)) * 75;
			cout << "A level " << num << "enemy should drop " << num2 << " EXP" << endl << endl;
		}
	}
}

void moneyCalc() {
	double num(0);
	while (num >= 0) {
		cout << "MoneyScaling for ship, enter level or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			int num2 = pow(num, 3) * .5 + 15;
			cout << "A level " << num << "Quest should drop " << num2 << " Gold" << endl << endl;
		}
	}
}

void enhanceCalc() {
	double num(0);
	while (num >= 0) {
		cout << "EnhanceScaling for ship, enter enhancement level or -9999 to end" << endl;
		cout << "Number: ";
		num = getInt();
		if (num >= 0) {
			int num2 = pow(num, (3.2)) + 9;
			cout << "A level " << num << "upgrade should cost " << num2 << " Gold" << endl << endl;
		}
	}
}
//Armor (((-(100X^2 + 400x)/(2x^2))+60)*10)            Scale 20-INF
//Howgoodyourrollbe (((-(50X^2 + 100x)/(2x^2))+35)*10) Scale 0-INF
//Magic ((2^x)*5)       Scale 1-10
//Melee (12X^2)         Scale 1-8
//Healing ((2^.8x) * 5) Scale 1-10
//Enemy (.1(x^3.9)+29.9)Scale 1-20
//Boss (1(x^3.9) + 40)  Scale 1-20
//Exp ((75(x^1.115)*.5))Scale 1-20
//Money (.5(X^3)+15)    Scale 1-20
//Weapons ((x^3.2)+9)   Scale 1-40
//Profession
//Enemy Damage
//Enemy Scores
//Ability Scores Kinda like Armor ****
