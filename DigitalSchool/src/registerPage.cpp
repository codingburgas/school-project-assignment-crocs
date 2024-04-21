#include "../lib/precompile.h"

char username1[15] = "\0";
int userCharCount1 = 0;

char password1[15] = "\0";
int passCharCount1 = 0;


void registerPage() {
	Font customFont = GetFontDefault();

	float borderThickness = 2;
	Color borderColor = GRAY;

	DrawTextEx(customFont, "Program The Future!", Vector2{ 710, 280 }, 50, 3, BLACK);

	//Draw username text box
	Rectangle usernameText = { 820, 415, 280, 45 };
	DrawRectangle(820, 415, 280, 45, RAYWHITE);
	DrawRectangleLinesEx(usernameText, borderThickness, borderColor);
	if (username1[0] != '\0')
		DrawText(username1, 835, 430, 20, BLACK);

	else DrawText("Username", 835, 430, 20, LIGHTGRAY);


	//Draw password text box
	Rectangle passwordText = { 820, 515, 280, 45 };
	DrawRectangle(820, 515, 280, 45, RAYWHITE);
	DrawRectangleLinesEx(passwordText, borderThickness, borderColor);
	if (password1[0] != '\0')
		DrawText(password1, 835, 530, 20, BLACK);

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
		if (userCharCount1 < 14 || ((GetTime() / 0.5f) < 1))
		{
			DrawLine(837 + MeasureText(username1, 20), 430, 837 + MeasureText(username1, 20), 430 + 20, BLACK);
		}

		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();
		if ((key >= 32) && (key <= 125) && (userCharCount1 < 14))
		{
			username1[userCharCount1] = (char)key;
			username1[userCharCount1 + 1] = '\0';
			userCharCount1++;
		}
		if (IsKeyPressed(KEY_BACKSPACE))
		{
			userCharCount1--;
			if (userCharCount1 < 0) userCharCount1 = 0;
			username1[userCharCount1] = '\0';
		}

	}
	else if (CheckCollisionPointRec(GetMousePosition(), passwordText))
	{
		if (passCharCount1 < 14 || ((GetTime() / 0.5f) < 1))
		{
			DrawLine(837 + MeasureText(password1, 20), 530, 837 + MeasureText(password1, 20), 530 + 20, BLACK);
		}

		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();
		if ((key >= 32) && (key <= 125) && (passCharCount1 < 14))
		{
			password1[passCharCount1] = (char)key;
			password1[passCharCount1 + 1] = '\0';
			passCharCount1++;
		}
		if (IsKeyPressed(KEY_BACKSPACE))
		{
			passCharCount1--;
			if (passCharCount1 < 0) passCharCount1 = 0;
			password1[passCharCount1] = '\0';
		}

	}
	else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}