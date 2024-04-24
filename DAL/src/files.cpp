#include "../lib/precompileDAL.h"

std::string* getLine(std::fstream& file, int lineNum)
{
	std::string* line = new std::string{};
	for (int i = 1; i < getFileSize(file); i++)
	{
		std::getline(file, *line);
		if (lineNum == i)
			break;
	}
	return line;
}

int getFileSize(std::fstream& file)
{
	int fileSize = 0;
	while (!file.eof())
	{
		fileSize++;
	}
	return fileSize;
}

void writeInFile(std::fstream& file, std::string& line)
{
	file << line << std::endl;
}

bool checkIfInFile(std::fstream& file, std::string& line)
{
	std::string fileLine;
	while (!file.eof())
	{
		std::getline(file, fileLine);
		if (fileLine == line)
		{
			return true;
		}
	}
	return false;
}

bool checkIfInFileLine(std::fstream& file, std::string& username)
{
	std::string fileLine;
	while (!file.eof())
	{
		std::getline(file, fileLine);
		if (fileLine.find(username) != std::string::npos)
		{
			return true;
		}
	}
	return false;
}