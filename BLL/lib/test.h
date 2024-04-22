#pragma once

struct QUESTIONS {
	std::string question;
	std::string answerA;
	std::string answerB;
	std::string answerC;
	std::string answerD;
	std::string correct;
};

QUESTIONS* getRandomQuestions(QUESTIONS* questionBank);