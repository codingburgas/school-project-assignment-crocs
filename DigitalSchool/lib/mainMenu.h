#pragma once
#include "precompile.h"
#include "pageHandle.h"

class mainMenu {
public:
    void displayMainMenu();
    void buttonHandler(pageBools& pages);
private:
    Rectangle registerNowButton = { 620, 610, 280, 70 };
    Rectangle loginNowButton = { 1020, 610, 280, 70 };
};