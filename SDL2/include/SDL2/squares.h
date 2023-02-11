#ifndef SQUARES_H
#define SQUARES_H

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "window.h"

#define NUM_LOLLIPOP 25
#define WIN 0
#define LOSE 1
#define SQUARE_SIZE 100
#define GRID_WIDTH 5
#define GRID_HEIGHT 5
#define NUM_IMAGES 5
#define VERSO 0
#define RECTO 1
#define STOP 1
#define CONTINUE 0

char *image_files[NUM_IMAGES] = {"images/win.bmp","images/lose.bmp","images/play.bmp","images/stop.bmp","images/start.bmp"};

typedef struct {
    SDL_Rect square;
    int state;
    int score;
} GameSquare;

typedef struct {
    GameSquare** grid;
    int width;
    int height;
} GameGrid;

void init_grid(GameGrid* grid) {
    grid->grid = calloc(grid->height*grid->width, sizeof(GameSquare*));

    for(int i = 0; i < grid->width; i++) {
        for(int j = 0; j < grid->height; j++) {
            GameSquare* square = malloc(sizeof(GameSquare));
            square->state = VERSO;
            square->square.h = SQUARE_SIZE;
            square->square.w = SQUARE_SIZE;
            square->square.x = 2*(j+1)*WIDTH/14;
            square->square.y = (i+1)*HEIGHT/8;

            grid->grid[i*grid->height + j] = square;
        }
    }
}

void randomizer(GameGrid* grid, int nb_sticks) {
    for(int i = 0; i < NUM_LOLLIPOP; i++) {
        grid->grid[i]->score = WIN;
    }

    srand(time(NULL));
    for(int i = 0; i < nb_sticks; i++) {
        int tirage = rand() % NUM_LOLLIPOP;
        while(grid->grid[tirage]->score == LOSE){
            tirage = rand() % NUM_LOLLIPOP;
        }
        grid->grid[tirage]->score = LOSE;
    }
}

void free_grid(GameGrid* grid) {
    for(int i = 0; i < NUM_LOLLIPOP; i++) {
        free(grid->grid[i]);
    }
    free(grid);
}

void draw_squares(Window *window, GameGrid* grid, const char* file_path) {
    SDL_Surface* picture_origin = SDL_LoadBMP(file_path);
    SDL_Texture* texture_origin = SDL_CreateTextureFromSurface(window->renderer, picture_origin);

    for(int i = 0; i < NUM_LOLLIPOP; i++) {
        grid->grid[i]->state = VERSO;
        SDL_RenderCopy(window->renderer, texture_origin, NULL, &(grid->grid[i]->square));
        SDL_RenderPresent(window->renderer);
    }
}

int check_square_click(Window* window, GameGrid* grid, int x_click, int y_click) {
    for(int i = 0; i < NUM_LOLLIPOP; i++) {
        GameSquare* current_square = grid->grid[i];
        if (x_click >= current_square->square.x && x_click <= current_square->square.x + SQUARE_SIZE &&
            y_click >= current_square->square.y && y_click <= current_square->square.y + SQUARE_SIZE && 
            current_square->state == VERSO) {

            current_square->state = RECTO;

            if(current_square->score == LOSE) {
                SDL_Surface* picture = SDL_LoadBMP("images/lose.bmp");
                SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                SDL_RenderCopy(window->renderer, texture, NULL, &current_square->square);
                SDL_RenderPresent(window->renderer);
                
                return STOP;
            } else {
                SDL_Surface* picture = SDL_LoadBMP("images/win.bmp");
                SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                SDL_RenderCopy(window->renderer, texture, NULL, &current_square->square);
                SDL_RenderPresent(window->renderer);

                return CONTINUE;
            }
        }
    }

    return CONTINUE;
}

void reveal_all(Window* window, GameGrid* grid) {
    for(int i = 0; i < NUM_LOLLIPOP; i++) {
        GameSquare* current_square = grid->grid[i];

        if(current_square->state == VERSO) {
            if(current_square->score == LOSE) {
                SDL_Surface* picture = SDL_LoadBMP("images/lose.bmp");
                SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                SDL_RenderCopy(window->renderer, texture, NULL, &current_square->square);
            } 
            else {
                SDL_Surface* picture = SDL_LoadBMP("images/win.bmp");
                SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, picture);
                SDL_RenderCopy(window->renderer, texture, NULL, &current_square->square);
            }

            current_square->state = RECTO;
            SDL_RenderPresent(window->renderer);
        }
    }
}

#endif