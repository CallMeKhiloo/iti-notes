#ifndef __TERMINAL__
#define __TERMINAL__

#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>

using namespace std;

void gotoxy(int x, int y);
void resetColor();
void clearScreen();

#endif