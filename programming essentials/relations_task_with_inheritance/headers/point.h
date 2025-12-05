#ifndef __POINT__
#define __POINT__

#include <SDL2/SDL.h>
#include "Shape.h"

class point : public Shape
{
private:
    int start, end;

public:
    point(int a, int b);

    int getStart() const;
    int getEnd() const;

    void setStart(int a);
    void setEnd(int b);
    void draw(SDL_Renderer* renderer) const override;
};

#endif