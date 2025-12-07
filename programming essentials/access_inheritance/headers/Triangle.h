#ifndef __TRIANGLE__
#define __TRIANGLE__

#include "Geoshape.h"

class Triangle : public Geoshape
{
public:
    Triangle(float b, float h);
    float calculateArea();
};

#endif