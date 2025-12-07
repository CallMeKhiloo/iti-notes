#include "Square.h"

Square::Square(float x) : Rect(x, x) {}

void Square::setSquareDim(float x)
{
    dim1 = dim2 = x;
}

float Square::getSquareDim()
{
    return dim1;
}

float Square::calculateArea()
{
    return Rect::calculateArea();
}