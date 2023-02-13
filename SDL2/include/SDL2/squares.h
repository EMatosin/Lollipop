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

void init_grid(GameGrid* grid, Window *window);

void randomizer(GameGrid* grid, int nb_sticks);

void free_grid(GameGrid* grid);

void draw_squares(Window *window, GameGrid* grid, const char* file_path);

int check_square_click(Window* window, GameGrid* grid, int x_click, int y_click);

void reveal_all(Window* window, GameGrid* grid);

#endif