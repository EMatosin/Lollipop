#include "SDL2/include/SDL2/window.h"
#include "SDL2/include/SDL2/squares.h"
#include "SDL2/include/SDL2/buttons.h"
#include "SDL2/include/SDL2/background.h"
#include "SDL2/include/SDL2/SDL_ttf.h"
#include "SDL2/include/SDL2/SDL_image.h"
#include "SDL2/include/SDL2/history.h"

int main(int argc, char *argv[]) {
    // Initialiser SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    // Initialiser SDL_IMAGE
    // IMG_Init(IMG_INIT_JPG);
    // Initialiser la fenêtre
    Window *window = create_window();
	// Initialiser SDL_TTF
    TTF_Init();

    // Stockage de l'état de la grille ( 25 carrés ) 
    GameGrid grid;
    grid.width = GRID_WIDTH;
    grid.height = GRID_HEIGHT;
    init_grid(&grid, window);

    // Variables pour déclarer l'état du jeu
    int game_started = 0; // qui permet de bloquer le clic sur les carrés notamment
    int nb_broccolis = 1; // nombre initial de brocolis
    int compteur_mise = 0; // compteur qui va servir pour le tableau de chiffres
    float odds; // initialisation du multiplicateur
    float cash = 100.0; // somme initial en banque
    int chiffres[]={1,2,3,4,5,6,7,8,9,10,15,20,25,30,40,50,60,70,80,90,100,150,200,250,300,400,500,600,700,800,900,1000}; // toutes les mises différentes
    int* chips = chiffres; // pour stocker les chiffres ci dessus
    int lollipop_found = 0; // variables qui va servir pour le calcul du multiplicateur
    GameHistory* head = NULL; // Initialisation de la tête de la liste chainée
    GameHistory* tail = NULL; // Initialisation de la queue de la liste chainée

    // Initilisation des différentes sections
    GameButtons buttons;
    create_layout(window, &buttons, nb_broccolis, chips[compteur_mise], cash, lollipop_found);
    draw_squares(window, &grid, "images/start.bmp");
    randomizer(&grid, nb_broccolis);

    // Boucle principale pour gérer les événements
    int running = 1;
    while (running) {
        SDL_Event event;
        int x; // initialisation des coordonnées du clic en x
        int y; // initialisation des coordonnées du clic en y
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT: // Gérer les événements de fermeture de fenêtre
                    running=0;
                    break;
                case SDL_MOUSEBUTTONDOWN: // Gérer les événements de clic de souris
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
                                update_history(&head, &tail, chips[compteur_mise], nb_broccolis, odds, cash);
                                lollipop_found = 0;
                                odds = draw_odds(window,nb_broccolis,lollipop_found);
                                game_started = 0;

                            }
                        
                        } else if (chiffres[compteur_mise]<=cash) {
                            cash=cash-chips[compteur_mise];
                            draw_account(window, cash);
                            restart_game_layout(window, &buttons, &grid, nb_broccolis);
                            game_started = 1;
                        }
                    }  
                    // Vérifier si le clic a eu lieu sur le bouton + des broccolis
                    if (check_increase_button_click(window, &buttons.increase_button, x, y, nb_broccolis)) {
                        if (!game_started) {
                            ++nb_broccolis;
                            draw_broccolis(window,nb_broccolis);
                            draw_odds(window,nb_broccolis,lollipop_found);
                        }
                    } 
                    // Vérifier si le clic a eu lieu sur le bouton - des broccolis
                    if (check_decrease_button_click(window, &buttons.decrease_button, x, y, nb_broccolis)) {
                        if (!game_started) {
                            --nb_broccolis;
                            draw_broccolis(window,nb_broccolis);
                            draw_odds(window,nb_broccolis,lollipop_found);
                        }
                    }
                    // Vérifier si le clic a eu lieu sur le bouton + de la mise
                    if (check_higher_bet_click(window, &buttons.higher_bet, x, y, compteur_mise)) {
                        if (!game_started && chiffres[compteur_mise+1]<=cash) {
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
                        int stop = check_square_click(window, &grid, x, y,lollipop_found,nb_broccolis);
                        if (stop==CONTINUE) {
                            ++lollipop_found; 
                            odds = draw_odds(window,nb_broccolis,lollipop_found);
                        }
                       
                        if (stop==STOP) {
                            finish_game_layout(window, &buttons, &grid);
                            lollipop_found = 0;
                            update_history(&head, &tail, chips[compteur_mise], nb_broccolis, odds, cash);
                            odds = draw_odds(window,nb_broccolis,lollipop_found);
                            game_started = 0;
                        }
                    }
            }
        }

    // Afficher l'écran
    SDL_RenderPresent(window->renderer);
    }

    // Sauvegarde des différentes stats de la partie dans Score.txt
    SaveGames(head, "Scores.txt");

    // Nettoyer les ressources utilisées
    destroy_window(window);
    SDL_Quit();

    // Libere la grille
    free_grid(&grid);

    // Libere la liste chainee
    free_list(head);

    return 0;
}
