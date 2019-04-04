#include "pch.h"
#include "Day32018.h"


Day32018::Day32018()
{
}


Day32018::~Day32018()
{
}

void Day32018::partOne() {
	std::vector<std::string> file;
	file = FileReader::getFile("../Input/2018-12-03.txt");
	std::unordered_set<std::string> fabric;
	std::unordered_set<std::string> overlap;
	std::regex split("#(\\d*).@.(\\d*),(\\d*)..(\\d*).(\\d*)");
	for (const auto &row : file) {
		std::smatch fabricPatch;
		std::regex_search(row, fabricPatch, split);
		int id = std::stoi(fabricPatch[1]);
		int leftOffset = std::stoi(fabricPatch[2]);
		int topOffset = std::stoi(fabricPatch[3]);
		int width = std::stoi(fabricPatch[4]);
		int height = std::stoi(fabricPatch[5]);
		
		std::string coordinate;
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				coordinate = std::to_string(leftOffset + x) + "," + std::to_string(topOffset + y);
				if (!fabric.insert(coordinate).second) {
					overlap.insert(coordinate);
				}
			}
		}
	}
	std::cout << "overlapping inches = " << overlap.size();
}

Claim::Claim(int id, int left, int width, int up, int height) {
	this->id = id;
	this->left = left;
	this->right = left + width;
	this->up = up;
	this->down = up + height;
	this->overlap = false;
}

bool Claim::compare(Claim c) {
	if (this->left < c.right && this->right > c.left &&
		this->up < c.down && this->down > c.up) {
		return true;
	}
	return false;
}

void Day32018::partTwo() {
	std::vector<std::string> file;
	file = FileReader::getFile("../Input/2018-12-03.txt");
	std::regex split("#(\\d*).@.(\\d*),(\\d*)..(\\d*).(\\d*)");
	std::list<Claim> claims;
	for (const auto &row : file) {
		std::smatch fabricPatch;
		std::regex_search(row, fabricPatch, split);
		int id = std::stoi(fabricPatch[1]);
		int leftOffset = std::stoi(fabricPatch[2]);
		int topOffset = std::stoi(fabricPatch[3]);
		int width = std::stoi(fabricPatch[4]);
		int height = std::stoi(fabricPatch[5]);

		Claim c = Claim::Claim(id, leftOffset, width, topOffset, height);
		claims.push_back(c);
	}
	std::list<Claim>::iterator i;
	std::list<Claim>::iterator j;
	Claim c;
	for (i = claims.begin(); i != claims.end(); i++) {
		for (std::advance(j = i, 1); j != claims.end(); j++) {
			if (i->compare(*j)) {
				i->overlap = true;
				j->overlap = true;
			}
		}
		if (i->overlap == false) {
			c = *i;
			break;
		}
	}
	std::cout << "the no overlapping claim is : " + std::to_string(c.id);
}