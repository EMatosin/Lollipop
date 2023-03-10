#include <stdio.h>
#include <stdlib.h>
#include "SDL2/include/SDL2/SDL_ttf.h"
#include "SDL2/include/SDL2/SDL_image.h"
#include "SDL2/include/SDL2/window.h"
#include "SDL2/include/SDL2/buttons.h"

void draw_account(Window* window, float cash) {
    // Affichage de l'argent en banque
    SDL_Rect account = {window->width/3+2.3*window->square, window->height/50, 2.3*window->square, window->square/1.5};
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, &account);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", window->square/2);
	SDL_Color pink = {229, 138, 189};

    char buffer[3];
    sprintf(buffer,"%.2f",cash);

	SDL_Surface* account_surf = TTF_RenderText_Blended(font, buffer, pink);
	int texW = 0;
	int texH = 0;
	SDL_Texture* account_txt = SDL_CreateTextureFromSurface(window->renderer, account_surf);
	SDL_QueryTexture(account_txt, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {2.2*window->width/5, window->height/70, texW, texH};
	SDL_RenderCopy(window->renderer, account_txt, NULL, &dstrect);
	SDL_RenderPresent(window->renderer);

}

float draw_odds(Window* window, int stick, int lollipop_found) {
    // Affichage du multiplicateur
    
    SDL_Rect odds = {window->width/10 + 8.5*window->square,2.95*window->height/4, 1.3*window->square, window->square};
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, &odds);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", window->square/2);
	SDL_Color pink = {229, 138, 189};

    char buffer[3];
    float maths = 25.0/(25.0 - (float)stick - lollipop_found);
    sprintf(buffer,"%.2f",maths);

	SDL_Surface* odds_surf = TTF_RenderText_Blended(font, buffer, pink);
	int texW = 0;
	int texH = 0;
	SDL_Texture* odds_txt = SDL_CreateTextureFromSurface(window->renderer, odds_surf);
	SDL_QueryTexture(odds_txt, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {window->width/10 + 8.55*window->square, 2.98*window->height/4, texW, texH};
	SDL_RenderCopy(window->renderer, odds_txt, NULL, &dstrect);
	SDL_RenderPresent(window->renderer);

    return maths;

}

void draw_broccolis(Window* window, int stick) {
    // Affichage du nombre de broccolis
    SDL_Rect select_stick = {window->width/10+window->square, 2.95*window->height/4, 1.8*window->square, window->square};
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, &select_stick);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", window->square);
	SDL_Color pink = {229, 138, 189};

    char buffer[3];    
    sprintf(buffer,"%d", stick);
	SDL_Surface* broccolis_surf = TTF_RenderText_Blended(font, buffer, pink);

	int texW = 0;
	int texH = 0;
	SDL_Texture* broccolis_txt = SDL_CreateTextureFromSurface(window->renderer, broccolis_surf);
	SDL_QueryTexture(broccolis_txt, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {window->width/10 + 1.65*window->square,2.88*window->height/4, texW, texH};
	SDL_RenderCopy(window->renderer, broccolis_txt, NULL, &dstrect);
	SDL_RenderPresent(window->renderer);

}

void draw_chips(Window* window, int mise) {
    // Affichage du nombre de broccolis
    SDL_Rect select_chips = {window->width/2+3*window->square, 2.95*window->height/4, 2.5*window->square, window->square};
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, &select_chips);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", window->square);
	SDL_Color pink = {229, 138, 189};

    char buffer[5];
    sprintf(buffer,"%d", mise);
	SDL_Surface* broccolis_surf = TTF_RenderText_Blended(font, buffer, pink);

	int texW = 0;
	int texH = 0;
	SDL_Texture* broccolis_txt = SDL_CreateTextureFromSurface(window->renderer, broccolis_surf);
	SDL_QueryTexture(broccolis_txt, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {window->width/2+3.5*window->square, 2.85*window->height/4, texW, texH};
	SDL_RenderCopy(window->renderer, broccolis_txt, NULL, &dstrect);
	SDL_RenderPresent(window->renderer);

}

void draw_bet(Window* window, SDL_Rect* bet_button) {
    // Affichage du menu BET
    SDL_SetRenderDrawColor(window->renderer, 229, 138, 189, 255);
    SDL_RenderFillRect(window->renderer, bet_button);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", window->square/2);
	SDL_Color white = {255, 255, 255};
	SDL_Surface* bet_surf = TTF_RenderText_Blended(font, "BET", white);
	int texW = 0;
	int texH = 0;
	SDL_Texture* bet_txt = SDL_CreateTextureFromSurface(window->renderer, bet_surf);
	SDL_QueryTexture(bet_txt, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {2.1*window->width/5,4.95*window->height/6, texW, texH};
	SDL_RenderCopy(window->renderer, bet_txt, NULL, &dstrect);
	SDL_RenderPresent(window->renderer);
}

void draw_cash_out(Window* window, SDL_Rect* bet_button) {
    // Affichage du menu CASHOUT
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, bet_button);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", window->square/2);
    SDL_Color pink = {229, 138, 189};
    SDL_Surface* cash_surf = TTF_RenderText_Blended(font, "CASH OUT", pink);
    int texW = 0;
	int texH = 0;
    SDL_Texture * cash_txt = SDL_CreateTextureFromSurface(window->renderer, cash_surf);
    SDL_QueryTexture(cash_txt, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {2*window->width/5,4.95*window->height/6, texW, texH};
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

int check_increase_button_click(Window* window, SDL_Rect* increase_button, int x_click, int y_click, int nb_broccolis) {
    if (x_click >= increase_button->x && x_click <= increase_button->x + increase_button->w &&
        y_click >= increase_button->y && y_click <= increase_button->y + increase_button->h &&
        nb_broccolis < NUM_LOLLIPOP-1) {
        return 1;
    }

    return 0;
}

int check_decrease_button_click(Window* window, SDL_Rect* decrease_button, int x_click, int y_click, int nb_broccolis) {
    if (x_click >= decrease_button->x && x_click <= decrease_button->x + decrease_button->w &&
        y_click >= decrease_button->y && y_click <= decrease_button->y + decrease_button->h &&
        nb_broccolis > 1) {
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
