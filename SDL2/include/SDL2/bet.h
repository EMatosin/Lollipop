#ifndef BET_H
#define BET_H

#include "SDL_ttf.h"
#include "window.h"

int nb_sticks = 0;

char *chiffres[NUM_LOLLIPOP] = {"1","2","3","4","5","6","7","8","9","10","11","12","13"
,"14","15","16","17","18","19","20","21","22","23","24","25"};

int compteur_mise = 0;

char *chips[32]={"1","2","3","4","5","6","7","8","9","10","15","20","25"
,"30","40","50","60","70","80","90","100","150","200","250","300","400","500","600","700","800","900","1000"};

void draw_sticks(Window* window, int stick) {
    // Affichage du nombre de sticks
    SDL_Rect select_stick = {window->width/10+SQUARE_SIZE, 2.95*window->height/4, 1.8*SQUARE_SIZE, SQUARE_SIZE};
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, &select_stick);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", 100);
	SDL_Color pink = {229, 138, 189};
	SDL_Surface* sticks_surf = TTF_RenderText_Blended(font, chiffres[stick], pink);
	int texW = 0;
	int texH = 0;
	SDL_Texture* sticks_txt = SDL_CreateTextureFromSurface(window->renderer, sticks_surf);
	SDL_QueryTexture(sticks_txt, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {window->width/10 + 1.65*SQUARE_SIZE,2.88*window->height/4, texW, texH};
	SDL_RenderCopy(window->renderer, sticks_txt, NULL, &dstrect);
	SDL_RenderPresent(window->renderer);

}

void draw_chips(Window* window, int mise) {
    // Affichage du nombre de sticks
    SDL_Rect select_chips = {window->width/2+3*SQUARE_SIZE, 2.95*window->height/4, 2.5*SQUARE_SIZE, SQUARE_SIZE};
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, &select_chips);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", 75);
	SDL_Color pink = {229, 138, 189};
	SDL_Surface* sticks_surf = TTF_RenderText_Blended(font, chips[mise], pink);
	int texW = 0;
	int texH = 0;
	SDL_Texture* sticks_txt = SDL_CreateTextureFromSurface(window->renderer, sticks_surf);
	SDL_QueryTexture(sticks_txt, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {window->width/2+3.5*SQUARE_SIZE, 2.93*window->height/4, texW, texH};
	SDL_RenderCopy(window->renderer, sticks_txt, NULL, &dstrect);
	SDL_RenderPresent(window->renderer);

}

void draw_bet(Window* window, SDL_Rect* bet_button) {
    // Affichage du menu BET
    SDL_SetRenderDrawColor(window->renderer, 229, 138, 189, 255);
    SDL_RenderFillRect(window->renderer, bet_button);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", 55);
	SDL_Color white = {255, 255, 255};
	SDL_Surface* bet_surf = TTF_RenderText_Blended(font, "BET", white);
	int texW = 0;
	int texH = 0;
	SDL_Texture* bet_txt = SDL_CreateTextureFromSurface(window->renderer, bet_surf);
	SDL_QueryTexture(bet_txt, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {2.1*window->width/5,5.1*window->height/6, texW, texH};
	SDL_RenderCopy(window->renderer, bet_txt, NULL, &dstrect);
	SDL_RenderPresent(window->renderer);
}

void draw_cash_out(Window* window, SDL_Rect* bet_button) {
    // Affichage du menu CASHOUT
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, bet_button);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", 55);
    SDL_Color pink = {229, 138, 189};
    SDL_Surface* cash_surf = TTF_RenderText_Blended(font, "CASH OUT", pink);
    int texW = 0;
	int texH = 0;
    SDL_Texture * cash_txt = SDL_CreateTextureFromSurface(window->renderer, cash_surf);
    SDL_QueryTexture(cash_txt, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {2*window->width/5,5.1*window->height/6, texW, texH};
    SDL_RenderCopy(window->renderer, cash_txt, NULL, &dstrect);
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

void draw_higher(Window* window, SDL_Rect* higher_bet) {
    // Affichage du menu BET
    SDL_Surface* picture = SDL_LoadBMP("images/plus.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
    SDL_RenderCopy(window->renderer, texture, NULL, higher_bet);
    SDL_RenderPresent(window->renderer);
}

void draw_lower(Window* window, SDL_Rect* lower_bet) {
    // Affichage du menu BET
    SDL_Surface* picture = SDL_LoadBMP("images/minus.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
    SDL_RenderCopy(window->renderer, texture, NULL, lower_bet);
    SDL_RenderPresent(window->renderer);
}


int check_bet_button_click(Window* window, SDL_Rect* bet_button, int x_click, int y_click) {
    if (x_click >= bet_button->x && x_click <= bet_button->x + bet_button->w &&
        y_click >= bet_button->y && y_click <= bet_button->y + bet_button->h) {
        return 1;
    }

    return 0;
}

int check_increase_button_click(Window* window, SDL_Rect* increase_button, int x_click, int y_click, int nb_sticks) {
    if (x_click >= increase_button->x && x_click <= increase_button->x + increase_button->w &&
        y_click >= increase_button->y && y_click <= increase_button->y + increase_button->h &&
        nb_sticks<24) {
        return 1;
    }

    return 0;
}

int check_decrease_button_click(Window* window, SDL_Rect* decrease_button, int x_click, int y_click, int nb_sticks) {
    if (x_click >= decrease_button->x && x_click <= decrease_button->x + decrease_button->w &&
        y_click >= decrease_button->y && y_click <= decrease_button->y + decrease_button->h &&
        nb_sticks>0) {
        return 1;
        
    } 
    return 0;
}

int check_higher_bet_click(Window* window, SDL_Rect* higher_bet, int x_click, int y_click, int compteur_mise) {
    if (x_click >= higher_bet->x && x_click <= higher_bet->x + higher_bet->w &&
        y_click >= higher_bet->y && y_click <= higher_bet->y + higher_bet->h &&
        compteur_mise<31) {
        return 1;
    }

    return 0;
}

int check_lower_bet_click(Window* window, SDL_Rect* lower_bet, int x_click, int y_click, int compteur_mise) {
    if (x_click >= lower_bet->x && x_click <= lower_bet->x + lower_bet->w &&
        y_click >= lower_bet->y && y_click <= lower_bet->y + lower_bet->h &&
        compteur_mise>0) {
        return 1;   
    } 
    return 0;
}

#endif