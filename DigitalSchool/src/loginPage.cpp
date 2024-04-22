#include "../lib/precompile.h"

char username[17] = "\0";
int userCharCount = 0;

char password[17] = "\0";
int passCharCount = 0;

int StartTest = 0;

void loginPage() {
	Font customFont = GetFontDefault();

	float borderThickness = 2;
	Color borderColor = GRAY;

	DrawTextEx(customFont, "Login Before Starting", Vector2{700, 280}, 50, 3, BLACK);

	//Draw username text box
	Rectangle usernameText = { 820, 415, 280, 45 };
	DrawRectangle(820, 415, 280, 45, RAYWHITE);
	DrawRectangleLinesEx(usernameText, borderThickness, borderColor);
	if (username[0] != '\0') 
		DrawText(username, 835, 430, 20, BLACK);
		
	else DrawText("Username", 835, 430, 20, LIGHTGRAY);


	//Draw password text box
	Rectangle passwordText = { 820, 515, 280, 45 };
	DrawRectangle(820, 515, 280, 45, RAYWHITE);
	DrawRectangleLinesEx(passwordText, borderThickness, borderColor);
	if (password[0] != '\0')
	{
		for (int i = 0; i < passCharCount; i++)
			DrawText("*", 835 + i * 11, 530, 20, BLACK);
	}

	else DrawText("Password", 835, 530, 20, LIGHTGRAY);

	//Draw login button
	Rectangle loginButton = { 820, 660, 280, 90 };
	DrawRectangle(820, 660, 280, 90, BLUE);
	DrawText("Login", 905, 685, 40, LIGHTGRAY);


	Rectangle Border = { 670, 215, 580, 600 };
	DrawRectangleLinesEx(Border, 1, borderColor);


	//Check mouse position and change cursor accordingly
	if (CheckCollisionPointRec(GetMousePosition(), loginButton))
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
	else if (CheckCollisionPointRec(GetMousePosition(), usernameText))
	{
		if (userCharCount < 14 || ((GetTime() / 0.5f) < 1))
		{
			DrawLine(837 + MeasureText(username, 20), 430, 837 + MeasureText(username, 20), 430 + 20, BLACK);
		}

		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();
		if ((key >= 32) && (key <= 125) && (userCharCount < 14))
		{
			username[userCharCount] = (char)key;
			username[userCharCount + 1] = '\0';
			userCharCount++;
		}
		if (IsKeyPressed(KEY_BACKSPACE))
		{
			userCharCount--;
			if (userCharCount < 0) userCharCount = 0;
			username[userCharCount] = '\0';
		}

	}
	else if (CheckCollisionPointRec(GetMousePosition(), passwordText))
	{
		if (passCharCount < 14 || ((GetTime() / 0.5f) < 1))
		{
			DrawLine(837 + MeasureText(password, 20), 530, 837 + MeasureText(password, 20), 530 + 20, BLACK);
		}

		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();
		if ((key >= 32) && (key <= 125) && (passCharCount < 14))
		{
			password[passCharCount] = (char)key;
			password[passCharCount + 1] = '\0';
			passCharCount++;
		}
		if (IsKeyPressed(KEY_BACKSPACE))
		{
			passCharCount--;
			if (passCharCount < 0) passCharCount = 0;
			password[passCharCount] = '\0';
		}

	}
	else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

	if (CheckCollisionPointRec(GetMousePosition(), loginButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		StartTest = 1;
	}

	if (StartTest == 1) {
		questions();
	}
}