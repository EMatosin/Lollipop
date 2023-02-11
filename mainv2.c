#include <SDL2/SDL.h>
#include "C:\Users\emato\OneDrive\Bureau\Lollipop\SDL2\include\SDL2\SDL_ttf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "C:\Users\emato\OneDrive\Bureau\Lollipop\SDL2\include\SDL2\window.h"
#include "C:\Users\emato\OneDrive\Bureau\Lollipop\SDL2\include\SDL2\squares.h"
//#include "C:\Users\emato\OneDrive\Bureau\Lollipop\SDL2\include\SDL2\game_started.h"
#include "C:\Users\emato\OneDrive\Bureau\Lollipop\SDL2\include\SDL2\randomizer.h"
#include "C:\Users\emato\OneDrive\Bureau\Lollipop\SDL2\include\SDL2\background.h"

// Stockage des images pour éviter des perturbations au niveau des clics

SDL_Surface *images[NUM_IMAGES];

int main(int argc, char *argv[]) {
    // Initialiser SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    // Initialiser la fenêtre
    Window *window = create_window();
	/* TTF INIT */
	TTF_Init();

    // Variables pour stocker l'état des carrés (s'ils sont retournés ou non)
    GameGrid grid;
    grid.width = GRID_WIDTH;
    grid.height = GRID_HEIGHT;
    init_grid(&grid);

    // Variables pour déclarer l'état du jeu (en cours ou gameover)

    int game_started = 0;
    //int game_over = 0;

    // Initilisation des différentes sections
    background(window);
    draw_squares(window, &grid, image_files[4]);

    // Affichage du menu BET
    TTF_Font * font = TTF_OpenFont("PurpleSmile.ttf", 55);
	SDL_Color blackcolor = {0, 0, 0};
	SDL_Surface * betbtnsurf = TTF_RenderText_Blended(font, "BET", blackcolor);
	int texW = 0;
	int texH = 0;
	SDL_Texture * betbtntext = SDL_CreateTextureFromSurface(window->renderer, betbtnsurf);
	SDL_QueryTexture(betbtntext, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {WIDTH/2-WIDTH/10,HEIGHT/2+HEIGHT/4+HEIGHT/12, texW, texH};
	SDL_RenderCopy(window->renderer, betbtntext, NULL, &dstrect);
	SDL_RenderPresent(window->renderer);
            
    randomizer();

    // Boucle principale pour gérer les événements
    int running = 1;
    while (running) {
        SDL_Event event;
        int x;
        int y;
        while (SDL_PollEvent(&event)) {
            switch(event.type){
                case SDL_QUIT: // Gérer les événements de fermeture de fenêtre
                    running=0;
                    break;
                case SDL_MOUSEBUTTONDOWN: // Gérer les événements de clic de souris

                    // Récupérer les coordonnées du clic
                    x = event.button.x;
                    y = event.button.y;

                    // Vérifier si le clic a eu lieu sur le bouton BET
                    if (x >= bet_button.x && x <= bet_button.x + bet_button.w && y >= bet_button.y && y <= bet_button.y + bet_button.h) {
                        // Affichage du menu CASHOUT
                        SDL_SetRenderDrawColor(window->renderer, 200, 0, 0, 255);
                        SDL_RenderFillRect(window->renderer, &bet_button);
                        TTF_Font * font = TTF_OpenFont("PurpleSmile.ttf", 55);
                        SDL_Color whitecolor = {255, 255, 255};
                        SDL_Surface * betbtnsurf = TTF_RenderText_Blended(font, "CASH OUT", whitecolor);
                        SDL_Texture * betbtntext = SDL_CreateTextureFromSurface(window->renderer, betbtnsurf);
                        SDL_QueryTexture(betbtntext, NULL, NULL, &texW, &texH);
                        SDL_Rect dstrect = {WIDTH/2-WIDTH/10,HEIGHT/2+HEIGHT/4+HEIGHT/12, texW, texH};
                        SDL_RenderCopy(window->renderer, betbtntext, NULL, &dstrect);
                        SDL_RenderPresent(window->renderer);  
                        game_started=1;

                    }                  

                    //event_started(window);

                    // Vérifier si le clic a eu lieu dans l'un des carrés
                    if (game_started) {
                        int stop = check_square_click(window, &grid, x, y);
                        if(stop) {
                            game_started = 0;
                            reveal_all(window, &grid);
                        }
                    }
            }
        }
    // Afficher l'écran
    SDL_RenderPresent(window->renderer);
    
    }

    // Nettoyer les ressources utilisées
    destroy_window(window);
    SDL_Quit();

    // Libere la grille
    free_grid(&grid);

    return 0;
}
