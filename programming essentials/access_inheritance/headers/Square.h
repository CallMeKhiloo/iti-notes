#ifndef __SQUARE__
#define __SQUARE__

#include "Rect.h"

class Square : private Rect
{
public:
    Square(float x);

    void setSquareDim(float x);
    float getSquareDim();
    float calculateArea();
};

#endif