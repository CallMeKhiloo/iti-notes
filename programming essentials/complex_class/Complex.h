#ifndef __COMPLEX_CLONE__
#define __COMPLEX_CLONE__

#include <iostream>
using namespace std;

class Complex
{
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0);

    //copy constructor
    Complex(const Complex& c);

    void setReal(double r);
    void setImag(double i);

    double getReal();
    double getImag();

    //operator overloading
    Complex operator+(const Complex c);
    friend ostream& operator<<(ostream& out, const Complex& c);
};

#endif