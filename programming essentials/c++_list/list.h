#ifndef __LIST__
#define __LIST__

#include <any>
#include <stdexcept>
#include <iostream>

class PyList
{
private:
    std::any *data;  // raw dynamic array
    size_t capacity; // allocated size
    size_t length;   // current number of elements

    void resize(size_t new_cap)
    {
        std::any *new_data = new std::any[new_cap];
        for (size_t i = 0; i < length; i++)
            new_data[i] = data[i];

        delete[] data;
        data = new_data;
        capacity = new_cap;
    }

    // convert negative index to positive
    long normalize_index(long idx) const
    {
        if (idx < 0)
            idx = long(length) + idx;
        if (idx < 0 || idx >= long(length))
            throw std::out_of_range("Index out of range");
        return idx;
    }

public:
    PyList()
        : data(nullptr), capacity(0), length(0) {}

    ~PyList()
    {
        delete[] data;
    }

    size_t size() const { return length; }

    // ---------- append ----------
    void append(const std::any &value)
    {
        if (length == capacity)
        {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[length++] = value;
    }

    // ---------- index operator ----------
    std::any &operator[](long index)
    {
        long i = normalize_index(index);
        return data[i];
    }

    const std::any &operator[](long index) const
    {
        long i = normalize_index(index);
        return data[i];
    }

    // ---------- get<T>() ----------
    template <typename T>
    T get(long index) const
    {
        long i = normalize_index(index);
        return std::any_cast<T>(data[i]);
    }
};

#endif
