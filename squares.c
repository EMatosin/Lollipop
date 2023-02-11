#include "C:\Users\emato\OneDrive\Bureau\Lollipop\SDL2\include\SDL2\squares.h"
#include <stdio.h>

void squares(Window *window){
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
    SDL_Texture* texture_origin = SDL_CreateTextureFromSurface(window->renderer, picture_origin);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect0);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect1);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect2);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect3);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect4);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect5);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect6);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect7);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect8);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect9);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect10);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect11);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect12);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect13);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect14);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect15);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect16);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect17);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect18);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect19);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect20);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect21);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect22);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect23);
    SDL_RenderCopy(window->renderer, texture_origin, NULL, &rect24);
    SDL_RenderPresent(window->renderer);
}