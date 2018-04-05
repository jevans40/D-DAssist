#pragma once
#include <vector>
#include <string>

std::vector<std::string> GetFileStringList(std::string file);

std::vector<double> GetFileWeights(std::string file, char type);

bool setFileWeights(std::vector<double> weights, std::string filename, char type);