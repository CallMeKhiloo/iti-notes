#ifndef __COMPLEX_CLONE__
#define __COMPLEX_CLONE__

#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0);

    void setReal(double r);
    void setImag(double i);

    double getReal();
    double getImag();

    void display() const;

    // operator overloading
    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator/(const Complex &c);
    Complex operator*(const Complex &c);

    Complex operator+(double r);
    Complex operator-(double r);

    friend Complex operator+(const double r, const Complex &c); // double + complex

    Complex &operator+=(const Complex &c);
    Complex &operator-=(const Complex &c);
    Complex &operator*=(const Complex &c);
    Complex &operator/=(const Complex &c);

    Complex &operator++();   // prefix
    Complex operator++(int); // postfix
    Complex &operator--();   // prefix
    Complex operator--(int); // postfix

    bool operator==(const Complex&);
    bool operator!=(const Complex&);

    double &operator[](int);

    operator double(); // type conversion to get the magnitude

    Complex &operator=(const Complex &c);

    friend ostream &operator<<(ostream &out, const Complex &c);
};

#endif