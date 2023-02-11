#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

#define WIDTH 1200
#define HEIGHT 1200

typedef struct
{
    SDL_Window *sdl_window;
    SDL_Renderer *renderer;
} Window;

Window *create_window();

void destroy_window(Window *window);

#endif