#include <SDL2/SDL.h>
#include "C:\Users\emato\OneDrive\Bureau\Lollipop\SDL2\include\SDL2\SDL_ttf.h"
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



//betbutton = SDL_CreateRGBSurface (0, 100, 100, 32, 0, 0, 0, 0);
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
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        fprintf(stderr, "Erreur lors de la création du renderer : %s\n", SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);

	/* TTF INIT */
	TTF_Init();

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


	/*backgrounds*/

		/*background window*/
		SDL_SetRenderDrawColor(renderer, 135, 76, 98, 255);
		SDL_Rect window_bg = {0, 0, WIDTH, HEIGHT};
		SDL_RenderFillRect(renderer, &window_bg);

		/*background lollypop*/
		SDL_SetRenderDrawColor(renderer, 196, 50, 145, 255);
		SDL_Rect lollypop_bg = {WIDTH/10,HEIGHT/11,WIDTH/1.4, HEIGHT/1.6};
		SDL_RenderFillRect(renderer, &lollypop_bg);

		/*background gain*/
		SDL_SetRenderDrawColor(renderer, 196, 50, 145, 255);
		SDL_Rect gain_bg = {WIDTH/2, HEIGHT/50, SQUARE_SIZE*4,SQUARE_SIZE};
		SDL_RenderFillRect(renderer, &gain_bg);

		/*background nblolly*/
		SDL_SetRenderDrawColor(renderer, 196, 50, 145, 255);
		SDL_Rect nblolly_bg = {WIDTH/2, 2*HEIGHT/3+HEIGHT/16, SQUARE_SIZE*5.5, SQUARE_SIZE*1.5};
		SDL_RenderFillRect(renderer, &nblolly_bg);

		/*background nbbet*/
		SDL_SetRenderDrawColor(renderer, 196, 50, 145, 255);
		SDL_Rect nbbet_bg = {WIDTH/10, 2*HEIGHT/3+HEIGHT/16, SQUARE_SIZE*5.5, SQUARE_SIZE*1.5};
		SDL_RenderFillRect(renderer, &nbbet_bg);








		/*bet button*/
		SDL_SetRenderDrawColor(renderer, 161, 241, 42, 255);
		SDL_Rect bet_button = {WIDTH/10,HEIGHT/2+HEIGHT/4+HEIGHT/12,WIDTH/1.4, HEIGHT/10};
		SDL_RenderFillRect(renderer, &bet_button);












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

	TTF_Font * font = TTF_OpenFont("PurpleSmile.ttf", 55);
	SDL_Color blackcolor = {0, 0, 0};
	SDL_Surface * betbtnsurf = TTF_RenderText_Blended(font, "BET", blackcolor);
	int texW = 0;
	int texH = 0;
	SDL_Texture * betbtntext = SDL_CreateTextureFromSurface(renderer, betbtnsurf);
	SDL_QueryTexture(betbtntext, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {WIDTH/2-WIDTH/10,HEIGHT/2+HEIGHT/4+HEIGHT/12, texW, texH};
	SDL_RenderCopy(renderer, betbtntext, NULL, &dstrect);
	SDL_RenderPresent(renderer);

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

                    if (x >= rect8.x && x <= rect8.x + SQUARE_SIZE && y >= rect8.y && y <= rect8.y + SQUARE_SIZE && square[8] == 0) {
                         if(tab[8] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect8);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect8);
                        }
                    square[8] = !square[8];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect9.x && x <= rect9.x + SQUARE_SIZE && y >= rect9.y && y <= rect9.y + SQUARE_SIZE && square[9] == 0) {
                        if(tab[9] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect9);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect9);
                        }
                    square[9] = !square[9];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect10.x && x <= rect10.x + SQUARE_SIZE && y >= rect10.y && y <= rect10.y + SQUARE_SIZE && square[10] == 0) {
                        if(tab[10] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect10);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect10);
                        }
                    square[10] = !square[10];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect11.x && x <= rect11.x + SQUARE_SIZE && y >= rect11.y && y <= rect11.y + SQUARE_SIZE && square[11] == 0) {
                        if(tab[11] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect11);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect11);
                        }
                    square[11] = !square[11];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect12.x && x <= rect12.x + SQUARE_SIZE && y >= rect12.y && y <= rect12.y + SQUARE_SIZE && square[12] == 0) {
                        if(tab[12] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect12);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect12);
                        }
                    square[12] = !square[12];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect13.x && x <= rect13.x + SQUARE_SIZE && y >= rect13.y && y <= rect13.y + SQUARE_SIZE && square[13] == 0) {
                        if(tab[13] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect13);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect13);
                        }
                    square[13] = !square[13];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect14.x && x <= rect14.x + SQUARE_SIZE && y >= rect14.y && y <= rect14.y + SQUARE_SIZE && square[14] == 0) {
                        if(tab[14] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect14);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect14);
                        }
                    square[14] = !square[14];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect15.x && x <= rect15.x + SQUARE_SIZE && y >= rect15.y && y <= rect15.y + SQUARE_SIZE && square[15] == 0) {
                        if(tab[15] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect15);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect15);
                        }
                    square[15] = !square[15];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect16.x && x <= rect16.x + SQUARE_SIZE && y >= rect16.y && y <= rect16.y + SQUARE_SIZE && square[16] == 0) {
                        if(tab[16] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect16);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect16);
                        }
                    square[16] = !square[16];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect17.x && x <= rect17.x + SQUARE_SIZE && y >= rect17.y && y <= rect17.y + SQUARE_SIZE && square[17] == 0) {
                        if(tab[17] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect17);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect17);
                        }
                    square[17] = !square[17];
                    SDL_RenderPresent(renderer);
                    }

                    if (x >= rect18.x && x <= rect18.x + SQUARE_SIZE && y >= rect18.y && y <= rect18.y + SQUARE_SIZE && square[18] == 0) {
                        if(tab[18] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect18);
                        } else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect18);
                        }
                    square[18] = !square[18];
                    SDL_RenderPresent(renderer);
                    }

		            if (x >= rect19.x && x <= rect19.x + SQUARE_SIZE && y >= rect19.y && y <= rect19.y + SQUARE_SIZE && square[19] == 0) {
                        if(tab[19] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect19);
                        }
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect19);
                        }
                    square[19] = !square[19];
                    SDL_RenderPresent(renderer);
                    }

		            if (x >= rect20.x && x <= rect20.x + SQUARE_SIZE && y >= rect20.y && y <= rect20.y + SQUARE_SIZE && square[20] == 0) {
                        if(tab[20] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect20);
                        }
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect20);
                        }
                    square[20] = !square[20];
                    SDL_RenderPresent(renderer);
                    }

		            if (x >= rect21.x && x <= rect21.x + SQUARE_SIZE && y >= rect21.y && y <= rect21.y + SQUARE_SIZE && square[21] == 0) {
                        if(tab[21] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect21);
                        }
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect21);
                        }
                    square[21] = !square[21];
                    SDL_RenderPresent(renderer);
                    }

		            if (x >= rect22.x && x <= rect22.x + SQUARE_SIZE && y >= rect22.y && y <= rect22.y + SQUARE_SIZE && square[22] == 0) {
                        if(tab[22] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect22);
                        }
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect22);
                        }
                    square[22] = !square[22];
                    SDL_RenderPresent(renderer);
                    }

		            if (x >= rect23.x && x <= rect23.x + SQUARE_SIZE && y >= rect23.y && y <= rect23.y + SQUARE_SIZE && square[23] == 0) {
                        if(tab[23] == 1) {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect23);
                        }
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect23);
                        }
                    square[23] = !square[23];
                    SDL_RenderPresent(renderer);
                    }

		            if (x >= rect24.x && x <= rect24.x + SQUARE_SIZE && y >= rect24.y && y <= rect24.y + SQUARE_SIZE && square[24] == 0) {
                        if(tab[24] == 1) {

                            SDL_Surface* picture = SDL_LoadBMP(image_files[0]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect24);
                        }
                        else {
                            SDL_Surface* picture = SDL_LoadBMP(image_files[1]);
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
                            SDL_RenderCopy(renderer, texture, NULL, &rect24);
                        }
                    square[24] = !square[24];
                    SDL_RenderPresent(renderer);
                    }

//                    if (x >= bouton_play.x && x <= bouton_play.x + SQUARE_SIZE && y >= bouton_play.y && y <= bouton_play.y + SQUARE_SIZE) {
//                         if (play) {
//                                 SDL_Surface* picture = SDL_LoadBMP(image_files[2]);
//                                 SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
//                                 SDL_RenderCopy(renderer, texture, NULL, &bouton_play);
//                         } else {
//                                 SDL_Surface* picture = SDL_LoadBMP(image_files[3]);
//                                 SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
//                                 SDL_RenderCopy(renderer, texture, NULL, &bouton_play);
//                         }
//                     play = !play;
//                     SDL_RenderPresent(renderer);
//                     }
            }
        }
    // Afficher l'écran
    SDL_RenderPresent(renderer);
    }

    // Nettoyer les ressources utilisées
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
	SDL_DestroyTexture (betbtntext);
	SDL_FreeSurface(betbtnsurf);
	TTF_CloseFont(font);
    SDL_DestroyTexture(texture_origin);
	TTF_Quit();
    SDL_Quit();

    return 0;
}
