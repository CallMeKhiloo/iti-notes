#ifndef __CIRCLE__
#define __CIRCLE__

#include <SDL2/SDL.h>
#include "point.h"
#include "Shape.h"

class Circle : public Shape
{
private:
    point origin;
    int radius;

public:
    Circle(int a, int b, int r);

    point getOrigin() const;
    int getRadius() const;

    void setOrigin(int a, int b);
    void draw(SDL_Renderer* renderer) const override;
};

#endif