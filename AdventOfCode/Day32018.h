#pragma once
#include <unordered_set>
#include <regex>

class Claim
{
public:
	Claim() {};
	~Claim() {};
	Claim(int id, int left, int width, int up, int height);
	bool compare(Claim c);
	bool overlap;
	int id;
private:
	int left, right, up, down;
	
};

class Day32018
{
public:
	Day32018();
	~Day32018();
	void static partOne();
	void static partTwo();
};

