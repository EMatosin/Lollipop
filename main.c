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

    int square[NUM_LOLLIPOP];
    for (i = 0; i < NUM_LOLLIPOP; i++){
        square[i]= 0;
    }

    // Variables pour déclarer l'état du jeu (en cours ou gameover)

    int game_started = 0;
    //int game_over = 0;

    // Initilisation des différentes sections
    background(window);
    squares(window);

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
                    if (x >= rect0.x && x <= rect0.x + SQUARE_SIZE && y >= rect0.y && y <= rect0.y + SQUARE_SIZE && square[0] == 0 && game_started==1) {
                        if(tab[0] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect0);
                            break;
                        } 
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect0);
                        }
                    square[0] = !square[0];
                    SDL_RenderPresent(window->renderer);
                    }
                    
                    if (x >= rect1.x && x <= rect1.x + SQUARE_SIZE && y >= rect1.y && y <= rect1.y + SQUARE_SIZE && square[1] == 0 && game_started==1) {
                        if(tab[1] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect1);
                            break;
                        } 
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect1);
                        }
                    square[1] = !square[1];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0 && game_started==1) {
                        if(tab[2] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect2);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect2);
                        }                
                    square[2] = !square[2];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect3.x && x <= rect3.x + SQUARE_SIZE && y >= rect3.y && y <= rect3.y + SQUARE_SIZE && square[3] == 0 && game_started==1) {
                        if(tab[3] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect3);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect3);
                        }                
                    square[3] = !square[3];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect4.x && x <= rect4.x + SQUARE_SIZE && y >= rect4.y && y <= rect4.y + SQUARE_SIZE && square[4] == 0 && game_started==1) {
                        if(tab[4] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect4);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect4);
                        }                
                    square[4] = !square[4];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect5.x && x <= rect5.x + SQUARE_SIZE && y >= rect5.y && y <= rect5.y + SQUARE_SIZE && square[5] == 0 && game_started==1) {
                        if(tab[5] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect5);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect5);
                        }                
                    square[5] = !square[5];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect6.x && x <= rect6.x + SQUARE_SIZE && y >= rect6.y && y <= rect6.y + SQUARE_SIZE && square[6] == 0 && game_started==1) {
                        if(tab[6] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect6);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect6);
                        }                
                    square[6] = !square[6];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect7.x && x <= rect7.x + SQUARE_SIZE && y >= rect7.y && y <= rect7.y + SQUARE_SIZE && square[7] == 0 && game_started==1) {
                        if(tab[7] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect7);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect7);
                        }                
                    square[7] = !square[7];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect8.x && x <= rect8.x + SQUARE_SIZE && y >= rect8.y && y <= rect8.y + SQUARE_SIZE && square[8] == 0 && game_started==1) {
                        if(tab[8] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect8);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect8);
                        }
                    square[8] = !square[8];
                    SDL_RenderPresent(window->renderer);
                    }


                    if (x >= rect9.x && x <= rect9.x + SQUARE_SIZE && y >= rect9.y && y <= rect9.y + SQUARE_SIZE && square[9] == 0 && game_started==1) {
                        if(tab[9] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect9);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect9);
                        }
                    square[9] = !square[9];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect10.x && x <= rect10.x + SQUARE_SIZE && y >= rect10.y && y <= rect10.y + SQUARE_SIZE && square[10] == 0 && game_started==1) {
                        if(tab[10] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect10);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect10);
                        }
                    square[10] = !square[10];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect11.x && x <= rect11.x + SQUARE_SIZE && y >= rect11.y && y <= rect11.y + SQUARE_SIZE && square[11] == 0 && game_started==1) {
                        if(tab[11] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect11);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect11);
                        }
                    square[11] = !square[11];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect12.x && x <= rect12.x + SQUARE_SIZE && y >= rect12.y && y <= rect12.y + SQUARE_SIZE && square[12] == 0 && game_started==1) {
                        if(tab[12] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect12);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect12);
                        }
                    square[12] = !square[12];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect13.x && x <= rect13.x + SQUARE_SIZE && y >= rect13.y && y <= rect13.y + SQUARE_SIZE && square[13] == 0 && game_started==1) {
                        if(tab[13] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect13);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect13);
                        }
                    square[13] = !square[13];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect14.x && x <= rect14.x + SQUARE_SIZE && y >= rect14.y && y <= rect14.y + SQUARE_SIZE && square[14] == 0 && game_started==1) {
                        if(tab[14] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect14);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect14);
                        }
                    square[14] = !square[14];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect15.x && x <= rect15.x + SQUARE_SIZE && y >= rect15.y && y <= rect15.y + SQUARE_SIZE && square[15] == 0 && game_started==1) {
                        if(tab[15] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect15);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect15);
                        }
                    square[15] = !square[15];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect16.x && x <= rect16.x + SQUARE_SIZE && y >= rect16.y && y <= rect16.y + SQUARE_SIZE && square[16] == 0 && game_started==1) {
                        if(tab[16] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect16);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect16);
                        }
                    square[16] = !square[16];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect17.x && x <= rect17.x + SQUARE_SIZE && y >= rect17.y && y <= rect17.y + SQUARE_SIZE && square[17] == 0 && game_started==1) {
                        if(tab[17] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect17);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect17);
                        }
                    square[17] = !square[17];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect18.x && x <= rect18.x + SQUARE_SIZE && y >= rect18.y && y <= rect18.y + SQUARE_SIZE && square[18] == 0 && game_started==1) {
                        if(tab[18] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect18);
                            break;
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect18);
                        }
                    square[18] = !square[18];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect19.x && x <= rect19.x + SQUARE_SIZE && y >= rect19.y && y <= rect19.y + SQUARE_SIZE && square[19] == 0 && game_started==1) {
                        if(tab[19] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect19);
                            break;
                        }
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect19);
                        }
                    square[19] = !square[19];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect20.x && x <= rect20.x + SQUARE_SIZE && y >= rect20.y && y <= rect20.y + SQUARE_SIZE && square[20] == 0 && game_started==1) {
                        if(tab[20] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect20);
                            break;
                        }
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect20);
                        }
                    square[20] = !square[20];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect21.x && x <= rect21.x + SQUARE_SIZE && y >= rect21.y && y <= rect21.y + SQUARE_SIZE && square[21] == 0 && game_started==1) {
                        if(tab[21] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect21);
                            break;
                        }
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect21);
                        }
                    square[21] = !square[21];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect22.x && x <= rect22.x + SQUARE_SIZE && y >= rect22.y && y <= rect22.y + SQUARE_SIZE && square[22] == 0 && game_started==1) {
                        if(tab[22] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect22);
                            break;
                        }
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect22);
                            break;
                        }
                    square[22] = !square[22];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect23.x && x <= rect23.x + SQUARE_SIZE && y >= rect23.y && y <= rect23.y + SQUARE_SIZE && square[23] == 0 && game_started==1) {
                        if(tab[23] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect23);
                            break;
                        }
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect23);
                        }
                    square[23] = !square[23];
                    SDL_RenderPresent(window->renderer);
                    }

                    if (x >= rect24.x && x <= rect24.x + SQUARE_SIZE && y >= rect24.y && y <= rect24.y + SQUARE_SIZE && square[24] == 0 && game_started==1) {
                        if(tab[24] == 1) {

                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect24);
                            break;
                        }
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                            SDL_RenderCopy(window->renderer, texture, NULL, &rect24);
                        }
                    square[24] = !square[24];
                    SDL_RenderPresent(window->renderer);
                    } 
            }
        }
    // Afficher l'écran
    SDL_RenderPresent(window->renderer);
    
    }

    // Nettoyer les ressources utilisées
    destroy_window(window);
    SDL_Quit();

    return 0;
}
