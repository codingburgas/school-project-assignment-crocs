#pragma once


class reg {
public:
	void displayRegisterPage();
	void buttonHandler(pageBools& pages);
	void textBoxHandler();
	char username1[17] = "\0";
	int userCharCount1 = 0;
	char password1[17] = "\0";
	int passCharCount1 = 0;
	float borderThickness = 2;
	Font customFont = GetFontDefault();
	Color borderColor = BLACK;
	Rectangle usernameText = { 820, 415, 280, 45 };
	Rectangle backButton = { 1700, 50, 70, 70 };
	Rectangle passwordText = { 820, 515, 280, 45 };
	Rectangle registerButton = { 820, 660, 280, 90 };
	Rectangle Border = { 670, 215, 580, 600 };
};