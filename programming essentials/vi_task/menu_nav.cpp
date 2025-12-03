#include "main.h"

// ================= Terminal Utilities =================

void gotoxy(int x, int y)
{
    std::cout << "\033[" << y << ";" << x << "H";
}

// Set text color (foreground: 30-37, background: 40-47)
void setColor(int fg, int bg)
{
    if (bg == 0)
    {
        switch (fg)
        {
        case COLOR_WHITE:
            std::cout << "\033[37m";
            break;
        case COLOR_GREEN:
            std::cout << "\033[32m";
            break;
        }
    }
    else
        cout << "\033[" << fg << ";" << bg << "m";
}

void resetColor()
{
    std::cout << "\033[0m";
}

void clearScreen()
{
    system("clear");
}

// =============== getKey() (Handles Arrow Keys) =================

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

    // Not an escape sequence → return directly
    if (ch != 27)
        return ch;

    // ESC detected → make non-blocking
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

    int next1 = getchar();
    int next2 = getchar();
    int next3 = getchar(); // may be -1
    int next4 = getchar();

    // Restore blocking mode
    fcntl(STDIN_FILENO, F_SETFL, flags);

    // Handle ESC[
    if (next1 == '[' || next1 == 79)
    {
        return next2+1000;
    }

    return 27; // ESC alone
}
