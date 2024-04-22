#include "../lib/precompile.h"

int continueToTest = 5;

void mainMenuProcesses() {

    Rectangle registerNowButton = { 620, 610, 280, 70 };
    Rectangle loginNowButton = { 1020, 610, 280, 70 };

    loginPage();
    //questions();

    if (continueToTest == 0) {
        DrawText("Team Crocs", 500, 250, 150, BLACK);

        DrawRectangle(620, 610, 280, 70, BLUE);
        DrawText("Register", 685, 630, 35, LIGHTGRAY);

        DrawRectangle(1020, 610, 280, 70, BLUE);
        DrawText("Login", 1115, 630, 35, LIGHTGRAY);
    }

    if (CheckCollisionPointRec(GetMousePosition(), registerNowButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        continueToTest = 2;
    }

    if (CheckCollisionPointRec(GetMousePosition(), loginNowButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        continueToTest = 1;
    }

    if (continueToTest == 1) {
        loginPage();
    }

    if (continueToTest == 2) {
        registerPage();
    }
}