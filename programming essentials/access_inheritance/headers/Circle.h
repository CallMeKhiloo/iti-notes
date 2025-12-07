#ifndef __CIRCLE__
#define __CIRCLE__

#include "Geoshape.h"

class Circle : public Geoshape
{
public:
    Circle(float r);
    void setRadius(float r);
    float getRadius();
    float calculateArea();
};

#endif