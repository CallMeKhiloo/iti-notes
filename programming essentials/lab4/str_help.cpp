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
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0'){
        if(tolower(str1[i]) < tolower(str2[i])) return 1;
        else if (tolower(str1[i]) > tolower(str2[i])) return 2;
        i++;
    }
    if(str1[i] == '\0' && str2[i] == '\0') return 0;
    return str1[i] == '\0' ? 1:2;
}

void strcpy (char str1[], char str2[]){
    
}

int str_concat(char str1[], char str2[], )
