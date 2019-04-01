#include "pch.h"
#include "Day12018.h"



Day12018::Day12018()
{
}


Day12018::~Day12018()
{
}

void Day12018::PartOne() {
	std::vector<std::string> file;
	file = FileReader::getFile("../Input/2018-12-01.txt");
	int result = 0;
	for (const auto &row : file) {
		result += std::stoi(row);
	}
	std::cout << result;
}

void Day12018::PartTwo() {
	std::vector<std::string> file;
	file = FileReader::getFile("../Input/2018-12-01.txt");
	std::unordered_set<int> previousFrequencies;
	int lastFrequency = 0;
	previousFrequencies.insert(lastFrequency);
	int i = 0;
	bool found = false;
	while (!found) {
		lastFrequency += std::stoi(file[i]);
		found = ! previousFrequencies.insert(lastFrequency).second;
		i = (i + 1) % file.size();
	}
	std::cout << lastFrequency;
}