#ifndef RECT_H
#define RECT_H

#include <SDL2/SDL.h>
#include "point.h"

class Rect
{
private:
    point start, end;

public:
    Rect(int x1, int y1, int x2, int y2);

    point getStart() const;
    point getEnd() const;

    void setStart(int a, int b);
    void setEnd(int a, int b);
    void draw(SDL_Renderer* renderer) const;
};

#endif