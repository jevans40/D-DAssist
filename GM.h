#pragma once
#include <string>

void RunGame();

void gameCommands(std::string cmd);

void gameMakeMob();

void gameMakeWeapon();

void gameGetWeapon(int num);

void gameGetMob(int num);

void gameDeleteMobs();

void gameDeleteWeapons();

void gameDamageMob(int index, int damage, int attack);

void gameAddStatusToMob(int status);