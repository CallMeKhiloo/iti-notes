#include "main.h"

void gotoxy(int x, int y)
{
#ifdef _WIN32
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    cout << "\033[" << y << ";" << x << "H";
#endif
}

void delay_half_second()
{
#ifdef _WIN32
    Sleep(500);
#else
    this_thread::sleep_for(chrono::milliseconds(500));
#endif
}

void check_borders(int *r, int *c, int n)
{
    if (*r < 0)
        *r = n - 1;

    if (*c == n)
        *c = 0;
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}