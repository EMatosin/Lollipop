#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


#define WIDTH 900
#define HEIGHT 900
#define SQUARE_SIZE 50
#define NUM_IMAGES 5
#define NUM_LOLLIPOP 25


// Stockage des images pour éviter des perturbations au niveau des clics

SDL_Surface *images[NUM_IMAGES];
char *image_files[NUM_IMAGES] = {"images/win.bmp","images/lose.bmp","images/play.bmp","images/stop.bmp","images/start.bmp"};

int main(int argc, char *argv[]) {
    // Initialiser SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    // Créer une fenêtre
    SDL_Window *window = SDL_CreateWindow("Carrés cliquables", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        return 1;
    }

    // Créer un renderer pour dessiner dans la fenêtre
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "Erreur lors de la création du renderer : %s\n", SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);

    // Variables du hasard

    int tirage;
    int tab[NUM_LOLLIPOP] = {0};
    int i;
    int perdu;

    // Initialisation des variabeles qui sera fait plus tard dans le fichier de config
    perdu = 12;

    // Variables pour stocker l'état des carrés (s'ils sont retournés ou non)

    int square[NUM_LOLLIPOP];
    for (i = 0; i < NUM_LOLLIPOP; i++){
        square[i]= 0;
    }
    //int play = 0;

    // Initilisation des différentes sections

        /*Carrés*/
		/*premiere ligne*/
    SDL_Rect rect0 = { 2*WIDTH/14, HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect1 = { 4*WIDTH/14, HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect2 = { 6*WIDTH/14, HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect3 = { 8*WIDTH/14, HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect4 = { 10*WIDTH/14, HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
   		/*deuxieme ligne*/
    SDL_Rect rect5 = { 2*WIDTH/14, HEIGHT/4, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect6 = { 4*WIDTH/14, HEIGHT/4, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect7 = { 6*WIDTH/14, HEIGHT/4, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect8 = { 8*WIDTH/14, HEIGHT/4, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect9 = { 10*WIDTH/14, HEIGHT/4, SQUARE_SIZE, SQUARE_SIZE };
    	/*troisieme ligne*/
    SDL_Rect rect10 = { 2*WIDTH/14, HEIGHT/4+HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect11 = { 4*WIDTH/14, HEIGHT/4+HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect12 = { 6*WIDTH/14, HEIGHT/4+HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect13 = { 8*WIDTH/14, HEIGHT/4+HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect14 = { 10*WIDTH/14, HEIGHT/4+HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
		/*quatrieme ligne*/
    SDL_Rect rect15 = { 2*WIDTH/14, HEIGHT/2, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect16 = { 4*WIDTH/14, HEIGHT/2, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect17 = { 6*WIDTH/14, HEIGHT/2, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect18 = { 8*WIDTH/14, HEIGHT/2, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect19 = { 10*WIDTH/14, HEIGHT/2, SQUARE_SIZE, SQUARE_SIZE };
		/*cinquieme ligne*/
    SDL_Rect rect20 = { 2*WIDTH/14, HEIGHT/2+HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect21 = { 4*WIDTH/14, HEIGHT/2+HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect22 = { 6*WIDTH/14, HEIGHT/2+HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect23 = { 8*WIDTH/14, HEIGHT/2+HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect24 = { 10*WIDTH/14, HEIGHT/2+HEIGHT/8, SQUARE_SIZE, SQUARE_SIZE };
    // SDL_Rect bouton_play = { WIDTH/2, HEIGHT/4, SQUARE_SIZE, SQUARE_SIZE };


    // Initialisation des logos
            /*Carrés*/
    SDL_Surface* picture_origin = SDL_LoadBMP(image_files[4]);
    SDL_Texture* texture_origin = SDL_CreateTextureFromSurface(renderer, picture_origin);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect0);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect1);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect2);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect3);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect4);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect5);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect6);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect7);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect8);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect9);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect10);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect11);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect12);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect13);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect14);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect15);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect16);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect17);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect18);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect19);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect20);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect21);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect22);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect23);
    SDL_RenderCopy(renderer, texture_origin, NULL, &rect24);
    // SDL_Surface* picture_play = SDL_LoadBMP(image_files[2]);
    // SDL_Texture* texture_play = SDL_CreateTextureFromSurface(renderer, picture_play);
    // SDL_RenderCopy(renderer, texture_play, NULL, &bouton_play);

    // On va initialiser les carrés et placer les os et poulet
    srand(time(NULL));
    for(i = 0; i < perdu; i++){
        tirage = rand() % NUM_LOLLIPOP;
        if(tab[tirage] == 1){
            while(tab[tirage] != 1) {
                tirage = rand() % NUM_LOLLIPOP;
                tab[tirage] = 1;
            }
        }
        tab[tirage] = 1;
    }

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

                    // Vérifier si le clic a eu lieu dans l'un des carrés                   
                    if (x >= rect0.x && x <= rect0.x + SQUARE_SIZE && y >= rect0.y && y <= rect0.y + SQUARE_SIZE && square[0] == 0) {
                        if(tab[0] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect0);
                        } 
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect0);
                        }
                    square[0] = !square[0];
                    SDL_RenderPresent(renderer);
                    }
                    
                    if (x >= rect1.x && x <= rect1.x + SQUARE_SIZE && y >= rect1.y && y <= rect1.y + SQUARE_SIZE && square[1] == 0) {
                        if(tab[1] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect1);
                        } 
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect1);
                        }
                    square[1] = !square[1];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0) {
                        if(tab[2] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect2);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect2);
                        }                
                    square[2] = !square[2];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect3.x && x <= rect3.x + SQUARE_SIZE && y >= rect3.y && y <= rect3.y + SQUARE_SIZE && square[3] == 0) {
                        if(tab[3] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect3);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect3);
                        }                
                    square[3] = !square[3];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect4.x && x <= rect4.x + SQUARE_SIZE && y >= rect4.y && y <= rect4.y + SQUARE_SIZE && square[4] == 0) {
                        if(tab[4] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect4);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect4);
                        }                
                    square[4] = !square[4];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect5.x && x <= rect5.x + SQUARE_SIZE && y >= rect5.y && y <= rect5.y + SQUARE_SIZE && square[5] == 0) {
                        if(tab[5] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect5);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect5);
                        }                
                    square[5] = !square[5];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect6.x && x <= rect6.x + SQUARE_SIZE && y >= rect6.y && y <= rect6.y + SQUARE_SIZE && square[6] == 0) {
                        if(tab[6] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect6);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect6);
                        }                
                    square[6] = !square[6];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect7.x && x <= rect7.x + SQUARE_SIZE && y >= rect7.y && y <= rect7.y + SQUARE_SIZE && square[7] == 0) {
                        if(tab[7] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect7);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect7);
                        }                
                    square[7] = !square[7];
                    SDL_RenderPresent(renderer);
                    }

                    // if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0) {
                    //     if(tab[2] == 1) {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     } else {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     }                
                    // square[2] = !square[2];
                    // SDL_RenderPresent(renderer);
                    // }

                    // if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0) {
                    //     if(tab[2] == 1) {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     } else {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     }                
                    // square[2] = !square[2];
                    // SDL_RenderPresent(renderer);
                    // }

                    // if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0) {
                    //     if(tab[2] == 1) {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     } else {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     }                
                    // square[2] = !square[2];
                    // SDL_RenderPresent(renderer);
                    // }

                    // if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0) {
                    //     if(tab[2] == 1) {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     } else {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     }                
                    // square[2] = !square[2];
                    // SDL_RenderPresent(renderer);
                    // }

                    // if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0) {
                    //     if(tab[2] == 1) {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     } else {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     }                
                    // square[2] = !square[2];
                    // SDL_RenderPresent(renderer);
                    // }

                    // if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0) {
                    //     if(tab[2] == 1) {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     } else {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     }                
                    // square[2] = !square[2];
                    // SDL_RenderPresent(renderer);
                    // }

                    // if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0) {
                    //     if(tab[2] == 1) {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     } else {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     }                
                    // square[2] = !square[2];
                    // SDL_RenderPresent(renderer);
                    // }

                    // if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0) {
                    //     if(tab[2] == 1) {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     } else {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     }                
                    // square[2] = !square[2];
                    // SDL_RenderPresent(renderer);
                    // }

                    // if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0) {
                    //     if(tab[2] == 1) {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     } else {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     }                
                    // square[2] = !square[2];
                    // SDL_RenderPresent(renderer);
                    // }

                    // if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0) {
                    //     if(tab[2] == 1) {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     } else {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     }                
                    // square[2] = !square[2];
                    // SDL_RenderPresent(renderer);
                    // }

                    // if (x >= rect2.x && x <= rect2.x + SQUARE_SIZE && y >= rect2.y && y <= rect2.y + SQUARE_SIZE && square[2] == 0) {
                    //     if(tab[2] == 1) {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     } else {
                    //         SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                    //         SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //         SDL_RenderCopy(renderer, texture, NULL, &rect2);
                    //     }                
                    // square[2] = !square[2];
                    // SDL_RenderPresent(renderer);
                    // }
                    // if (x >= bouton_play.x && x <= bouton_play.x + SQUARE_SIZE && y >= bouton_play.y && y <= bouton_play.y + SQUARE_SIZE) {
                    //     if (play) {
                    //             SDL_Surface* picture = SDL_LoadBMP(image_files[2]);
                    //             SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //             SDL_RenderCopy(renderer, texture, NULL, &bouton_play);
                    //     } else {
                    //             SDL_Surface* picture = SDL_LoadBMP(image_files[3]);
                    //             SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                    //             SDL_RenderCopy(renderer, texture, NULL, &bouton_play);
                    //     }
                    // play = !play;
                    // SDL_RenderPresent(renderer);
                    // }              
            }
        }
    // Afficher l'écran
    SDL_RenderPresent(renderer);
    
    }

    // Nettoyer les ressources utilisées
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture_origin);
    //SDL_DestroyTexture(texture_play);
    //SDL_DestroyTexture(texture);
    SDL_Quit();

    return 0;
}
