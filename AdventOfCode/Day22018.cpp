#include "pch.h"
#include "Day22018.h"


Day22018::Day22018()
{
}


Day22018::~Day22018()
{
}

void Day22018::partOne() {
	std::vector<std::string> file;
	file = FileReader::getFile("../Input/2018-12-02.txt");
	int amountOfPairs = 0;
	int amountOfTripples = 0;
	for (const auto &row : file) {
		std::string sortedRow = row;
		std::sort(sortedRow.begin(), sortedRow.end());
		int firstTimeIndex = 0;
		char lastChar = sortedRow[0];
		bool pairs = false;
		bool tripplets = false;
		for (int i = 0; i <= sortedRow.length(); i++) {
			if (lastChar != sortedRow[i % sortedRow.length()]) {
				if (i - firstTimeIndex == 2) {
					pairs = true;
				}
				else if (i - firstTimeIndex == 3) {
					tripplets = true;
				}
				lastChar = sortedRow[i];
				firstTimeIndex = i;
			} 
		}
		if (pairs) {
			amountOfPairs++;
		}
		if (tripplets) {
			amountOfTripples++;
		}
	}
	std::cout << amountOfPairs << " " << amountOfTripples << " " << amountOfPairs * amountOfTripples;
}

void Day22018::partTwo() {
	std::vector<std::string> file;
	file = FileReader::getFile("../Input/2018-12-02.txt");
	std::unordered_set<std::string> boxIdsMissingOneChar;
	std::string matchingChars = "";
	bool found = false;
	for (auto row = file.begin(); row != file.end() && !found; row++) {
		std::unordered_set<std::string> variationsForOneBox;
		// use i for char to remove
		for (int i = 0; i < row->length(); i++) {
			std::string variation = *row;
			variation.erase(variation.begin() + i);
			variationsForOneBox.insert(variation);
		}
		for (auto itr = variationsForOneBox.begin(); itr != variationsForOneBox.end() && !found; itr++) {
			found = !boxIdsMissingOneChar.insert(*itr).second;
			matchingChars = *itr;
		}
	}
	std::cout << "matching chars : " << matchingChars;
}
