#include "../lib/precompile.h"
#include "../lib/pageHandle.h"
#include "../lib/registerPage.h"

void reg::displayRegisterPage()
{
	DrawTextEx(customFont, "Program The Future!", Vector2{ 710, 280 }, 50, 3, BLACK);

	//Draw username text box
	DrawRectangle(820, 415, 280, 45, RAYWHITE);
	DrawRectangleLinesEx(usernameText, borderThickness, borderColor);
	if (username1[0] != '\0')
	{
		DrawText(username1, 835, 430, 20, BLACK);
	}
	else DrawText("Username", 835, 430, 20, LIGHTGRAY);

	//Draw back button
	DrawRectangle(1700, 50, 70, 70, BLUE);
	DrawText("<-", 1705, 53, 70, LIGHTGRAY);

	//Draw password text box
	DrawRectangle(820, 515, 280, 45, RAYWHITE);
	DrawRectangleLinesEx(passwordText, borderThickness, borderColor);
	if (password1[0] != '\0')
	{
		for (int i = 0; i < passCharCount1; i++)
			DrawText("*", 835 + i * 11, 530, 20, BLACK);
	}
	else DrawText("Password", 835, 530, 20, LIGHTGRAY);

	//Draw login button
	DrawRectangle(820, 660, 280, 90, BLUE);
	DrawText("Login", 905, 685, 40, LIGHTGRAY);

	DrawRectangleLinesEx(Border, 1, borderColor);
}

void reg::buttonHandler(pageBools& pages)
{
	//register button
	if (CheckCollisionPointRec(GetMousePosition(), registerButton))
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pages.mainMenuShouldDisplay = false;
			pages.registerPageShouldDisplay = false;
			pages.loginPageShouldDisplay = false;
			pages.preTestPageShouldDisplay = false;
			pages.testPageShouldDisplay = true;
		}
		return;
	}
	//back button
	if (CheckCollisionPointRec(GetMousePosition(), backButton))
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pages.mainMenuShouldDisplay = true;
			pages.registerPageShouldDisplay = false;
			pages.loginPageShouldDisplay = false;
			pages.preTestPageShouldDisplay = false;
			pages.testPageShouldDisplay = false;
		}
		return;
	}
	SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

void reg::textBoxHandler()
{
	if (CheckCollisionPointRec(GetMousePosition(), usernameText))
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
		return;
	}

	if (CheckCollisionPointRec(GetMousePosition(), passwordText))
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
		return;
	}
	SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}