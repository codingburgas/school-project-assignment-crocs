#include "../lib/precompile.h"

void mainMenuProcesses(activity currentMenu) {

    Rectangle registerNowButton = { 620, 610, 280, 70 };
    Rectangle loginNowButton = { 1020, 610, 280, 70 };


    if(currentMenu.mainMenu)
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
                currentMenu.activateRegister();
        }
        else if (CheckCollisionPointRec(GetMousePosition(), loginNowButton))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                currentMenu.activateLogin();
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
    if (currentMenu.loginPage)
        loginPage(currentMenu);

    if (currentMenu.registerPage)
        registerPage(currentMenu);
}