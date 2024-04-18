#include "../lib/precompile.h"

class display {
public:
	int width = GetScreenWidth();
	int height = GetScreenHeight();
};
display screen;

void app()
{
	InitWindow(screen.width, screen.height, "app");
	SetTargetFPS(30);
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(WHITE);
		DrawText("TEXT", 190, 200, 20, GRAY);

		EndDrawing();
	}


	CloseWindow();
}