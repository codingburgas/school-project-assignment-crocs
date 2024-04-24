#include "../lib/precompileBLL.h"
#include "../lib/register.h"

bool checkPassword(std::string password)
{
    bool checkSize = false;
    bool checkSpaces = false;
    bool checkUpper = false;
    bool checkSpecial = false;
    bool checkNumber = false;

    if (password.size() >= 6 && password.size() <= 16) checkSize = true;

    if (password.find(' ') != std::string::npos) checkSpaces = true;

    for (int i = 0; i < password.size(); i++)
    {
        if (password[i] >= 65 && password[i] <= 90) checkUpper = true;
        if (password[i] >= 48 && password[i] <= 57) checkNumber = true;
        if (!(password[i] >= 65 && password[i] <= 90) && !(password[i] >= 48 && password[i] <= 57) && !(password[i] >= 97 && password[i] <= 122)) checkSpecial = true;
    }

    if (checkSize && checkUpper && checkNumber && checkSpecial && !checkSpaces)
        return true;
    else
        return false;
}

bool reg(std::fstream& loginFile, std::string registerUsername, std::string registerPassword, std::string registerEmail)
{
    bool checkValidity = false;
    if (checkPassword(registerPassword) && checkUsername(registerUsername) && checkEmail(registerEmail))
    {
        checkValidity = true;
    }
    if (checkValidity)
    {
        bool checkFind = false;
        while (!loginFile.eof())
        {
            std::string line;
            getline(loginFile, line);
            if (line.find(registerUsername) != std::string::npos)
            {
                checkFind = true;
                break;
            }

        }
        if (!checkFind)
        {
            loginFile << std::endl << registerUsername + " " + registerPassword;
        }
        return !checkFind;
    }
    return false;
}

bool checkUsername(std::string username)
{
    return username.find(' ') != std::string::npos;
}

bool checkEmail(std::string email)
{
    return email.find('@') != std::string::npos;
}