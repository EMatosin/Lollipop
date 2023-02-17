#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

typedef struct
{
    SDL_Window *sdl_window;
    SDL_Renderer *renderer;
    int width;
    int height;
    int square;
} Window;

Window *create_window();

void destroy_window(Window *window);

#endif