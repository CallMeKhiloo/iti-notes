#include "khalil_stack.h"

stack_clone::stack_clone()
{
    this->arr = new int[5];
    this->curr = 0;
    this->size = 5;
}

void stack_clone::push(int x)
{
    if (this->curr < size)
    {
        this->arr[curr] = x;
        this->curr++;
    }
    else
    {
        this->size = this->size * 2;
        int *new_ptr = new int[this->size];
        for (int i = 0; i < this->size / 2; i++)
            new_ptr[i] = arr[i];
        new_ptr[curr] = x;
        delete[] arr;
        arr = new_ptr;
        curr++;
    }
}

int stack_clone::pop()
{
    if (this->curr > 0)
    {
        int val = this->arr[curr - 1];
        this->curr--;
        return val;
    }
    else
    {
        throw out_of_range("Cannot pop from an empty stack");
    }
}

bool stack_clone::empty()
{
    return curr == 0;
}

int stack_clone::top()
{
    if (this->empty())
    {
        throw out_of_range("Stack is empty");
    }
    return this->arr[curr - 1];
}

stack_clone::~stack_clone()
{
    delete[] this->arr;
}