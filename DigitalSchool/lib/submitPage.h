#pragma once
#include "../lib/precompile.h"
#include "../lib/pageHandle.h"

class submitPage {
public:
    void displaySubmitPage();
    void buttonHandler(pageBools& pages);

    Rectangle navbar = { 30, 40, 1860, 120 };
    Rectangle topOutline1{ 30, 40, 1860, 120 };
    Rectangle middleOutline1{ 30, 200, 1860, 700 };
    Rectangle middleBox1{ 30, 200, 1860, 600 };
    Rectangle middleOutline2{ 60, 530, 1800, 50 };
    Rectangle middleBox2{ 60, 530, 1800, 50 };
    Rectangle middleOutline3{ 60, 578, 1800, 80 };
    Rectangle middleBox3{ 60, 578, 1800, 80 };
    Rectangle homeButton{ 800, 730, 320, 60 };

    //Texture2D* Logo = new Texture2D(LoadTexture("assets/crocs-logo.png"));

    float borderThickness = 1;
};