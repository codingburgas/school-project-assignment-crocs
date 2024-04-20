#pragma once

std::fstream openFile(std::string& name);
void closeFile(std::fstream& file);
std::string* getLine(std::fstream& file, int lineNum);
int getFileSize(std::fstream& file);