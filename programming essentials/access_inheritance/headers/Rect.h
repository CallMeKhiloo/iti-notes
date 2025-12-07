#ifndef __RECT__
#define __RECT__

#include "Geoshape.h"

class Rect : public Geoshape
{
public:
    Rect(float x, float y);
    float calculateArea();
};

#endif