#ifndef MAIN
#define MAIN

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fcntl.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

// X coordinate where the menu is centered
#define MENU_CENTER_X 40

// Y coordinate to start drawing the menu
#define MENU_START_Y 10

// Vertical spacing between menu items
#define MENU_SPACING 2

#define COLOR_DEFAULT 0
#define COLOR_GREEN 32
#define COLOR_WHITE 37

using namespace std;
// Key codes (abstracted per OS)
#ifdef _WIN32
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESCAPE 27
#define KEY_HOME 71
#define KEY_END 79
#else
#define KEY_UP 'A'
#define KEY_DOWN 'B'
#define KEY_ENTER 10
#define KEY_ESCAPE 27
#define KEY_HOME 72
#define KEY_END 70
#define KEY_LEFT 68
#define KEY_RIGHT 67
#endif

void gotoxy(int x, int y);
void setColor(int color);
void resetColor();
void clearScreen();
int getKey();

void drawMenu(
    const std::vector<std::string> &items,
    int selectedIndex);

// ========= Navigation & Pages =========
void showMenu();        // handles movement + calling drawMenu()
void startPage(int id); // displays page after pressing Enter

typedef struct Employee
{
    char name[20];
    int age;
    int salary;
    Employee *next;
} Employee;

extern Employee *head;
extern Employee *last;

void create_employee();
void display_employees();

#endif