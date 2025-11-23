#include "main.h"

void array_manipulate(int (*ptr) [COLS], int rows){
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < COLS ; j++){
            ptr[i][j] = -1;
        }
    }
}

int main(){
    int rows;

    cout << "enter the number of rows you want: ";
    cin >> rows;

    int (*arr) [COLS] = (int (*) [COLS]) calloc(rows, sizeof(*arr));

    array_manipulate(arr, rows);

    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < COLS ; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    free(arr);
    return 0;
}