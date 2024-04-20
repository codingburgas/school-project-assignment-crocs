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