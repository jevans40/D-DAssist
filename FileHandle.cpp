#include "FileHandle.h"
#include "MiscUtil.h"
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

std::vector<double> GetFileWeights(std::string file, char type) {
	std::vector<double> vect;
	std::ifstream input;
	input.open(file);

	char tmpchar;
	int tmpint;

	if (!input.is_open()) {
		throw _CRT_ERROR;
	}
	
	input >> tmpchar;

	if (tmpchar != type) {
		return vect;
	}
	
	while (!input.eof()) {
		input >> tmpint;
		if (input.peek() == ',') {
			input.clear();
			input.ignore();
		}
	}
	
	return vect;
}

bool setFileWeights(std::vector<double> weights, std::string filename, char type) {
	std::ofstream output;
	output.open("Weights/"+filename+".csl");
	if (!output.is_open()) {
		return false;
	}
	output << type << '\n';
	for (int i = 0; i < weights.size(); i++) {
		output << weights[i] << ',';
	}
	return true;
}