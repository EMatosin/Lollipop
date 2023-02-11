#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "window.h"
#include "squares.h"
#include "bet.h"

typedef struct {
    SDL_Rect bet_button;
} GameButtons;

// Initilisation des différentes sections
void create_layout(Window *window, GameButtons* buttons){
    /*layout window*/
    SDL_Rect window_bg = {0, 0, WIDTH, HEIGHT};
    SDL_Surface* picture = SDL_LoadBMP("images/lollipop_background.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
    SDL_RenderCopy(window->renderer, texture, NULL, &window_bg);
    SDL_RenderPresent(window->renderer);
    // SDL_Rect window_bg = {0, 0, WIDTH, HEIGHT};
    // SDL_SetRenderDrawColor(window->renderer, 0, 0, 0, 255);
    // SDL_RenderFillRect(window->renderer, &window_bg);

    /*layout lollipop*/
    SDL_Rect lollipop_bg = {WIDTH/10,HEIGHT/11,WIDTH/1.4, HEIGHT/1.6};
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, &lollipop_bg);

    /*layout current cash*/
    SDL_Rect gain_bg = {WIDTH/3, HEIGHT/50, SQUARE_SIZE*3,SQUARE_SIZE/1.5};
    SDL_SetRenderDrawColor(window->renderer, 229, 138, 189, 255);
    SDL_RenderFillRect(window->renderer, &gain_bg);

    /*layout sticks put*/
    SDL_Rect nblolly_bg = {WIDTH/2, 2.95*HEIGHT/4, SQUARE_SIZE*3.8, SQUARE_SIZE};
    SDL_SetRenderDrawColor(window->renderer, 229, 138, 189, 255);
    SDL_RenderFillRect(window->renderer, &nblolly_bg);

    /*layout bet put*/
    SDL_Rect nbbet_bg = {WIDTH/10, 2.95*HEIGHT/4, SQUARE_SIZE*3.8, SQUARE_SIZE};
    SDL_SetRenderDrawColor(window->renderer, 229, 138, 189, 255);
    SDL_RenderFillRect(window->renderer, &nbbet_bg);

    /*bet button*/
    buttons->bet_button.x = WIDTH/10;
    buttons->bet_button.y = 5*HEIGHT/6;
    buttons->bet_button.w = WIDTH/1.4;
    buttons->bet_button.h = HEIGHT/10;
    draw_bet(window, &buttons->bet_button);
}

void restart_game_layout(Window *window, GameButtons* buttons, GameGrid* grid, int nb_sticks) {
    draw_squares(window, grid, image_files[4]);
    draw_cash_out(window, &buttons->bet_button);
    randomizer(grid, nb_sticks);
}

void finish_game_layout(Window *window, GameButtons* buttons, GameGrid* grid) {
    reveal_all(window, grid);
    draw_bet(window, &buttons->bet_button);
}

#endif