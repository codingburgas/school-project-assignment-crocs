#include "../lib/precompile.h"
#include "../lib/mainMenu.h"
#include "../lib/pageHandle.h"

void mainMenu::displayMainMenu() {
    DrawText("Team Crocs", 500, 250, 150, BLACK);

    DrawRectangle(620, 610, 280, 70, BLUE);
    DrawText("Register", 685, 630, 35, LIGHTGRAY);

    DrawRectangle(1020, 610, 280, 70, BLUE);
    DrawText("Login", 1115, 630, 35, LIGHTGRAY);
}

void mainMenu::buttonHandler(pageBools& pages)
{
    //register button
    if (CheckCollisionPointRec(GetMousePosition(), registerNowButton))
    {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            pages.mainMenuShouldDisplay = false;
            pages.registerPageShouldDisplay = true;
            pages.loginPageShouldDisplay = false;
        }
    }
    else
        //login button
        if (CheckCollisionPointRec(GetMousePosition(), loginNowButton))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                pages.mainMenuShouldDisplay = false;
                pages.registerPageShouldDisplay = false;
                pages.loginPageShouldDisplay = true;
            }
        }
        else
        {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }
}
