#include "Geoshape.h"

Geoshape::Geoshape()
{
    dim1 = dim2 = 0;
}

Geoshape::Geoshape(float x)
{
    dim1 = dim2 = x;
}

Geoshape::Geoshape(float x, float y)
{
    dim1 = x;
    dim2 = y;
}

void Geoshape::setdim1(float x)
{
    dim1 = x;
}

void Geoshape::setdim2(float x)
{
    dim2 = x;
}

float Geoshape::getdim1()
{
    return dim1;
}

float Geoshape::getdim2()
{
    return dim2;
}

float Geoshape::calculateArea(){
    return 0;
}