#include "Complex.h"

Complex::Complex(double r, double i): real(r), imag(i){}

ostream& operator<<(ostream& out, const Complex& c){
    out<<c.real<<'+'<<c.imag<<'i';
    return out;
}
