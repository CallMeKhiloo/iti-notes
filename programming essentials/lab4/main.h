#ifndef MAIN_H
#define MAIN_H
using namespace std;

#include <iostream>
#include <string>

int str_len(char arr[]);
void to_lower(char arr[]);
void to_capital(char arr[]);
int str_cmp(char str1[], char str2[]);
bool str_cpy (char str1[], char str2[], int size);
bool str_concat (char str1[], char str2[], int str1_size);

#endif