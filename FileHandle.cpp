#include "FileHandle.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

std::vector<std::string> GetFileStringList(std::string filename) {
	std::ifstream file;
	std::vector <std::string> strings;
	file.open(filename);
	if (!file) {
		throw _CRT_ERROR;
	}
	std::string tmpstr;
	std::getline(file,tmpstr);
	strings.push_back(tmpstr);
	while (!file.eof()) {
		std::getline(file, tmpstr);
		strings.push_back(tmpstr);
	}

	return strings;
}