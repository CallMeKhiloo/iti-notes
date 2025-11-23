#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void gotoxy(int x, int y);
void delay_half_second();
void check_borders(int *r, int *c, int n);
void clearScreen();

#endif