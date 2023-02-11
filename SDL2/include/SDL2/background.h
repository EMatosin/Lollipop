#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "window.h"
#include "squares.h"

typedef struct {
    SDL_Rect bet_button;
} GameButtons;

// Initilisation des différentes sections
void create_layout(Window *window, GameButtons* buttons){
    /*background window*/
    SDL_Rect window_bg = {0, 0, WIDTH, HEIGHT};
    SDL_SetRenderDrawColor(window->renderer, 135, 76, 98, 255);
    SDL_RenderFillRect(window->renderer, &window_bg);

    /*background lollipop*/
    SDL_Rect lollipop_bg = {WIDTH/10,HEIGHT/11,WIDTH/1.4, HEIGHT/1.6};
    SDL_SetRenderDrawColor(window->renderer, 196, 50, 145, 255);
    SDL_RenderFillRect(window->renderer, &lollipop_bg);

    /*background gain*/
    SDL_Rect gain_bg = {WIDTH/2, HEIGHT/50, SQUARE_SIZE*4,SQUARE_SIZE};
    SDL_SetRenderDrawColor(window->renderer, 196, 50, 145, 255);
    SDL_RenderFillRect(window->renderer, &gain_bg);

    /*background nblolly*/
    SDL_Rect nblolly_bg = {WIDTH/2, 2*HEIGHT/3+HEIGHT/16, SQUARE_SIZE*5.5, SQUARE_SIZE*1.5};
    SDL_SetRenderDrawColor(window->renderer, 196, 50, 145, 255);
    SDL_RenderFillRect(window->renderer, &nblolly_bg);

    /*background nbbet*/
    SDL_Rect nbbet_bg = {WIDTH/10, 2*HEIGHT/3+HEIGHT/16, SQUARE_SIZE*5.5, SQUARE_SIZE*1.5};
    SDL_SetRenderDrawColor(window->renderer, 196, 50, 145, 255);
    SDL_RenderFillRect(window->renderer, &nbbet_bg);

    /*bet button*/
    buttons->bet_button.x = WIDTH/10;
    buttons->bet_button.y = 5*HEIGHT/6;
    buttons->bet_button.w = WIDTH/1.4;
    buttons->bet_button.h = HEIGHT/10;
    SDL_SetRenderDrawColor(window->renderer, 161, 241, 42, 255);
    SDL_RenderFillRect(window->renderer, &buttons->bet_button);
}

#endif