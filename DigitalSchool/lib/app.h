#pragma once

void app();

class activity {
public:
    bool mainMenu = 1;
    bool loginPage = 0;
    bool registerPage = 0;

    void activateMain()
    {
        mainMenu = 1;
        loginPage = 0;
        registerPage = 0;
    }

    void activateLogin()
    {
        mainMenu = 0;
        loginPage = 1;
        registerPage = 0;
    }

    void activateRegister()
    {
        mainMenu = 0;
        loginPage = 0;
        registerPage = 1;
    }
};