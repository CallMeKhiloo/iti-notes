#ifndef TERMINAL_UTILS
#define TERMINAL_UTILS

#include <iostream>
#include <thread> // deal with threads in order to use it with timing functions
#include <chrono> // to use time utilities

#define COLOR_RESET 0
#define COLOR_RED 1
#define COLOR_GREEN 2
#define COLOR_YELLOW 3
#define COLOR_BLUE 4
#define COLOR_MAGENTA 5
#define COLOR_CYAN 6
#define COLOR_WHITE 7

void gotoxy(int x, int y);
void setColor(int color);
void resetColor();
void clearScreen();

#endif