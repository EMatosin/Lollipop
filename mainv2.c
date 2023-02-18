#include "SDL2/include/SDL2/window.h"
#include "SDL2/include/SDL2/squares.h"
#include "SDL2/include/SDL2/bet.h"
#include "SDL2/include/SDL2/background.h"
#include "SDL2/include/SDL2/SDL_ttf.h"
#include "SDL2/include/SDL2/history.h"

// Stockage des images pour éviter des perturbations au niveau des clics

SDL_Surface *images[NUM_IMAGES];

int main(int argc, char *argv[]) {
    // Initialiser SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    // Initialiser la fenêtre
    Window *window = create_window();
	/* TTF INIT */
	TTF_Init();

    // Stockage de l'état de la grille ( 25 carrés ) 
    GameGrid grid;
    grid.width = GRID_WIDTH;
    grid.height = GRID_HEIGHT;
    init_grid(&grid, window);

    // Variables pour déclarer l'état du jeu
    int game_started = 0;
    int nb_sticks = 1;
    int compteur_mise = 0;
    float odds;
    float cash = 100.0;
    int chiffres[]={1,2,3,4,5,6,7,8,9,10,15,20,25,30,40,50,60,70,80,90,100,150,200,250,300,400,500,600,700,800,900,1000};
    int* chips = chiffres;
    int lollipop_found = 0;
    GameHistory* head = NULL; // Initialisation de la liste chainée
    GameHistory* tail = NULL; // Initialisation de la liste chainée

    // Initilisation des différentes sections
    GameButtons buttons;
    create_layout(window, &buttons, nb_sticks, chips[compteur_mise], cash, lollipop_found);
    draw_squares(window, &grid, "images/start.bmp");
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
                            if (lollipop_found==0){
                                finish_game_layout(window, &buttons, &grid);
                                cash=cash+chips[compteur_mise];
                                draw_account(window, cash);
                                lollipop_found = 0;
                                game_started = 0;   
                            }
                            else{
                                finish_game_layout(window, &buttons, &grid);
                                cash=cash+chips[compteur_mise]*odds;
                                draw_account(window, cash);
                                update_history(&head, &tail, chips[compteur_mise], nb_sticks, cash);
                                lollipop_found = 0;
                                game_started = 0;   
                            }
                            
                        
                        } else {
                            cash=cash-chips[compteur_mise];
                            draw_account(window, cash);
                            restart_game_layout(window, &buttons, &grid, nb_sticks);
                            game_started = 1;
                        }
                    }  
                    // Vérifier si le clic a eu lieu sur le bouton + des broccolis
                    if (check_increase_button_click(window, &buttons.increase_button, x, y, nb_sticks)) {
                        if (!game_started) {
                            ++nb_sticks;
                            draw_sticks(window,nb_sticks);
                            draw_odds(window,nb_sticks,lollipop_found);
                        }
                    } 
                    // Vérifier si le clic a eu lieu sur le bouton - des broccolis
                    if (check_decrease_button_click(window, &buttons.decrease_button, x, y, nb_sticks)) {
                        if (!game_started) {
                            --nb_sticks;
                            draw_sticks(window,nb_sticks);
                            draw_odds(window,nb_sticks,lollipop_found);
                        }
                    }
                    // Vérifier si le clic a eu lieu sur le bouton + de la mise
                    if (check_higher_bet_click(window, &buttons.higher_bet, x, y, compteur_mise)) {
                        if (!game_started) {
                            ++compteur_mise;
                            draw_chips(window,chips[compteur_mise]);
                        }
                    } 
                    // Vérifier si le clic a eu lieu sur le bouton - de la mise
                    if (check_lower_bet_click(window, &buttons.lower_bet, x, y, compteur_mise)) {
                        if (!game_started) {
                            --compteur_mise;
                            draw_chips(window,chips[compteur_mise]);
                        }
                    }                         

                    // Vérifier si le clic a eu lieu dans l'un des carrés
                    if (game_started) {
                        int stop = check_square_click(window, &grid, x, y,lollipop_found,nb_sticks);
                        if (stop==CONTINUE) {
                            ++lollipop_found; 
                            odds = draw_odds(window,nb_sticks,lollipop_found);
                        }
                       
                        if (stop==STOP) {
                            finish_game_layout(window, &buttons, &grid);
                            lollipop_found = 0;
                            update_history(&head, &tail, chips[compteur_mise], nb_sticks, cash);
                            game_started = 0;
                        }
                    }
            }
        }

    // Afficher l'écran
    SDL_RenderPresent(window->renderer);
    }

    SaveGames(head, "Score.txt");

    // Nettoyer les ressources utilisées
    destroy_window(window);
    SDL_Quit();

    // Libere la grille
    free_grid(&grid);

    // Libere la liste chainee
    free_list(head);

    return 0;
}
