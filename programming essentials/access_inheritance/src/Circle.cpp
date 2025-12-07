#include "Circle.h"

Circle::Circle(float r): Geoshape(r){}

void Circle::setRadius(float r)
{
    dim1 = dim2 = r;
}

float Circle::getRadius()
{
    return dim1;
}

float Circle::calculateArea()
{
    return 22.0/7.0 * dim1 * dim1;
}