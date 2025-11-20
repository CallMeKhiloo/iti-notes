#include "main.h"

int main()
{
    char s1 [10] = "";
    char s2 [10] = "";
    cout << "Enter 2 strings: " << '\n';
    cin >> s1 >> s2;
    if(str_concat(s1, s2, sizeof(s1))){
        cout << s1 << '\n';
    }
    // if(str_cpy(s1, s2, sizeof(s1)))
    //     cout << s1 << '\n';
    // cout << str_cmp(s1, s2) << " "<< sizeof(s1);
    // cout << str_len(s1) << " " << str_len(s2) << '\n';
    // to_lower(s1);
    // to_capital(s2);
    // cout << s1 << " " << s2 << '\n';
    return 1;
}