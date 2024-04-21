#include "../lib/precompile.h"

int StartTest = 0;

void mainMenuProcesses() {

    Rectangle registerNowButton = { 820, 610, 280, 90 };

    if (StartTest == 0) {
        DrawText("Team Crocs", 500, 250, 150, BLACK);

        DrawRectangle(820, 610, 280, 90, BLUE);
        DrawText("Register Now", 850, 638, 35, LIGHTGRAY);
    }

    if (CheckCollisionPointRec(GetMousePosition(), registerNowButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        StartTest = 1;
    }

    if (StartTest == 1) {
        loginPage();
    }
}