#include "SDL2\include\SDL2\background.h"
#include "SDL2\include\SDL2\buttons.h"
#include "SDL2\include\SDL2\SDL_ttf.h"

void create_layout(Window *window, GameButtons* buttons, int nb_broccolis, int mise, float cash, int lollipop_found){
    /*layout window*/
    SDL_Rect window_bg = {0, 0, window->width, window->height};
    SDL_Surface* picture = SDL_LoadBMP("images/lollipop_background.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
    SDL_RenderCopy(window->renderer, texture, NULL, &window_bg);
    SDL_RenderPresent(window->renderer);

    /*layout lose icon*/
    SDL_Rect lose_layout = {window->width/10 + 4*window->square, 2.95*window->height/4, window->square, window->square};
    SDL_Surface* picture_lose = SDL_LoadBMP("images/lose.bmp");
    SDL_Texture* texture_lose = SDL_CreateTextureFromSurface(window->renderer, picture_lose);
    SDL_RenderCopy(window->renderer, texture_lose, NULL, &lose_layout);
    SDL_RenderPresent(window->renderer);

    /*layout squares*/
    SDL_Rect squares_layout = {window->width/10,window->height/11,window->width/1.4, window->height/1.6};
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, &squares_layout);

    /*current bank characters*/
    SDL_Rect bank_layout = {window->width/3, window->height/50, window->square*6,window->square/1.5};
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, &bank_layout);
    TTF_Font* font = TTF_OpenFont("PurpleSmile.ttf", window->square/2);
	SDL_Color pink = {229, 138, 189};
	SDL_Surface* bank = TTF_RenderText_Blended(font, "Bank :", pink);
    SDL_Surface* usd = TTF_RenderText_Blended(font, "USD", pink);
	int texW = 0;
	int texH = 0;
    int texW2 = 0;
	int texH2 = 0;
	SDL_Texture* bank_txt = SDL_CreateTextureFromSurface(window->renderer, bank);
    SDL_Texture* usd_txt = SDL_CreateTextureFromSurface(window->renderer, usd);
	SDL_QueryTexture(bank_txt, NULL, NULL, &texW, &texH);
    SDL_QueryTexture(usd_txt, NULL, NULL, &texW2, &texH2);
	SDL_Rect dstrect = {1.7*window->width/5,window->height/70, texW, texH};
    SDL_Rect dstrect2 = {2.6*window->width/5,window->height/70, texW2, texH2};
	SDL_RenderCopy(window->renderer, bank_txt, NULL, &dstrect);
    SDL_RenderCopy(window->renderer, usd_txt, NULL, &dstrect2);
	SDL_RenderPresent(window->renderer);

    /*layout bet put*/
    SDL_Rect bet_layout = {window->width/2, 2.95*window->height/4, window->square*8, window->square};
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, &bet_layout);

    /*current bet characters*/
	SDL_Surface* bet = TTF_RenderText_Blended(font, "Bet :", pink);
	int texW3 = 0;
	int texH3 = 0;
    int texW4 = 0;
	int texH4 = 0;
	SDL_Texture* bet_txt = SDL_CreateTextureFromSurface(window->renderer, bet);
	SDL_QueryTexture(bet_txt, NULL, NULL, &texW3, &texH3);
    SDL_QueryTexture(usd_txt, NULL, NULL, &texW4, &texH4);
	SDL_Rect dstrect3 = {window->width/2+1.4*window->square,2.98*window->height/4, texW3, texH3};
    SDL_Rect dstrect4 = {window->width/2+5.8*window->square,2.98*window->height/4, texW4, texH4};
	SDL_RenderCopy(window->renderer, bet_txt, NULL, &dstrect3);
    SDL_RenderCopy(window->renderer, usd_txt, NULL, &dstrect4);
	SDL_RenderPresent(window->renderer);

    /*layout increase/decrease menu*/
    SDL_Rect select_layout = {window->width/10, 2.95*window->height/4, window->square*3.8, window->square};
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, &select_layout);

    /*layout odds*/
    SDL_Rect odds_layout = {window->width/10 + 6*window->square, 2.95*window->height/4, window->square*3.8, window->square};
    SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(window->renderer, &odds_layout);

    /*current odds characters*/
	SDL_Surface* odds = TTF_RenderText_Blended(font, "Odds : X", pink);
	int texW5 = 0;
	int texH5 = 0;
	SDL_Texture* odds_txt = SDL_CreateTextureFromSurface(window->renderer, odds);
	SDL_QueryTexture(odds_txt, NULL, NULL, &texW5, &texH5);
	SDL_Rect dstrect5 = {window->width/10 + 6.1*window->square, 2.98*window->height/4, texW5, texH5};
	SDL_RenderCopy(window->renderer, odds_txt, NULL, &dstrect5);
	SDL_RenderPresent(window->renderer);

    /*affichage des menus avec chiffres variables*/
    draw_account(window, cash);
    draw_broccolis(window, nb_broccolis);
    draw_chips(window, mise);
    draw_odds(window,nb_broccolis, lollipop_found);

    /*bet button*/
    buttons->bet_button.x = window->width/10;
    buttons->bet_button.y = 4.9*window->height/6;
    buttons->bet_button.w = window->width/1.4;
    buttons->bet_button.h = window->height/15;
    draw_bet(window, &buttons->bet_button);

    /*increase broccoli button*/
    buttons->increase_button.x = window->width/10;
    buttons->increase_button.y = 2.95*window->height/4;
    buttons->increase_button.w = window->square;
    buttons->increase_button.h = window->square;
    draw_increase(window, &buttons->increase_button);

    /*decrease broccoli button*/
    buttons->decrease_button.x = window->width/10+2.8*window->square;
    buttons->decrease_button.y = 2.95*window->height/4;
    buttons->decrease_button.w = window->square;
    buttons->decrease_button.h = window->square;
    draw_decrease(window, &buttons->decrease_button);

    /*increase bet button*/
    buttons->higher_bet.x = window->width/2;
    buttons->higher_bet.y = 2.95*window->height/4;
    buttons->higher_bet.w = window->square;
    buttons->higher_bet.h = window->square;
    draw_higher(window, &buttons->higher_bet);

    /*decrease bet button*/
    buttons->lower_bet.x = window->width/2+7*window->square;
    buttons->lower_bet.y = 2.95*window->height/4;
    buttons->lower_bet.w = window->square;
    buttons->lower_bet.h = window->square;
    draw_lower(window, &buttons->lower_bet);
}

void restart_game_layout(Window *window, GameButtons* buttons, GameGrid* grid, int nb_broccolis) {
    draw_squares(window, grid, "images/start.bmp");
    draw_cash_out(window, &buttons->bet_button);
    randomizer(grid, nb_broccolis);
}

void finish_game_layout(Window *window, GameButtons* buttons, GameGrid* grid) {
    reveal_all(window, grid);
    draw_bet(window, &buttons->bet_button);
}