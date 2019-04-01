#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class FileReader
{
public:
	FileReader();
	~FileReader();
	static std::vector<std::string> getFile(std::string filePath);
};

