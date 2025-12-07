#include "Rect.h"

Rect::Rect(float x, float y) : Geoshape(x, y) {};

float Rect::calculateArea()
{
    return dim1 * dim2;
}