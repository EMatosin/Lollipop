#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_LOLLIPOP 25
#define WIN 0
#define LOSE 1

// Variables du hasard
int tirage;
int tab[NUM_LOLLIPOP] = {0};
int i;
// Initialisation des variabeles qui sera fait plus tard dans le fichier de config
int perdu = 6; // A PARTIR DE 7 LE TRUC FAIT -1 

// Variables pour stocker l'état des carrés (s'ils sont retournés ou non)

void randomizer(){
    // On va initialiser les carrés et placer les os et poulet
    srand(time(NULL));

    for(i = 0; i < perdu; i++){
        tirage = rand() % NUM_LOLLIPOP;
        if(tab[tirage] == LOSE){
            while(tab[tirage] != LOSE) {
                tirage = rand() % NUM_LOLLIPOP;
                tab[tirage] = LOSE;
            }
        }
        tab[tirage] = LOSE;
    }

}


#endif