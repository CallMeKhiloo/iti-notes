#include "khalil_stack.h"

stack_clone::stack_clone()
{
    this->arr = new int[5];
    this->curr = 0;
    this->size = 5;
}

// copy constructor
stack_clone::stack_clone(const stack_clone &other)
{
    if(this == &other) return;
    this->curr = other.curr;
    this->size = other.size;
    this->arr = new int[other.size];
    for (int i = 0; i < other.curr; i++)
    {
        this->arr[i] = other.arr[i];
    }
}

// assignment operator overloading
stack_clone& stack_clone::operator=(const stack_clone &other)
{
    if (this == &other) return *this;
    if (this->size < other.size)
    {
        this->size = other.size;
        delete[] this->arr;
        this->arr = new int[other.size];
    }
    this->curr = other.curr;
    for (int i = 0; i < other.curr; i++)
    {
        this->arr[i] = other.arr[i];
    }
    return *this; // to enable chaining st1=st2=st3
}

int stack_clone::getSize(){
    return this->size;
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