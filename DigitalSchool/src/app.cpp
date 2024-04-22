#include "../lib/precompile.h"
#include "../lib/app.h"

app::app()
{
    //Initialize main app screen
    InitWindow(screen.width, screen.height, "app");
    SetTargetFPS(30);

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
    }

    //if (pageBools.registerPageShouldDisplay)
    //{
    //    
    //}

    if (pageBools.loginPageShouldDisplay)
    {
        login.displayLoginPage();
        login.buttonHandler(pageBools);
        login.textBoxHandler();
    }
}
