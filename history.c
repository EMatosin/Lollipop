#include "SDL2/include/SDL2/history.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

GameHistory* create_history(int bet, int nb_broccolis, float odds, float total) {
    GameHistory* hist = malloc(sizeof(GameHistory));
    hist->bet = bet;
    hist->nb_broccolis = nb_broccolis;
    hist->odds = odds;
    hist->total = total;
    hist->next = NULL;

    return hist;
}

void update_history(GameHistory** head, GameHistory** tail, int bet, int nb_broccolis, float odds, float total) {
    GameHistory* hist = create_history(bet, nb_broccolis, odds, total);

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

void SaveGames(GameHistory* head, const char *filename) {
    FILE *file;
    if (access(filename, F_OK) != -1){
        //l'historique existe déjà, on ouvre en mode "append"
        file = fopen(filename,"a");
    } else {
        // c'est la première fois qu'on joue au jeu, on ouvre en mode "write"
        file = fopen(filename, "w");
        fprintf(file, "Montant parié :\t\t");
        fprintf(file, "Nombre de broccolis choisis :\t\t");
        fprintf(file, "Multiplicateur final :\t\t");
        fprintf(file, "Montant amassé :\n\n");
    }
    if (file != NULL) {
        GameHistory *current = head;
        while (current != NULL) {
            fprintf(file, "\t %d $", current->bet);
            fprintf(file, "\t\t\t\t\t%d\t\t", current->nb_broccolis);
            fprintf(file, "\t\t\t X%.2f", current->odds);
            fprintf(file, "\t\t\t\t%.2f $\n", current->total);
            current = current->next;
        }
        fclose(file);
    }   
}