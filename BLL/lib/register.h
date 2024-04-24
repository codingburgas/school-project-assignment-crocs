#pragma once

bool checkPassword(std::string password);

bool reg(std::fstream& loginFile, std::string registerUsername, std::string registerPassword, std::string registerEmail);

bool checkUsername(std::string username);

bool checkEmail(std::string email);