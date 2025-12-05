#ifndef __SHAPE__
#define __SHAPE__

#include <SDL2/SDL.h>

class Shape
{
public:
    virtual void draw(SDL_Renderer *renderer) const;
    virtual ~Shape();
};

#endif