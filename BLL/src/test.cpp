#include "../lib/precompile.h"
#include "../lib/test.h"

QUESTIONS* getRandomQuestions(QUESTIONS* questionBank)
{
	int maxNum = 49;
	std::random_device rd;
	
	QUESTIONS* questions = new QUESTIONS[20];
	QUESTIONS* questionsTemp = questionBank;

	for (int i = 0; i < 20; i++)
	{
		std::uniform_int_distribution<int> rand(0, maxNum);
		int choice = rand(rd);
		questions[i] = questionsTemp[choice];
		for (int j = choice; j < maxNum; j++)
		{
			questionsTemp[j] = questionsTemp[j + 1];
		}
		maxNum--;
	}
	return questions;
}