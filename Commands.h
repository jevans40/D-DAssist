#pragma once
#include <string>
#include <iostream>


int getInt();

std::string getGrade(int g = 0);

void Command(std::string cmd);

void printHelp();

void ACInfo();

void ACCalcL();

void ACCalcM();

void ACCalcH();

void hamGap();

void enhanceCalc();

// Extras
void magicCalc();

void meleeCalc();

void healCalc();

void skillCalc();

void enemyCalc();

void bossCalc();

void XPCalc();

void moneyCalc();

void attackCalc();

void defCalc();

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
