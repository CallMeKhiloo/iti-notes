#include "string_clone.h"

string_clone::string_clone()
{
    size = 1;
    arr = new char[size];
    arr[0] = '\0';
}

string_clone::string_clone(const char *st) // string_clone("fdsf") or string_clone st = "fsdfawe"
{
    int x = 0;
    const char *curr = st;
    while (*curr != '\0')
    {
        x++;
        curr++;
    }
    size = x;
    arr = new char[size + 1]; // size + 1 for null terminator
    curr = st;
    x = 0;
    while (*curr != '\0')
    {
        arr[x] = *curr;
        x++;
        curr++;
    }
    arr[x] = '\0';
}

string_clone::string_clone(const string_clone &st) // copy constructor
{
    size = st.length();
    arr = new char[size + 1];
    const char *ptr = st.arr;
    int i = 0;
    while (*ptr != '\0')
    {
        *(arr + i) = *ptr;
        ptr++;
        i++;
    }
    arr[i] = '\0';
}

int string_clone::length() const
{
    return size;
}

char &string_clone::operator[](int index)
{
    if (index >= size || index < 0)
        throw out_of_range("index is out of bounds");
    return arr[index];
}

const char &string_clone::operator[](int index) const
{
    if (index >= size || index < 0)
        throw out_of_range("index is out of bounds");
    return arr[index];
}

string_clone &string_clone::operator=(const string_clone &st)
{
    if (this == &st)
        return *this;
    size = st.length();
    delete[] arr;
    arr = new char[size + 1];
    const char *ptr = st.arr;
    int i = 0;
    while (*ptr != '\0')
    {
        *(arr + i) = *ptr;
        ptr++;
        i++;
    }
    arr[i] = '\0';
    return *this;
}

string_clone &string_clone::operator=(const char *ptr)
{
    int x = 0;
    const char *curr = ptr;
    while (*curr != '\0')
    {
        x++;
        curr++;
    }
    size = x;
    delete[] arr;
    arr = new char[size + 1]; // size + 1 for null terminator
    curr = ptr;
    x = 0;
    while (*curr != '\0')
    {
        arr[x] = *curr;
        x++;
        curr++;
    }
    arr[x] = '\0';
    return *this;
}

ostream &operator<<(ostream &out, const string_clone &st)
{
    const char *ptr = st.arr;
    while (*ptr != '\0')
    {
        out << *ptr;
        ptr++;
    }
    out << '\n';
    return out;
}

string_clone::~string_clone()
{
    delete[] arr;
}