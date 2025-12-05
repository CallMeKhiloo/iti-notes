#ifndef __PICTURE__
#define __PICTURE__

#include <SDL2/SDL.h>
#include "Line.h"
#include "Rect.h"
#include "Circle.h"

class Picture
{
private:
    int line_size, rect_size, circle_size;
    Line *line_ptr;
    Rect *rect_ptr;
    Circle *circle_ptr;

public:
    Picture(int ls, int rs, int cs, Line *l, Rect *r, Circle *c);

    void setLines(int size, Line *l);
    void setRects(int size, Rect *r);
    void setCircles(int size, Circle *c);

    void draw(SDL_Renderer* renderer);
};

#endif