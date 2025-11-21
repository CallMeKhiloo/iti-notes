#include "main.h"

// Draw the full menu
void drawMenu(const std::vector<std::string> &items, int selectedIndex)
{
    clearScreen();

    for (int i = 0; i < items.size(); i++)
    {
        int y = MENU_START_Y + i * MENU_SPACING;

        gotoxy(MENU_CENTER_X, y);

        if (i == selectedIndex)
            setColor(COLOR_GREEN);
        else
            setColor(COLOR_WHITE);

        std::cout << items[i];
    }

    resetColor();
}

// Page displayed after selecting an item
void startPage(int id)
{
    clearScreen();

    gotoxy(MENU_CENTER_X, MENU_START_Y);

    switch (id)
    {
    case 0:
        gotoxy(0,0);
        create_employee();
        break;
    case 1:
        gotoxy(0,0);
        display_employees();
        return;
    case 2:
        std::cout << "Exit";
        break;
    }

    resetColor();

    gotoxy(MENU_CENTER_X, MENU_START_Y + 10);
    std::cout << "[Press ESC or HOME to return]";

    int key;
    do
    {
        key = getKey();
    } while (key != KEY_ESCAPE && key != KEY_HOME);
}

// Main menu logic
void showMenu()
{
    std::vector<std::string> items = {"New", "Display", "Exit"};

    int selected = 0;
    int key = 0;

    while (true)
    {
        drawMenu(items, selected);
        key = getKey();

        if (key == KEY_UP || key == KEY_LEFT)
        {
            selected--;
            if (selected < 0)
                selected = items.size() - 1;
        }
        else if (key == KEY_DOWN || key == KEY_RIGHT)
        {
            selected++;
            if (selected >= items.size())
                selected = 0;
        }
        else if (key == KEY_ENTER)
        {
            if (selected == 2)
                return; // exit chosen

            startPage(selected);
        }
        else if (key == KEY_HOME)
        {
            selected = 0;
        }
        else if (key == KEY_END)
        {
            selected = items.size() - 1;
        }
    }
}
