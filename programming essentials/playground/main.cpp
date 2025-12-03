#include <iostream>
using namespace std;
#include "main.h"
#include <stdbool.h>
int& get(){
    int a = 20;
    return a;
}

// #define int long int

int main(){
    int z = 5;
    int &x = z;

    cout << sizeof(int&) << endl;
    cout << sizeof(x) << endl;
}