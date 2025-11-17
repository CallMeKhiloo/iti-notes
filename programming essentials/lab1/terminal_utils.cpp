#include "terminal_utils.h"

#ifdef _WIN32
#include <windows.h>
// Windows implementation
void gotoxy(int x, int y)
{
  COORD coord{(SHORT)(x - 1), (SHORT)(y - 1)};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color)
{
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  WORD wColor;
  switch (color)
  {
  case COLOR_RED:
    wColor = FOREGROUND_RED;
    break;
  case COLOR_GREEN:
    wColor = FOREGROUND_GREEN;
    break;
  case COLOR_YELLOW:
    wColor = FOREGROUND_RED | FOREGROUND_GREEN;
    break;
  case COLOR_BLUE:
    wColor = FOREGROUND_BLUE;
    break;
  case COLOR_MAGENTA:
    wColor = FOREGROUND_RED | FOREGROUND_BLUE;
    break;
  case COLOR_CYAN:
    wColor = FOREGROUND_GREEN | FOREGROUND_BLUE;
    break;
  case COLOR_WHITE:
    wColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    break;
  default:
    wColor = 7;
  }
  SetConsoleTextAttribute(h, wColor | FOREGROUND_INTENSITY);
}

void resetColor()
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                          FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void clearScreen()
{
  system("cls");
}

#else
// Linux / macOS implementation
void gotoxy(int x, int y)
{
  std::cout << "\033[" << y << ";" << x << "H";
}

void setColor(int color)
{
  int code = 37;
  switch (color)
  {
  case COLOR_RED:
    code = 31;
    break;
  case COLOR_GREEN:
    code = 32;
    break;
  case COLOR_YELLOW:
    code = 33;
    break;
  case COLOR_BLUE:
    code = 34;
    break;
  case COLOR_MAGENTA:
    code = 35;
    break;
  case COLOR_CYAN:
    code = 36;
    break;
  case COLOR_WHITE:
    code = 37;
    break;
  }
  std::cout << "\033[" << code << "m";
}

void resetColor()
{
  std::cout << "\033[0m";
}

void clearScreen()
{
  system("clear");
}
#endif