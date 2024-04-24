#pragma once
#include "../lib/precompile.h"
#include "../lib/preTestPage.h"

class preTestPage {
public:
	void displayPreTestPage();
	void buttonHandler(pageBools& pages);
	Rectangle border{ 400, 215, 1120, 600 };
	Rectangle closeTestButton = { 550, 605, 320, 40 };
	Rectangle startTestButton = { 1050, 605, 320, 40 };
};