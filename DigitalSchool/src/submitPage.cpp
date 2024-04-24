#include "../lib/precompile.h"
#include "../lib/submitPage.h"

void submitPage::displaySubmitPage() {
	DrawRectangle(0, 0, 1920, 1080, LIGHTGRAY);

	//Draw navbar
	DrawRectangle(30, 40, 1860, 120, RAYWHITE);
	DrawRectangleLinesEx(navbar, 1, BLACK);

	//Draw navbar text
	DrawText("Crocs", 70, 60, 50, BLACK);
	DrawText("Digital School Project", 70, 110, 25, BLACK);

	//Draw navbar logo
	DrawTextureEx(Logo, Vector2(1710, 50), 0, 0.3, RAYWHITE);
 
	//Draw outline boxes
	DrawRectangle(30, 200, 1860, 700, RAYWHITE);
	DrawRectangleLinesEx(middleOutline1, borderThickness, BLACK);
	DrawRectangle(60, 530, 1800, 50, RAYWHITE);
	DrawRectangleLinesEx(middleOutline2, borderThickness, BLACK);
	DrawRectangle(60, 578, 1800, 80, LIGHTGRAY);
	DrawRectangleLinesEx(middleOutline3, borderThickness, BLACK);
	
	//Draw home button
	DrawRectangle(800, 730, 320, 60, BLUE);
	DrawText("Return to home", 880, 752, 20, BLACK);

	//Draw Text
	DrawText("Summary of your previous attempt", 60, 500, 25, BLACK);
	DrawText("Attempt", 140, 547, 20, BLACK);
	DrawText("1", 175, 610, 20, BLACK);
	DrawText("State", 350, 547, 20, BLACK);
	DrawText("Finished", 340, 610, 20, BLACK);
	DrawText("Marks/20", 1000, 547, 20, BLACK);
	DrawText("grade", 1017, 610, 20, BLACK);
	DrawText("Grade", 1300, 547, 20, BLACK);
	DrawText("10%", 1310, 610, 20, BLACK);
	DrawText("Review", 1660, 547, 20, BLACK);
	DrawText("Review unavailable", 1600, 610, 20, BLACK);
	DrawText("Attempts allowed: Unlimited", 760, 280, 30, BLACK);
	DrawText("Grading method: Average grade", 800, 330, 20, BLACK);
}

void submitPage::buttonHandler() {

}