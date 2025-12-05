#include "Rect.h"
#include "terminal_utils.h"

Rect::Rect(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {}

point Rect::getStart() const
{
    return this->start;
}

point Rect::getEnd() const
{
    return this->end;
}

void Rect::setStart(int x1, int y1)
{
    this->start = point(x1, y1);
}

void Rect::setEnd(int x2, int y2)
{
    this->end = point(x2, y2);
}

void Rect::draw(SDL_Renderer* rendererPtr) const
{
    SDL_Rect r;

    r.x = start.getStart();
    r.y = start.getEnd();
    r.w = end.getStart() - start.getStart();
    r.h = end.getEnd() - start.getEnd();

    SDL_RenderDrawRect(rendererPtr, &r);
}