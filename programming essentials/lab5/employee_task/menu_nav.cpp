#include "main.h"

// ================= Terminal Utilities =================

void gotoxy(int x, int y)
{
#ifdef _WIN32
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    std::cout << "\033[" << y << ";" << x << "H";
#endif
}

void setColor(int c)
{
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (c)
    {
    case COLOR_WHITE:
        SetConsoleTextAttribute(h, 7);
        break;
    case COLOR_GREEN:
        SetConsoleTextAttribute(h, 10);
        break;
    }
#else
    switch (c)
    {
    case COLOR_WHITE:
        std::cout << "\033[37m";
        break;
    case COLOR_GREEN:
        std::cout << "\033[32m";
        break;
    }
#endif
}

void resetColor()
{
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
    std::cout << "\033[0m";
#endif
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// =============== getKey() (Handles Arrow Keys) =================

#ifdef _WIN32

int getKey()
{
    int ch = _getch();

    if (ch == 0 || ch == 224)
    {
        // Arrow keys
        int arrow = _getch();
        return arrow;
    }

    return ch;
}

#else

int getKey()
{
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    /*
    the above lines are to disable the canonical mode which buffers the input
    which would have forced us to press enter each time we press a key
    */
    if (ch == 27)
    {
        // Make stdin temporarily non-blocking
        int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

        int next1 = getchar();

        // Restore blocking mode
        fcntl(STDIN_FILENO, F_SETFL, flags);

        if (next1 == '[')
        {
            int arrow = getchar();
            return arrow;
        }
    }

    return ch;
}

#endif
