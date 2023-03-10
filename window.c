#include "SDL2/include/SDL2/window.h"
#include <stdio.h>

Window *create_window() {
    Window *window = calloc(1, sizeof(Window));

    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int width = DM.w;
    int height = DM.h;
    int square = width/25;

    window->sdl_window = SDL_CreateWindow("Lollipop Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width-100, height-100, SDL_WINDOW_SHOWN);
    if (window->sdl_window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s", SDL_GetError());
        SDL_Quit();
        exit(-1);
    }

    window->renderer = SDL_CreateRenderer(window->sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (window->renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s", SDL_GetError());
        SDL_DestroyWindow(window->sdl_window);
        SDL_Quit();
        exit(-1);
    }
    window->width = width;
    window->height = height;
    window->square = square;
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderClear(window->renderer);
    SDL_RenderPresent(window->renderer);

    return window;
}

void destroy_window(Window *window) {
    SDL_DestroyRenderer(window->renderer);
    SDL_DestroyWindow(window->sdl_window);
}