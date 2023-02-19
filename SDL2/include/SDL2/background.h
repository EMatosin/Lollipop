#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "window.h"
#include "squares.h"

typedef struct {
    SDL_Rect broccolis;   
    SDL_Rect bet_button;
    SDL_Rect increase_button;
    SDL_Rect decrease_button;
    SDL_Rect higher_bet;
    SDL_Rect lower_bet;
} GameButtons;

// Initilisation des différentes sections
void create_layout(Window *window, GameButtons* buttons, int nb_broccolis, int compteur_mise, float cash, int lollipop_found);

void restart_game_layout(Window *window, GameButtons* buttons, GameGrid* grid, int nb_broccolis);

void finish_game_layout(Window *window, GameButtons* buttons, GameGrid* grid);

#endif