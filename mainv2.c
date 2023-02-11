#include <SDL2/SDL.h>
#include "SDL2/include/SDL2/SDL_ttf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "SDL2/include/SDL2/window.h"
#include "SDL2/include/SDL2/squares.h"
#include "SDL2/include/SDL2/bet.h"
//#include "C:\Users\emato\OneDrive\Bureau\Lollipop\SDL2\include\SDL2\game_started.h"
#include "SDL2/include/SDL2/background.h"

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

    int nb_sticks = 12;
    int game_started = 0;
    //int game_over = 0;

    // Initilisation des différentes sections
    GameButtons buttons;
    create_layout(window, &buttons);
    draw_squares(window, &grid, image_files[4]);
    draw_bet(window, &buttons.bet_button);
    randomizer(&grid, nb_sticks);

    // Boucle principale pour gérer les événements
    int running = 1;
    while (running) {
        SDL_Event event;
        int x;
        int y;
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT: // Gérer les événements de fermeture de fenêtre
                    running=0;
                    break;
                case SDL_MOUSEBUTTONDOWN: // Gérer les événements de clic de souris

                    // Récupérer les coordonnées du clic
                    x = event.button.x;
                    y = event.button.y;

                    // Vérifier si le clic a eu lieu sur le bouton BET
                    if (check_bet_button_click(window, &buttons.bet_button, x, y)) {
                        if (game_started) {
                            finish_game_layout(window, &buttons, &grid);
                            game_started = 0;
                        } else {
                            restart_game_layout(window, &buttons, &grid, nb_sticks);

                            game_started = 1;
                        }
                    }
                                 

                    //event_started(window);

                    // Vérifier si le clic a eu lieu dans l'un des carrés
                    if (game_started) {
                        int stop = check_square_click(window, &grid, x, y);
                        if(stop) {
                            finish_game_layout(window, &buttons, &grid);
                            game_started = 0;
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
