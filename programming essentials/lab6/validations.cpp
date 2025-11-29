#include "main.h"
void integer_validation (int *num, int limit){
    while (true)
    {
        string line;
        getline(cin, line);

        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        bool valid = !line.empty();
        for (char c : line)
        {
            if (!isdigit(c))
            {
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            clearScreen();
            gotoxy(MENU_CENTER_X, MENU_START_Y);
            cout << "Input must be ONLY a number, Please try again: \n";
            gotoxy(MENU_CENTER_X, MENU_START_Y+1);
            continue;
        }

        *num = std::stoi(line);
        if (*num <= 0 || *num > limit)
        {
            clearScreen();
            gotoxy(MENU_CENTER_X, MENU_START_Y);
            cout << "Invalid number. Please enter a valid positive number: \n";
            gotoxy(MENU_CENTER_X, MENU_START_Y+1);
            continue;
        }
        clearScreen();
        break;
    }
}