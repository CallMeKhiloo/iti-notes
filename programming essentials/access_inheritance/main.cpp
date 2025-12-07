#include "main.h"

int main()
{
    Circle c(7);
    Square s(4);
    Triangle t(3, 6);



    std::cout << "Circle Area: " << c.calculateArea() << std::endl;
    std::cout << "Square Area: " << s.calculateArea() << std::endl;
    std::cout << "Triangle Area: " << t.calculateArea() << std::endl;

    return 0;
}