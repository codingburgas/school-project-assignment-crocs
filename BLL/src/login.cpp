#include "../lib/precompile.h"
#include "../lib/login.h"

bool login(std::fstream& loginFile)
{
    bool check = false;
    std::string loginUsername;
    std::string loginPassword;
    std::string line;
    std::string inputLine;

    std::cin >> loginUsername;
    std::cin >> loginPassword;

    inputLine = loginUsername + " " + loginPassword;

    while (!loginFile.eof())
    {
        getline(loginFile, line);
        if (line == inputLine)
        {
            check = true;
            break;
        }
    }
    return check;
}