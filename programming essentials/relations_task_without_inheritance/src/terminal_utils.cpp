#include "terminal_utils.h"

void gotoxy(int x, int y)
{
    cout << "\033[" << y << ";" << x << "H";
}

void resetColor()
{
    std::cout << "\033[0m";
}

void clearScreen()
{
    system("clear");
}