#pragma once
#include "../lib/precompile.h"
#include "pageHandle.h"
#include "test.h"
#include "files.h"

class questionDisplay {
public:
	QUESTIONS question;
	std::string* chosenAnswer = nullptr;
};

class testPage {
public:
	void displayTestPage();
	void drawQuestion();
	void buttonHandler(pageBools& pages);
	void questionsHandler();
	void questionChecker();

	int indexOfQuestion = 0;
	int questionPosY = 210;
	int selectedAnswer[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int marks = 0;
	int grade = 0;
	questionDisplay question[20];
	QUESTIONS* questionBank = new QUESTIONS[50];
	Rectangle navbar = { 30, 40, 1860, 120 };
	//Texture2D* Logo = new Texture2D(LoadTexture("../assets/crocs-logo.png"));
	Rectangle questionnaire = { 30, 180, 1460, 800 };
	Rectangle sidebar = { 1510, 180, 380, 800 };
	Rectangle questionNumber = { 1540, 210, 320, 150 };
	Rectangle nextQuestion = { 1540, 370, 320, 40 };
	Rectangle previousQuestion = { 1540, 425, 320, 40 };
	Rectangle submitButton = { 1540, 480, 320, 40 };
	Rectangle answer1 = { 70, 262, 1000, 40 };
	Rectangle answer2 = { 70, 332, 1000, 40 };
	Rectangle answer3 = { 70, 402, 1000, 40 };
	Rectangle answer4 = { 70, 472, 1000, 40 };
};