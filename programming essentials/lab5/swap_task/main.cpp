#include "main.h"

void swap1 (int *x, int *y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void swap2 (int *x, int *y){
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void swap3 (int *x, int *y){
    *x = *x * *y;
    *y = *x / *y;
    *x = *x / *y;
}

int main(){
    int x = 20, y = 100;
    swap3(&x, &y);
    cout << x << " " << y;
    return 1;
}