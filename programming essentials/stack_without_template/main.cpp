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
    
    while(!st.empty()) cout << st.pop();

    return 0;
}