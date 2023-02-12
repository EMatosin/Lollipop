#ifndef BET_H
#define BET_H

#include "SDL_ttf.h"
#include "window.h"

char* chiffres = "1";
//chiffres = {'1','2','3','4'};

void draw_sticks(Window* window) {
    // Affichage du nombre de sticks
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", 100);
	SDL_Color pink = {229, 138, 189};
	SDL_Surface* betbtnsurf = TTF_RenderText_Blended(font, chiffres, pink);
	int texW = 0;
	int texH = 0;
	SDL_Texture* betbtntext = SDL_CreateTextureFromSurface(window->renderer, betbtnsurf);
	SDL_QueryTexture(betbtntext, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {window->width/10 + 1.8*SQUARE_SIZE,2.88*window->height/4, texW, texH};
	SDL_RenderCopy(window->renderer, betbtntext, NULL, &dstrect);
	SDL_RenderPresent(window->renderer);

}

void draw_bet(Window* window, SDL_Rect* bet_button) {
    // Affichage du menu BET
    SDL_SetRenderDrawColor(window->renderer, 229, 138, 189, 255);
    SDL_RenderFillRect(window->renderer, bet_button);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", 55);
	SDL_Color white = {255, 255, 255};
	SDL_Surface* betbtnsurf = TTF_RenderText_Blended(font, "BET", white);
	int texW = 0;
	int texH = 0;
	SDL_Texture* betbtntext = SDL_CreateTextureFromSurface(window->renderer, betbtnsurf);
	SDL_QueryTexture(betbtntext, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {2.1*window->width/5,5.1*window->height/6, texW, texH};
	SDL_RenderCopy(window->renderer, betbtntext, NULL, &dstrect);
	SDL_RenderPresent(window->renderer);
}

void draw_cash_out(Window* window, SDL_Rect* bet_button) {
    // Affichage du menu CASHOUT
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, bet_button);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", 55);
    SDL_Color pink = {229, 138, 189};
    SDL_Surface* betbtnsurf = TTF_RenderText_Blended(font, "CASH OUT", pink);
    int texW = 0;
	int texH = 0;
    SDL_Texture * betbtntext = SDL_CreateTextureFromSurface(window->renderer, betbtnsurf);
    SDL_QueryTexture(betbtntext, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {2*window->width/5,5.1*window->height/6, texW, texH};
    SDL_RenderCopy(window->renderer, betbtntext, NULL, &dstrect);
    SDL_RenderPresent(window->renderer);  
}

void draw_increase(Window* window, SDL_Rect* increase_button) {
    // Affichage du menu BET
    SDL_Surface* picture = SDL_LoadBMP("images/plus.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
    SDL_RenderCopy(window->renderer, texture, NULL, increase_button);
    SDL_RenderPresent(window->renderer);
}

void draw_decrease(Window* window, SDL_Rect* decrease_button) {
    // Affichage du menu BET
    SDL_Surface* picture = SDL_LoadBMP("images/minus.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
    SDL_RenderCopy(window->renderer, texture, NULL, decrease_button);
    SDL_RenderPresent(window->renderer);
}


int check_bet_button_click(Window* window, SDL_Rect* bet_button, int x_click, int y_click) {
    if (x_click >= bet_button->x && x_click <= bet_button->x + bet_button->w &&
        y_click >= bet_button->y && y_click <= bet_button->y + bet_button->h) {
        return 1;
    }

    return 0;
}

#endif