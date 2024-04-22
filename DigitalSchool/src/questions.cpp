//#include "../lib/precompile.h"
//
//int index = 0;
//
//void questions() {
//
//	const char* questions[20] = {"Which of the following situations show a biotic factor operating within an ecosystem?", "giwhhg", "gheiowhgwio", "hgwj", "gwih", "hbnwo", "giwhhg", "hgwj", "gwih", "hbnwo", "giwhhg", "gheiowhgwio", "hgwj", "gwih", "hbnwo", "giwhhg", "gheiowhgwio", "hgwj", "gwih", "hbnwo"};
//
//	//Draw navbar
//	Rectangle navbar = { 30, 40, 1860, 120 };
//	DrawRectangleLinesEx(navbar, 1, BLACK);
//	
//	//Draw navbar text
//	DrawText("Crocs", 70, 60, 50, BLACK);
//	DrawText("Digital School Project", 70, 110, 25, BLACK);
//
//	//Draw navbar logo
//	Texture2D Logo = LoadTexture("../school-project-assignment-crocs/DigitalSchool/assets/crocs-logo.png");
//	DrawTextureEx(Logo, Vector2(1710, 50), 0, 0.3, RAYWHITE);
//
//
//
//	Rectangle questionnaire = { 30, 180, 1460, 800 };
//	DrawRectangleLinesEx(questionnaire, 1, BLACK);
//
//
//
//
//	//Draw sidebar
//	Rectangle sidebar = { 1510, 180, 380, 800 };
//	DrawRectangleLinesEx(sidebar, 1, BLACK);
//
//	Rectangle questionNumber = { 1540, 210, 320, 150 };
//	DrawText("Test navigation", 1540, 210, 20, BLACK);
//
//	Rectangle nextQuestion = { 1540, 370, 320, 40 };
//	if (index < 19) {
//		DrawRectangle(1540, 390, 320, 40, LIGHTGRAY);
//		DrawText("Next question", 1630, 400, 20, BLACK);
//	}
//
//	Rectangle previousQuestion = { 1540, 425, 320, 40 };
//	if (index > 0) {
//		DrawRectangle(1540, 445, 320, 40, LIGHTGRAY);
//		DrawText("Previous question", 1610, 455, 20, BLACK);
//	}
//
//	//Change question when clicking next question or previous question buttons
//	if (CheckCollisionPointRec(GetMousePosition(), nextQuestion) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//		if (index < 19) {
//			index += 1;
//		}
//	}
//
//	if (CheckCollisionPointRec(GetMousePosition(), previousQuestion) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//		if (index > 0) {
//			index -= 1;
//		}
//	}
//
//	int questionPosY = 210;
//	DrawText(questions[index], 70, questionPosY, 20, BLACK);
//
//
//
//	//Draw sidebar question navigation buttons
//	Rectangle question[20];
//	question[0].x = 1530;
//	question[0].y = 270;
//	question[0].width = 30;
//	question[0].height = 30;
//	DrawRectangleLinesEx(question[0], 2, BLACK);
//
//	question[1].x = 1565;
//	question[1].y = 270;
//	question[1].width = 30;
//	question[1].height = 30; 
//	DrawRectangleLinesEx(question[1], 2, BLACK);
//
//	question[2].x = 1600;
//	question[2].y = 270;
//	question[2].width = 30;
//	question[2].height = 30;
//	DrawRectangleLinesEx(question[2], 2, BLACK);
//
//	question[3].x = 1635;
//	question[3].y = 270;
//	question[3].width = 30;
//	question[3].height = 30;
//	DrawRectangleLinesEx(question[3], 2, BLACK);
//
//	question[4].x = 1670;
//	question[4].y = 270;
//	question[4].width = 30;
//	question[4].height = 30;
//	DrawRectangleLinesEx(question[4], 2, BLACK);
//
//	question[5].x = 1705;
//	question[5].y = 270;
//	question[5].width = 30;
//	question[5].height = 30;
//	DrawRectangleLinesEx(question[5], 2, BLACK);
//
//	question[6].x = 1740;
//	question[6].y = 270;
//	question[6].width = 30;
//	question[6].height = 30;
//	DrawRectangleLinesEx(question[6], 2, BLACK);
//
//	question[7].x = 1775;
//	question[7].y = 270;
//	question[7].width = 30;
//	question[7].height = 30;
//	DrawRectangleLinesEx(question[7], 2, BLACK);
//
//	question[8].x = 1810;
//	question[8].y = 270;
//	question[8].width = 30;
//	question[8].height = 30;
//	DrawRectangleLinesEx(question[8], 2, BLACK);
//
//	question[9].x = 1845;
//	question[9].y = 270;
//	question[9].width = 30;
//	question[9].height = 30;
//	DrawRectangleLinesEx(question[9], 2, BLACK);
//
//	question[10].x = 1530;
//	question[10].y = 305;
//	question[10].width = 30;
//	question[10].height = 30;
//	DrawRectangleLinesEx(question[10], 2, BLACK);
//
//	question[11].x = 1565;
//	question[11].y = 305;
//	question[11].width = 30;
//	question[11].height = 30;
//	DrawRectangleLinesEx(question[11], 2, BLACK);
//
//	question[12].x = 1600;
//	question[12].y = 305;
//	question[12].width = 30;
//	question[12].height = 30;
//	DrawRectangleLinesEx(question[12], 2, BLACK);
//
//	question[13].x = 1635;
//	question[13].y = 305;
//	question[13].width = 30;
//	question[13].height = 30;
//	DrawRectangleLinesEx(question[13], 2, BLACK);
//
//	question[14].x = 1670;
//	question[14].y = 305;
//	question[14].width = 30;
//	question[14].height = 30;
//	DrawRectangleLinesEx(question[14], 2, BLACK);
//
//	question[15].x = 1705;
//	question[15].y = 305;
//	question[15].width = 30;
//	question[15].height = 30;
//	DrawRectangleLinesEx(question[15], 2, BLACK);
//
//	question[16].x = 1740;
//	question[16].y = 305;
//	question[16].width = 30;
//	question[16].height = 30;
//	DrawRectangleLinesEx(question[16], 2, BLACK);
//
//	question[17].x = 1775;
//	question[17].y = 305;
//	question[17].width = 30;
//	question[17].height = 30;
//	DrawRectangleLinesEx(question[17], 2, BLACK);
//
//	question[18].x = 1810;
//	question[18].y = 305;
//	question[18].width = 30;
//	question[18].height = 30;
//	DrawRectangleLinesEx(question[18], 2, BLACK);
//
//	question[19].x = 1845;
//	question[19].y = 305;
//	question[19].width = 30;
//	question[19].height = 30;
//	DrawRectangleLinesEx(question[19], 2, BLACK);
//
//
//
//
//
//	//Draw answer choices
//	DrawCircle(78, questionPosY + 80, 8, RAYWHITE);
//	DrawRing(Vector2(78, questionPosY + 80), 7, 10, 0, 360, 1, BLACK);
//
//	DrawCircle(78, questionPosY + 150, 8, RAYWHITE);
//	DrawRing(Vector2(78, questionPosY + 150), 7, 10, 0, 360, 1, BLACK);
//
//	DrawCircle(78, questionPosY + 220, 8, RAYWHITE);
//	DrawRing(Vector2(78, questionPosY + 220), 7, 10, 0, 360, 1, BLACK);
//
//	DrawCircle(78, questionPosY + 290, 8, RAYWHITE);
//	DrawRing(Vector2(78, questionPosY + 290), 7, 10, 0, 360, 1, BLACK);
//
//
//}