#include "../lib/precompile.h"

class display {
public:
	int width = GetScreenWidth();
	int height = GetScreenHeight();
};
display screen;

void app()
{
	//Initialize main app screen
	InitWindow(screen.width, screen.height, "app");
	SetTargetFPS(30);

	char username[15] = "\0";
	int userCharCount = 0;

	char password[15] = "\0";
	int passCharCount = 0;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		//Set background color
		ClearBackground(RAYWHITE);

		//Draw login button
		Rectangle loginButton = { 825, 730, 270, 120 };
		DrawRectangle(825, 730, 270, 120, BLUE);
		DrawText("Login", 835, 740, 100, LIGHTGRAY);

		//Draw username text box
		Rectangle passwordText = { 825, 630, 270, 65 };
		DrawRectangle(825, 630, 270, 65, BLUE);
		if(password[0] != '\0')
			DrawText(password, 835, 650, 30, LIGHTGRAY);
		else DrawText("Insert password", 835, 650, 30, LIGHTGRAY);

		//Draw password text box
		Rectangle usernameText = { 825, 530, 270, 65 };
		DrawRectangle(825, 530, 270, 65, BLUE);
		if(username[0] != '\0')
			DrawText(username, 835, 550, 30, LIGHTGRAY);
		else DrawText("Insert username", 835, 550, 30, LIGHTGRAY);


		//Check mouse position and change cursor accordingly
		if (CheckCollisionPointRec(GetMousePosition(), loginButton))
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		else if (CheckCollisionPointRec(GetMousePosition(), usernameText))
		{
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

		EndDrawing();
	}


	CloseWindow();
}