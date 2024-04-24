#pragma once
#include "precompile.h"
#include "mainMenu.h"
#include "loginPage.h"
#include "registerPage.h"
#include "preTestPage.h"
#include "testPage.h"
#include "submitPage.h"
#include "pageHandle.h"
class displayRes {
public:
    int width = 1920; //GetScreenWidth();
    int height = 1080; //GetScreenHeight();
};

class app {
public:
    app();
    void display();
    void update();
    void pageHandler();

    char username[15] = "\0";
    int userCharCount = 0;
    char password[15] = "\0";
    int passCharCount = 0;
    mainMenu mainMenu;
    login login;
    reg reg;
    displayRes screen;
    pageBools pageBools;
    testPage testPage;
    preTestPage preTestPage;
    submitPage submitPage;
};
