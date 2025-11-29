#ifndef __MAIN__
#define __MAIN__

#include <iostream>
#include <string>
#include <cstring>
#include <fcntl.h>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <fstream>

// X coordinate where the menu is centered
#define MENU_CENTER_X 40

// Y coordinate to start drawing the menu
#define MENU_START_Y 10

// Vertical spacing between menu items
#define MENU_SPACING 2

#define COLOR_DEFAULT 0
#define COLOR_GREEN 32
#define COLOR_WHITE 37
#define COLOR_BLACK 30

#define KEY_UP 1065
#define KEY_DOWN 1066
#define KEY_ENTER 10
#define KEY_ESCAPE 27
#define KEY_HOME 1072
#define KEY_INSERT 1050
#define KEY_DELETE 1051
#define KEY_END 1070
#define KEY_LEFT 1068
#define KEY_RIGHT 1067
#define KEY_BACKSPACE 127



using namespace std;

void gotoxy(int x, int y);
void setColor(int fg, int bg);
void resetColor();
void clearScreen();
int getKey();

void drawMenu(
    const std::vector<std::string> &items,
    int selectedIndex);

// ========= Navigation & Pages =========
void showMenu();        // handles movement + calling drawMenu()
void startPage(int id); // displays page after pressing Enter

void integer_validation (int *num, int limit);
void newText();
void displayFile();

#endif