#include "point.h"
#include "terminal_utils.h"

point::point(int a, int b) : start(a), end(b) {}

int point::getStart() const
{
    return this->start;
}

int point::getEnd() const
{
    return this->end;
}

void point::setStart(int a)
{
    this->start = a;
}

void point::setEnd(int b)
{
    this->end = b;
}

void point::draw(SDL_Renderer *rendererPtr) const
{
    SDL_Renderer *renderer = static_cast<SDL_Renderer *>(rendererPtr);
    SDL_RenderDrawPoint(renderer, start, end);
}