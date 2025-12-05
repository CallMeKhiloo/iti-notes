#include "Circle.h"
#include "terminal_utils.h"

Circle::Circle(int a, int b, int r) : origin(a, b) {
    this->radius = r;
}

point Circle::getOrigin() const
{
    return this->origin;
}
void Circle::setOrigin(int a, int b)
{
    this->origin = point(a, b);
}

void Circle::draw(SDL_Renderer* renderer) const
{
    int x = radius;
    int y = 0;
    int d = 1 - radius;

    while (x >= y)
    {
        // 8-way symmetry
        SDL_RenderDrawPoint(renderer, origin.getStart() + x, origin.getEnd() + y);
        SDL_RenderDrawPoint(renderer, origin.getStart() + y, origin.getEnd() + x);
        SDL_RenderDrawPoint(renderer, origin.getStart() - y, origin.getEnd() + x);
        SDL_RenderDrawPoint(renderer, origin.getStart() - x, origin.getEnd() + y);
        SDL_RenderDrawPoint(renderer, origin.getStart() - x, origin.getEnd() - y);
        SDL_RenderDrawPoint(renderer, origin.getStart() - y, origin.getEnd() - x);
        SDL_RenderDrawPoint(renderer, origin.getStart() + y, origin.getEnd() - x);
        SDL_RenderDrawPoint(renderer, origin.getStart() + x, origin.getEnd() - y);

        y++;

        if (d <= 0)
        {
            d += 2 * y + 1;
        }
        else
        {
            x--;
            d += 2 * (y - x) + 1;
        }
    }
}