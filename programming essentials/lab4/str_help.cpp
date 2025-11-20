#include "main.h"

int str_len(char arr[])
{
    int i = 0;
    while (arr[i] != '\0')
        i++;
    return i;
}

void to_lower(char arr[]){
    int i = 0;
    while(arr[i] != '\0'){
        if(arr[i] >= 65 && arr[i] <= 90){
            arr[i] = (arr[i] - 'A') + 'a';
        }
        i++;
    }
}

void to_capital(char arr[]){
    int i = 0;
    while(arr[i] != '\0'){
        if(arr[i] >= 97 && arr[i] <= 122){
            arr[i] = (arr[i] - 'a') + 'A';
        }
        i++;
    }
}

int str_cmp(char str1[], char str2[]){
    if (str_len(str1) != str_len(str2)) return str_len(str1) < str_len(str2)? 1:2;
    int i = 0;
    while(str1[i] != '\0'){
        if(str1[i] != str2[i]) return -1;
        i++;
    }
    return 0;
}

bool str_cpy (char str1[], char str2[], int str1_size){
    if(str_len(str2) >= str1_size) return 0;
    int i = 0;
    while (str2[i] != '\0'){
        str1[i] = str2[i];
        i++;
    }
    str1[i] = str2[i];
    return 1;
}

bool str_concat (char str1[], char str2[], int str1_size){
    if( (str_len(str1) + str_len(str2)) >= str1_size ) return 0;
    int i = 0, str1_length = str_len(str1);
    while(str2[i] != '\0'){
        str1[i + str1_length] = str2[i];
        i++;
    }
    str1[i + str1_length] = str2[i];
    return 1;
}