#include "Complex.h"

Complex::Complex(double r, double i) : real(r), imag(i) {}

void Complex::display() const
{
    cout << *this;
}

void Complex::setReal(double r)
{
    real = r;
}

void Complex::setImag(double i)
{
    imag = i;
}

double Complex::getReal()
{
    return real;
}

double Complex::getImag()
{
    return imag;
}

Complex Complex::operator+(const Complex &c)
{
    return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator-(const Complex &c)
{
    return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator*(const Complex &c)
{
    return Complex(real * c.real, imag * c.imag);
}

Complex Complex::operator/(const Complex &c)
{
    return Complex(real / c.real, imag / c.imag);
}

Complex &Complex::operator+=(const Complex &c)
{
    real += c.real;
    imag += c.imag;
    return *this;
}
Complex &Complex::operator-=(const Complex &c)
{
    real -= c.real;
    imag -= c.imag;
    return *this;
}
Complex &Complex::operator*=(const Complex &c)
{
    real *= c.real;
    imag *= c.imag;
    return *this;
}
Complex &Complex::operator/=(const Complex &c)
{
    if (c.real == 0 || c.imag == 0)
    {
        cout << "Can't divide by zero !!" << '\n';
        return *this;
    }
    real /= c.real;
    imag /= c.imag;
    return *this;
}

Complex &Complex::operator++()
{
    real++;
    return *this;
}

Complex Complex::operator++(int)
{
    Complex curr = *this;
    real++;
    return curr;
}

Complex &Complex::operator--()
{
    real--;
    return *this;
}

Complex Complex::operator--(int)
{
    Complex curr = *this;
    real--;
    return curr;
}

Complex Complex::operator+(double r) // complex + double
{
    return Complex(real + r, imag);
}

Complex Complex::operator-(double r) // complex - double
{
    return Complex(real - r, imag);
}

Complex operator+(const double r, const Complex &c)
{
    return Complex(c.real + r, c.imag);
}

Complex &Complex::operator=(const Complex &c) // assignment operator
{
    if (this == &c)
        return *this;
    real = c.real;
    imag = c.imag;

    return *this;
}

bool Complex::operator==(const Complex &c)
{
    if (real == c.real && imag == c.imag)
        return true;
    return false;
}

bool Complex::operator!=(const Complex &c)
{
    if (real != c.real || imag != c.imag)
        return true;
    return false;
}

double &Complex::operator[](int index)
{
    if (index == 0)
        return real;
    else if (index == 1)
        return imag;
    throw out_of_range("index must be 0 or 1");
}

Complex::operator double() // gets the magnitude
{
    return sqrt(real * real + imag * imag);
}

ostream &operator<<(ostream &out, const Complex &c)
{
    out << c.real << '+' << c.imag << 'i' << '\n';
    return out;
}
