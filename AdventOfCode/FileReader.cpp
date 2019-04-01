#include "pch.h"
#include "FileReader.h"


FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}

std::vector<std::string> FileReader::getFile(std::string filePath)
{
	std::vector<std::string> content;
	std::ifstream file;
	file.open(filePath);
	if (!file) {
		std::cerr << "unable to open file";
	}
	else {
		std::string line = "";
		if (file.is_open()) {
			while (std::getline(file, line)) {
				content.push_back(line);
			}
			file.close();
		}
	}
	return content;
}
