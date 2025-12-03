#ifndef KHALIL_STACK
#define KHALIL_STACK

using namespace std;
#include <stdexcept>
#include <iostream>

class stack_clone
{
private:
    int size, curr;
    int *arr;
public:
    stack_clone();

    void push(int val);
    int pop();
    bool empty();
    int top();

    ~stack_clone();
};

#endif