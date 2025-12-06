#ifndef KHALIL_STACK
#define KHALIL_STACK

using namespace std;
#include <stdexcept>
#include <iostream>

template <typename T>
class stack_clone
{
private:
    int size, curr;
    T *arr;

public:
    stack_clone()
    {
        this->arr = new T[5];
        this->curr = 0;
        this->size = 5;
    }
    stack_clone(const stack_clone &other)
    {
        if (this == &other)
            return;
        this->curr = other.curr;
        this->size = other.size;
        this->arr = new T[other.size];
        for (int i = 0; i < other.curr; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }

    stack_clone &operator=(const stack_clone &other)
    {
        if (this == &other)
            return *this;
        if (this->size < other.size)
        {
            this->size = other.size;
            delete[] this->arr;
            this->arr = new T[other.size];
        }
        this->curr = other.curr;
        for (int i = 0; i < other.curr; i++)
        {
            this->arr[i] = other.arr[i];
        }
        return *this; // to enable chaining st1=st2=st3
    }
    void push(T val)
    {
        if (this->curr < size)
        {
            this->arr[curr] = val;
            this->curr++;
        }
        else
        {
            this->size = this->size * 2;
            T *new_ptr = new T[this->size];
            for (int i = 0; i < this->size / 2; i++)
                new_ptr[i] = arr[i];
            new_ptr[curr] = val;
            delete[] arr;
            arr = new_ptr;
            curr++;
        }
    }
    T pop()
    {
        if (this->curr > 0)
        {
            T val = this->arr[curr - 1];
            this->curr--;
            return val;
        }
        else
        {
            throw out_of_range("Cannot pop from an empty stack");
        }
    }
    bool empty()
    {
        return curr == 0;
    }
    T top()
    {
        if (this->empty())
        {
            throw out_of_range("Stack is empty");
        }
        return this->arr[curr - 1];
    }
    int getSize()
    {
        return this->size;
    }

    ~stack_clone()
    {
        delete[] this->arr;
    }
};

#endif