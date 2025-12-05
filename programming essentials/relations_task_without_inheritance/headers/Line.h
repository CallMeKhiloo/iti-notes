#ifndef LINE_H
#define LINE_H

#include <SDL2/SDL.h>
#include "point.h"

class Line
{
private:
    point start, end;

public:
    Line(int x1, int y1, int x2, int y2);

    point getStart() const;
    point getEnd() const;

    void setStart(int a, int b);
    void setEnd(int a, int b);
    void draw(SDL_Renderer* renderer) const;
};

#endif