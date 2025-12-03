#include "main.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "SDL Shapes",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    SDL_Event event;

    // Scale factor to make small coordinates visible
    const int SCALE = 20;

    // Original coordinates multiplied for reasonable visibility
    Line lines[3] = {
        Line(2 * SCALE, 4 * SCALE, 10 * SCALE, 20 * SCALE),
        Line(1 * SCALE, 3 * SCALE, 5 * SCALE, 2 * SCALE),
        Line(1 * SCALE, 5 * SCALE, 2 * SCALE, 20 * SCALE)};

    Rect rectangles[1] = {Rect(0 * SCALE, 3 * SCALE, 5 * SCALE, 10 * SCALE)};

    Circle circles[1] = {Circle(10 * SCALE, 10 * SCALE, 20 * SCALE)};

    Picture pic(3, 1, 1, lines, rectangles, circles);

    while (running)
    {
        // Event loop
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        // Clear screen (black)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw shapes (white)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        pic.draw(renderer);

        // Show everything
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
