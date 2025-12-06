#include "Complex.h"

int main()
{
    Complex c1 = Complex(10, 2);

    c1.display();
    cout << c1;
    cout << c1.getReal() << " " << c1.getImag() << '\n';
    c1.setReal(7);
    c1.setImag(9);
    cout << c1 << '\n';

    Complex c2 = Complex(-1, -5);

    Complex res = c1 + c2;
    cout << "result of summation is: " << res;
    cout << "result of subtraction is: " << res - c2;
    cout << "result of multiplication is: " << res * c1;
    cout << "result of division is: " << c1 / res;

    cout << "adding complex to double: " << res + 2.0;
    cout << "adding double to complex: " << 2.0 + res;

    c1 += c2;

    cout << "using Complex += Complex with c1+=c2 : " << c1;

    ++c1;
    cout << "using ++Complex with ++c1: " << c1;
    c2 = c1++;
    cout << "value of c2 after using c2 = c1++ : " << c2 << " while value of c1 = " << c1;

    c1[0] = 0;
    cout << "value of c1 after using c1[0] = 0 :  " << c1;

    double val = c1;

    cout << "magnitude after using double val = c1 is : " << val << '\n';

    return 0;
}