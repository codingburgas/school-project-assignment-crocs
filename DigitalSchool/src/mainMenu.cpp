#include "../lib/precompile.h"

bool mainMenuActive = true;
bool loginPageActive = false;
bool registerPageActive = false;

void mainMenuProcesses() {

    Rectangle registerNowButton = { 620, 610, 280, 70 };
    Rectangle loginNowButton = { 1020, 610, 280, 70 };


    if(mainMenuActive)
    {
        DrawText("Team Crocs", 500, 250, 150, BLACK);

        DrawRectangle(620, 610, 280, 70, BLUE);
        DrawText("Register", 685, 630, 35, LIGHTGRAY);

        DrawRectangle(1020, 610, 280, 70, BLUE);
        DrawText("Login", 1115, 630, 35, LIGHTGRAY);

        if (CheckCollisionPointRec(GetMousePosition(), registerNowButton))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                mainMenuActive = false;
                loginPageActive = false;
                registerPageActive = true;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), loginNowButton))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                mainMenuActive = false;
                loginPageActive = true;
                registerPageActive = false;
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
    if (loginPageActive)
        loginPage();
    if (registerPageActive)
    {
        registerPage();
    }
}