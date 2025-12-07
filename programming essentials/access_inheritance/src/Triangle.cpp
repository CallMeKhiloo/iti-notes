#include "Triangle.h"

Triangle::Triangle(float b, float h) : Geoshape(b, h) {};

float Triangle::calculateArea()
{
    return (getdim1() * getdim2()) / 2;
}