#include "../lib/precompile.h"
#include "../lib/loginPage.h"

void login::displayLoginPage()
{
	DrawTextEx(customFont, "Login Before Starting", Vector2{ 700, 280 }, 50, 3, BLACK);

	//Draw back button
	DrawRectangle(1700, 50, 70, 70, BLUE);
	DrawText("<-", 1705, 53, 70, LIGHTGRAY);

	//Draw username text box
	DrawRectangle(820, 415, 280, 45, RAYWHITE);
	DrawRectangleLinesEx(usernameText, borderThickness, borderColor);
	if (username[0] != '\0')
		DrawText(username, 835, 430, 20, BLACK);

	else DrawText("Username", 835, 430, 20, LIGHTGRAY);

	//Draw password text box
	DrawRectangle(820, 515, 280, 45, RAYWHITE);
	DrawRectangleLinesEx(passwordText, borderThickness, borderColor);
	if (password[0] != '\0')
	{
		for (int i = 0; i < passCharCount; i++)
			DrawText("*", 835 + i * 11, 530, 20, BLACK);
	}
	else DrawText("Password", 835, 530, 20, LIGHTGRAY);

	//Draw login button
	DrawRectangle(820, 660, 280, 90, BLUE);
	DrawText("Login", 905, 685, 40, LIGHTGRAY);

	DrawRectangleLinesEx(Border, 1, borderColor);
}

void login::buttonHandler(pageBools& pages)
{
	if (CheckCollisionPointRec(GetMousePosition(), loginButton))
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pages.mainMenuShouldDisplay = false;
			pages.registerPageShouldDisplay = false;
			pages.loginPageShouldDisplay = false;
			pages.preTestPageShouldDisplay = true;
			pages.testPageShouldDisplay = false;
		}
	}
	else
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
		}
		else
		{
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		}
}

void login::textBoxHandler()
{
	//username textbox
	if (CheckCollisionPointRec(GetMousePosition(), usernameText))
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
	else
	//password textbox
		if (CheckCollisionPointRec(GetMousePosition(), passwordText))
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
		else
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}