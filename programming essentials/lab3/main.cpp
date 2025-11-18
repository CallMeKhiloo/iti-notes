#include "main.h"
#include <stdio.h>

int main()
{
    int n;
    cout << "Enter an odd size for the magic square: ";
    cin >> n;

    if (n % 2 == 0 || n <= 0)
    {
        cout << "Size must be a positive odd number.\n";
        return 1;
    }

    vector<vector<int>> square(n, vector<int>(n, 0));

    int row = 0;
    int col = n / 2;

    for (int num = 1; num <= n * n; num++)
    {
        square[row][col] = num;

        gotoxy(col * 4 + 2, row + 5);
        cout << num;
        cout.flush();

        delay_half_second();

        int prev_row = row;
        int prev_col = col;

        row--;
        col++;
        check_borders(&row, &col, n);

        if (square[row][col] != 0 ||
            (prev_row == 0 && prev_col == n - 1))
        {
            row = prev_row + 1;
            col = prev_col;

            check_borders(&row, &col, n);
        }
    }

    gotoxy(1, n + 4);
    cout << "\nMagic square completed.\n";

    return 0;
}
