#include "../lib/precompile.h"
#include "../lib/testPage.h"

void testPage::displayTestPage() {
	//Draw navbar
	DrawRectangleLinesEx(navbar, 1, BLACK);
	
	//Draw navbar text
	DrawText("Crocs", 70, 60, 50, BLACK);
	DrawText("Digital School Project", 70, 110, 25, BLACK);

	//Draw navbar logo
	DrawTextureEx(Logo, Vector2(1710, 50), 0, 0.3, RAYWHITE);
	DrawRectangleLinesEx(questionnaire, 1, BLACK);

	//Draw sidebar
	DrawRectangleLinesEx(sidebar, 1, BLACK);
	DrawText("Test navigation", 1540, 210, 20, BLACK);
	
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
	DrawText("temp", 70, questionPosY, 20, BLACK);

	//Draw answer choices
	DrawRing(Vector2(78, questionPosY + 80), 7, 10, 0, 360, 1, BLACK);
	if (selectedAnswer == 1)
	{
		DrawCircle(78, questionPosY + 80, 8, BLACK);
	}
	else
	{
		DrawCircle(78, questionPosY + 80, 8, RAYWHITE);
	}
	
	DrawRing(Vector2(78, questionPosY + 150), 7, 10, 0, 360, 1, BLACK);
	if (selectedAnswer == 2)
	{
		DrawCircle(78, questionPosY + 150, 8, BLACK);
	}
	else
	{
		DrawCircle(78, questionPosY + 150, 8, RAYWHITE);
	}

	DrawRing(Vector2(78, questionPosY + 220), 7, 10, 0, 360, 1, BLACK);
	if (selectedAnswer == 3)
	{
		DrawCircle(78, questionPosY + 220, 8, BLACK);
	}
	else
	{
		DrawCircle(78, questionPosY + 220, 8, RAYWHITE);
	}

	DrawRing(Vector2(78, questionPosY + 290), 7, 10, 0, 360, 1, BLACK);
	if (selectedAnswer == 4)
	{
		DrawCircle(78, questionPosY + 290, 8, BLACK);
	}
	else
	{
		DrawCircle(78, questionPosY + 290, 8, RAYWHITE);
	}
	
}

void testPage::buttonHandler()
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

	//if (CheckCollisionPointRec(GetMousePosition(), submitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
	//	if (indexOfQuestion < 19) {
	//		indexOfQuestion--;
	//	}
	//}

	if (CheckCollisionPointRec(GetMousePosition(), answer1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		selectedAnswer = 1;
	}
	if (CheckCollisionPointRec(GetMousePosition(), answer2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		selectedAnswer = 2;
	}
	if (CheckCollisionPointRec(GetMousePosition(), answer3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		selectedAnswer = 3;
	}
	if (CheckCollisionPointRec(GetMousePosition(), answer4) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		selectedAnswer = 4;
	}
}