#include "../lib/precompile.h"
#include "../lib/testPage.h"

void testPage::displayTestPage() {
	//Draw navbar
	DrawRectangleLinesEx(navbar, 1, BLACK);
	
	//Draw navbar text
	DrawText("Crocs", 70, 60, 50, BLACK);
	DrawText("Digital School Project", 70, 110, 25, BLACK);

	//Draw navbar logo
	//DrawTextureEx(*Logo, Vector2(1710, 50), 0, 0.3, RAYWHITE);
	DrawRectangleLinesEx(questionnaire, 1, BLACK);
	
	if (indexOfQuestion < 19)
	{
		DrawRectangle(1540, 390, 320, 40, LIGHTGRAY);
		DrawText("Next question", 1630, 400, 20, BLACK);
	}

	if (indexOfQuestion > 0)
	{
		DrawRectangle(1540, 445, 320, 40, LIGHTGRAY);
		DrawText("Previous question", 1610, 455, 20, BLACK);
	}

	DrawRectangle(1540, 500, 320, 40, LIGHTGRAY);
	DrawText("Submit", 1670, 510, 20, BLACK);
}

void testPage::drawQuestion()
{

	DrawText(question[indexOfQuestion].question.question.c_str(), 70, questionPosY, 20, BLACK);

	//Draw answer choices
	DrawRing(Vector2(78, questionPosY + 90), 7, 10, 0, 360, 1, BLACK);
	if (selectedAnswer[indexOfQuestion] == 1)
	{
		DrawCircle(78, questionPosY + 90, 8, BLACK);
	}
	else
	{
		DrawCircle(78, questionPosY + 90, 8, RAYWHITE);
	}
	DrawText(question[indexOfQuestion].question.answerA.c_str(), 78 + 20, questionPosY + 81, 20, BLACK);

	DrawRing(Vector2(78, questionPosY + 160), 7, 10, 0, 360, 1, BLACK);
	if (selectedAnswer[indexOfQuestion] == 2)
	{
		DrawCircle(78, questionPosY + 160, 8, BLACK);
	}
	else
	{
		DrawCircle(78, questionPosY + 160, 8, RAYWHITE);
	}
	DrawText(question[indexOfQuestion].question.answerB.c_str(), 78 + 20, questionPosY + 151, 20, BLACK);
	DrawRing(Vector2(78, questionPosY + 230), 7, 10, 0, 360, 1, BLACK);
	if (selectedAnswer[indexOfQuestion] == 3)
	{
		DrawCircle(78, questionPosY + 230, 8, BLACK);
	}
	else
	{
		DrawCircle(78, questionPosY + 230, 8, RAYWHITE);
	}
	DrawText(question[indexOfQuestion].question.answerC.c_str(), 78 + 20, questionPosY + 221, 20, BLACK);
	DrawRing(Vector2(78, questionPosY + 300), 7, 10, 0, 360, 1, BLACK);
	if (selectedAnswer[indexOfQuestion] == 4)
	{
		DrawCircle(78, questionPosY + 300, 8, BLACK);
	}
	else
	{
		DrawCircle(78, questionPosY + 300, 8, RAYWHITE);
	}
	DrawText(question[indexOfQuestion].question.answerD.c_str(), 78 + 20, questionPosY + 291, 20, BLACK);
}

void testPage::buttonHandler(pageBools& pages)
{
	if (CheckCollisionPointRec(GetMousePosition(), nextQuestion) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		if (indexOfQuestion < 19) {
			indexOfQuestion++;
		}
	}

	if (CheckCollisionPointRec(GetMousePosition(), previousQuestion) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		if (indexOfQuestion > 0) {
			indexOfQuestion--;
		}
	}

	if (CheckCollisionPointRec(GetMousePosition(), submitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		pages.mainMenuShouldDisplay = false;
		pages.registerPageShouldDisplay = false;
		pages.loginPageShouldDisplay = false;
		pages.preTestPageShouldDisplay = false;
		pages.testPageShouldDisplay = false;
		pages.submitPageShouldDsiplay = true;
		questionChecker();
	}

	if (CheckCollisionPointRec(GetMousePosition(), answer1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		selectedAnswer[indexOfQuestion] = 1;
		question[indexOfQuestion].chosenAnswer = &question[indexOfQuestion].question.answerA;
	}
	if (CheckCollisionPointRec(GetMousePosition(), answer2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		selectedAnswer[indexOfQuestion] = 2;
		question[indexOfQuestion].chosenAnswer = &question[indexOfQuestion].question.answerB;
	}
	if (CheckCollisionPointRec(GetMousePosition(), answer3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		selectedAnswer[indexOfQuestion] = 3;
		question[indexOfQuestion].chosenAnswer = &question[indexOfQuestion].question.answerC;
	}
	if (CheckCollisionPointRec(GetMousePosition(), answer4) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		selectedAnswer[indexOfQuestion] = 4;
		question[indexOfQuestion].chosenAnswer = &question[indexOfQuestion].question.answerD;
	}
}

void testPage::questionsHandler()
{
	std::fstream questionsBank;
	questionsBank.open("../files/questionBank.txt", std::ios::in | std::ios::out);
	for (int i = 0; i < 50; i++)
	{
		questionBank[i].question = getLine(questionsBank);
		questionBank[i].answerA = getLine(questionsBank);
		questionBank[i].answerB = getLine(questionsBank);
		questionBank[i].answerC = getLine(questionsBank);
		questionBank[i].answerD = getLine(questionsBank);
		questionBank[i].correct = getLine(questionsBank);
	}
	questionsBank.close();
	QUESTIONS* chosenQuestions = getRandomQuestions(questionBank);
	for (int i = 0; i < 20; i++)
	{
		question[i].question = chosenQuestions[i];
	}

}

void testPage::questionChecker()
{
	for (int i = 0; i < 20; i++)
	{
		if (question[i].chosenAnswer == nullptr)
			marks = marks;
		else
		if (question[i].question.correct.find(*question[i].chosenAnswer) != std::string::npos)
			marks++;
	}
	grade = marks * 5;
}
