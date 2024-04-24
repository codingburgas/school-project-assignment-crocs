#include "../lib/precompile.h"
#include "../lib/preTestPage.h"

void preTestPage() {
    DrawRectangle(0, 0, 1920, 1080, LIGHTGRAY);

    //Draw Border
    Rectangle border(400, 215, 1120, 600);
    DrawRectangle(400, 215, 1120, 600, WHITE);
    DrawRectangleLinesEx(border, 1, BLACK);

    //Draw the start test text
    DrawText("Do you wish to start the test?", 650, 285, 40, BLACK);
    DrawText("If you start the test, you must finish all the questions before submitting.", 460, 380, 28, BLACK);

    Rectangle closeTestButton = { 800, 425, 320, 40 };
    DrawRectangle(1050, 625, 320, 40, LIGHTGRAY);
    DrawText("Start test", 1160, 635, 20, BLACK);


    Rectangle startTestButton = { 500, 425, 320, 40 };
    DrawRectangle(550, 625, 320, 40, LIGHTGRAY);
    DrawText("Close test", 655, 635, 20, BLACK);
    if (CheckCollisionPointRec(GetMousePosition(), startTestButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        
    }
}