#ifndef __STRING_CLONE__
#define __STRING_CLONE__

#include <iostream>
using namespace std;

class string_clone
{
private:
    char *arr;
    int size;

public:
    string_clone();
    string_clone(const char *ptr);
    string_clone(const string_clone &st);

    int length() const;
    void append(const string_clone &st);

    string_clone &operator=(const string_clone &st);
    string_clone &operator=(const char *ptr);

    char &operator[](int index);
    const char &operator[](int index) const;
    friend ostream &operator<<(ostream &out, const string_clone &st);

    ~string_clone();
};

#endif