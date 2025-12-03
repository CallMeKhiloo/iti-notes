#include "Line.h"
#include "terminal_utils.h"

Line::Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {}

point Line::getStart() const
{
    return this->start;
}

point Line::getEnd() const
{
    return this->end;
}

void Line::setStart(int x1, int y1)
{
    this->start = point(x1, y1);
}

void Line::setEnd(int x2, int y2)
{
    this->end = point(x2, y2);
}

void Line::draw(SDL_Renderer *rendererPtr) const
{
    SDL_Renderer *renderer = static_cast<SDL_Renderer *>(rendererPtr);

    int x1 = start.getStart();
    int y1 = start.getEnd();
    int x2 = end.getStart();
    int y2 = end.getEnd();

    // Bresenham's line algorithm
    int dx = std::abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -std::abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy;

    while (true)
    {
        SDL_RenderDrawPoint(renderer, x1, y1);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}