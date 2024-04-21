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

    int StartTest = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        //Set background color
        ClearBackground(RAYWHITE);

        mainMenuProcesses();

        EndDrawing();
    }


    CloseWindow();
}