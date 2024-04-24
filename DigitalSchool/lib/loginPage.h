#pragma once
#include "precompile.h"
#include "pageHandle.h"
#include "login.h"
#include "files.h"

class login {
public:
	void displayLoginPage();
	void textBoxHandler();
	void buttonHandler(pageBools& pages);
	bool loginHandler();

	Font customFont = GetFontDefault();
	Color borderColor = GRAY;
	Rectangle usernameText = { 820, 415, 280, 45 };
	Rectangle backButton = { 1700, 50, 70, 70 };
	Rectangle passwordText = { 820, 515, 280, 45 };
	Rectangle loginButton = { 820, 660, 280, 90 };
	Rectangle Border = { 670, 215, 580, 600 };
	std::string username;
	std::string password;
	float borderThickness = 2;
};