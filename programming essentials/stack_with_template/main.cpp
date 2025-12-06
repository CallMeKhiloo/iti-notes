#include "khalil_stack.h"

int main(){
    stack_clone st = stack_clone<string>();
    st.push("fsdf");
    st.push("fsdfs");
    st.push("fsdf");
    st.push("fdv");
    st.push("bncvs");
    st.push("bger");
    st.push("bsfdg");
    stack_clone st2 = stack_clone<string>();
    cout << st2.getSize()<<'\n';
    st2 = st;
    cout << st2.getSize()<<'\n';
    while(!st2.empty()) cout << st2.pop() << endl;
    cout << endl;
    while(!st.empty()) cout << st.pop() << endl;
    cout << endl;

    return 0;
}