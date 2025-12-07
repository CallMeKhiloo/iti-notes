#include "string_clone.h"

int main()
{
    string_clone st = string_clone("gsfgasf");

    cout << "string st = " << st;
    cout << "st has size of = " << st.length() << '\n';

    string_clone st2 = st;

    cout << "string st2 = " << st2;
    cout << "st2 has size of = " << st2.length() << '\n';

    st = "khalil";
    cout << "output of st = khalil then st : " << st;
    cout << st[5]<<'\n';

    return 0;
}