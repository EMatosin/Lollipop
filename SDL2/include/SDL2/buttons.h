#ifndef BUTTONS_H
#define BUTTONS_H

#include "squares.h"

void draw_account(Window* window, float cash);

float draw_odds(Window* window, int stick, int lollipop_found);

void draw_sticks(Window* window, int stick);

void draw_chips(Window* window, int mise);

void draw_bet(Window* window, SDL_Rect* bet_button);

void draw_cash_out(Window* window, SDL_Rect* bet_button);

void draw_increase(Window* window, SDL_Rect* increase_button);

void draw_decrease(Window* window, SDL_Rect* decrease_button);

void draw_higher(Window* window, SDL_Rect* higher_bet);

void draw_lower(Window* window, SDL_Rect* lower_bet);

int check_bet_button_click(Window* window, SDL_Rect* bet_button, int x_click, int y_click);

int check_increase_button_click(Window* window, SDL_Rect* increase_button, int x_click, int y_click, int nb_sticks);

int check_decrease_button_click(Window* window, SDL_Rect* decrease_button, int x_click, int y_click, int nb_sticks);

int check_higher_bet_click(Window* window, SDL_Rect* higher_bet, int x_click, int y_click, int compteur_mise);

int check_lower_bet_click(Window* window, SDL_Rect* lower_bet, int x_click, int y_click, int compteur_mise);

#endif