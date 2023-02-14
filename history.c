#include "SDL2\include\SDL2\history.h"
#include <stdio.h>
#include <stdlib.h>

GameHistory* create_history(int bet, int nb_sticks, int total) {
    GameHistory* hist = malloc(sizeof(GameHistory));
    hist->bet = bet;
    hist->nb_sticks = nb_sticks;
    hist->total = total;
    hist->next = NULL;

    return hist;
}

void update_history(GameHistory** head, GameHistory** tail, int bet, int nb_sticks, int total) {
    GameHistory* hist = create_history(bet, nb_sticks, total);

    if (*head == NULL) {
        *head = hist;
        *tail = hist;
    } else {
        (*tail)->next = hist;
        *tail = hist;
    }
}

void free_list(GameHistory* head) {
    if (head == NULL) {
        return;
    }

    GameHistory* current = head;
    do {
        GameHistory* temp = current->next;
        free(current);
        current = temp;
    } while (current != NULL);
}

//pour ecrire dans le .txt chaque chainons de la liste chainée a la fin du programme
// void iterate(GameHistory* head) {   
//     if (head == NULL) {
//         return;
//     }

//     GameHistory* current = head;
//     while (current != NULL) {
//         // Ta fonction

//         current = current->next;
//     }
// }