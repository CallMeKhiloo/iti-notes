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

    Shape *shapes[] = {new Line(1 * SCALE, 4 * SCALE, 2 * SCALE, 7 * SCALE), new Rect(1 * SCALE, 2 * SCALE, 5 * SCALE, 8 * SCALE), new Circle(5 * SCALE, 5 * SCALE, 3 * SCALE)};

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
        for(int i = 0 ; i < 3; i++){
            shapes[i]->draw(renderer);
        }

        // Show everything
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    for (int i = 0 ; i < 3 ; i++) free(shapes[i]);
    return 0;
}
