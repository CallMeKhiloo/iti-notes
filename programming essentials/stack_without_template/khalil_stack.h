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
    stack_clone(const stack_clone& st);

    stack_clone& operator=(const stack_clone& st);
    void push(int val);
    int pop();
    bool empty();
    int top();
    int getSize();

    ~stack_clone();
};

#endif