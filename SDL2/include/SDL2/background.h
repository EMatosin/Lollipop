#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "C:\Users\emato\OneDrive\Bureau\Lollipop\SDL2\include\SDL2\window.h"
#include "C:\Users\emato\OneDrive\Bureau\Lollipop\SDL2\include\SDL2\squares.h"

// Initilisation des différentes sections

/*backgrounds*/

SDL_Rect window_bg = {0, 0, WIDTH, HEIGHT};
SDL_Rect lollypop_bg = {WIDTH/10,HEIGHT/11,WIDTH/1.4, HEIGHT/1.6};
SDL_Rect gain_bg = {WIDTH/2, HEIGHT/50, SQUARE_SIZE*4,SQUARE_SIZE};
SDL_Rect nblolly_bg = {WIDTH/2, 2*HEIGHT/3+HEIGHT/16, SQUARE_SIZE*5.5, SQUARE_SIZE*1.5};
SDL_Rect nbbet_bg = {WIDTH/10, 2*HEIGHT/3+HEIGHT/16, SQUARE_SIZE*5.5, SQUARE_SIZE*1.5};
SDL_Rect bet_button = {WIDTH/10,HEIGHT/2+HEIGHT/4+HEIGHT/12,WIDTH/1.4, HEIGHT/10};

void background(Window *window){

    /*background window*/
    SDL_SetRenderDrawColor(window->renderer, 135, 76, 98, 255);
    SDL_RenderFillRect(window->renderer, &window_bg);

    /*background lollypop*/
    SDL_SetRenderDrawColor(window->renderer, 196, 50, 145, 255);
    SDL_RenderFillRect(window->renderer, &lollypop_bg);

    /*background gain*/
    SDL_SetRenderDrawColor(window->renderer, 196, 50, 145, 255);
    SDL_RenderFillRect(window->renderer, &gain_bg);

    /*background nblolly*/
    SDL_SetRenderDrawColor(window->renderer, 196, 50, 145, 255);
    SDL_RenderFillRect(window->renderer, &nblolly_bg);

    /*background nbbet*/
    SDL_SetRenderDrawColor(window->renderer, 196, 50, 145, 255);
    SDL_RenderFillRect(window->renderer, &nbbet_bg);

    /*bet button*/
    SDL_SetRenderDrawColor(window->renderer, 161, 241, 42, 255);
    SDL_RenderFillRect(window->renderer, &bet_button);

}

#endif