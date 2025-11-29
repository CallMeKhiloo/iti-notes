#include "main.h"
void newText()
{
    system("clear");
    int size;
    cout << "Enter the size of your text: ";
    integer_validation(&size, __INT_MAX__);

    // allocate memory for the line
    char *buffer = (char *)malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++)
        buffer[i] = ' ';
    buffer[size] = '\0';

    int pos = 0;
    int startX = 5, startY = 5;
    gotoxy(startX, startY);
    setColor(30, 47);
    for (int i = 0; i <= size; i++)
        cout << ' ';
    gotoxy(startX, startY);

    while (true)
    {
        int ch = getKey();
        if(ch == KEY_ESCAPE) break;
        else if (ch == KEY_BACKSPACE)
        {
            if (pos > 0)
            {
                pos--;
                buffer[pos] = ' ';
                gotoxy(startX + pos, startY);
                cout << ' ';
                gotoxy(startX + pos, startY);
            }
        }
        else if (ch == KEY_RIGHT)
        {
            pos++;
            if (pos > size) pos = 0;
            gotoxy(startX + pos, startY);
        }
        else if (ch == KEY_LEFT)
        {
            pos--;
            if (pos < 0) pos = size;
            gotoxy(startX + pos, startY);
        }
        else if (ch >= 32 && ch <= 126)
        {
            if (pos < size)
            {
                buffer[pos] = (char)ch;
                cout << (char)ch;
                pos++;
            }
        }
    }

    resetColor();
    cout << "\n1. Append to file\n2. Overwrite file\nChoose: ";
    int option;
    integer_validation(&option, 2);

    ofstream file;
    if (option == 1)
        file.open("file.txt", ios::app);
    else if (option == 2)
        file.open("file.txt", ios::trunc);

    file << buffer << '\n';
    file.close();

    free(buffer);
}

void displayFile() {
    system("clear");
    gotoxy(0,0);
    ifstream file("file.txt");
    char ch;
    while (file.get(ch)) cout << ch;
    file.close();
    int key = getKey();
    while(key != KEY_ESCAPE && key != KEY_HOME){
        key = getKey();
    };
    clearScreen();
}