#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <iostream>

int main()
{
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    std::cout << ch << " ";
    while (ch = getchar())
    {
        std::cout << ch << " ";
    }
}