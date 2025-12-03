#include "khalil_stack.h"

int main(){
    stack_clone st = stack_clone();
    st.push(2);
    st.push(3);
    st.push(1);
    st.push(3);
    st.push(1);
    st.push(1);
    st.push(1);
    stack_clone st2 = stack_clone();
    cout << st2.getSize()<<'\n';
    st2 = st;
    cout << st2.getSize()<<'\n';
    while(!st2.empty()) cout << st2.pop();
    cout << endl;
    while(!st.empty()) cout << st.pop();

    return 0;
}