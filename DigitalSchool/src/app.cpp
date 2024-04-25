#include "../lib/precompile.h"
#include "../lib/app.h"

app::app()
{
    //Initialize main app screen
    InitWindow(screen.width, screen.height, "app");
    SetTargetFPS(30);
    testPage.questionsHandler();

    update();
}

void app::update()
{
    while (!WindowShouldClose())
    {
        display();
    }
    CloseWindow();
}

void app::display()
{
    BeginDrawing();

    //Set background color
    ClearBackground(RAYWHITE);

    pageHandler();

    EndDrawing();
}

void app::pageHandler()
{
    if (pageBools.mainMenuShouldDisplay)
    {
        mainMenu.displayMainMenu();
        mainMenu.buttonHandler(pageBools);
        return;
    }

    if (pageBools.registerPageShouldDisplay)
    {
        reg.displayRegisterPage();
        reg.buttonHandler(pageBools);
        reg.textBoxHandler();
        return;
    }

    if (pageBools.loginPageShouldDisplay)
    {
        login.displayLoginPage();
        login.buttonHandler(pageBools);
        login.textBoxHandler();
        return;
    }

    if (pageBools.preTestPageShouldDisplay)
    {
        preTestPage.displayPreTestPage();
        preTestPage.buttonHandler(pageBools);
        return;
    }

    if (pageBools.testPageShouldDisplay)
    {
        testPage.displayTestPage();
        testPage.drawQuestion();
        testPage.buttonHandler(pageBools);
        return;
    }

    if (pageBools.submitPageShouldDsiplay)
    {
        submitPage.marks = testPage.marks;
        submitPage.grade = testPage.grade;
        submitPage.displaySubmitPage();
        submitPage.buttonHandler(pageBools);
        return;
    }
}
