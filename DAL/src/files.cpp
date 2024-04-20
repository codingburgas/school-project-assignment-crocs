#include "../lib/precompile.h"

std::fstream openFile(std::string& name)
{
	std::fstream file;
	file.open("../../files/" + name, std::ios::in | std::ios::out);
	if (!file)
	{
		std::cout << name + ".txt could not open";
	}
	return file;
}

void closeFile(std::fstream& file)
{
	file.close();
}

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