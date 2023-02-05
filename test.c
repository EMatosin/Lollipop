#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 2500
#define HEIGHT 1200
#define SQUARE_SIZE 100


void delRessources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t)
{

	if(t != NULL)
		SDL_DestroyTexture(t);
	if(r != NULL)
		SDL_DestroyRenderer(r);
	if(w != NULL)
		SDL_DestroyWindow(w);
	SDL_Quit();

}


int main(int argc, char *argv[]) {
    // Initialiser SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return 1;
    }

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

    // Variables pour stocker l'état des carrés (s'ils sont retournés ou non)
    int square1 = 0;
    int square2 = 0;
    int square3 = 0;
    int square4 = 0;

    // Initilisation des carrés
    SDL_Rect rect1 = { WIDTH/4, HEIGHT/2, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect2 = { 2*WIDTH/4, HEIGHT/2, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect3 = { 3*WIDTH/4, HEIGHT/2, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect rect4 = { 3*WIDTH/4, HEIGHT/3, SQUARE_SIZE, SQUARE_SIZE };

    // Boucle principale pour gérer les événements
    int running = 1;
    // Effacer l'écran
    SDL_RenderClear(renderer);
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // Gérer les événements de fermeture de fenêtre
            if (event.type == SDL_QUIT) {
                running = 0;
            }

            // Gérer les événements de clic de souris
            if (event.type == SDL_MOUSEBUTTONDOWN) {

                // Récupérer les coordonnées du clic
                int x = event.button.x;
                int y = event.button.y;

                // Vérifier si le clic a eu lieu dans l'un des carrés
                if (x >= WIDTH/4 && x <= WIDTH/4 + SQUARE_SIZE && y >= HEIGHT/2 && y <= HEIGHT/2 + SQUARE_SIZE) {
                square1 = !square1;
                }
                if (x >= WIDTH*2/4 && x <= WIDTH*2/4 + SQUARE_SIZE && y >= HEIGHT/2 && y <= HEIGHT/2 + SQUARE_SIZE) {
                square2 = !square2;
                }
                if (x >= WIDTH*3/4 && x <= WIDTH*3/4 + SQUARE_SIZE && y >= HEIGHT/2 && y <= HEIGHT/2 + SQUARE_SIZE) {
                square3 = !square3;
                }
                if (x >= WIDTH*3/4 && x <= WIDTH*3/4 + SQUARE_SIZE && y >= HEIGHT/3 && y <= HEIGHT/3 + SQUARE_SIZE) {
                square4 = !square4;
                }

            }
        }
            // Dessiner les carrés
    if (square1) {
        SDL_Surface* picture = SDL_LoadBMP("jojo.bmp");
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, picture);
        SDL_RenderCopy(renderer, texture, NULL, &rect1);
        SDL_RenderPresent(renderer);

    } else {
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(renderer, &rect1);
        SDL_RenderPresent(renderer);
    }

    if (square2) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }
    SDL_RenderFillRect(renderer, &rect2);

    if (square3) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }
    SDL_RenderFillRect(renderer, &rect3);

    if (square4) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }
    SDL_RenderFillRect(renderer, &rect4);

    // Afficher l'écran
    SDL_RenderPresent(renderer);
    
    }

    // Nettoyer les ressources utilisées
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
