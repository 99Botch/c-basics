#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "piles.c"

int main(int argc, char *argv[]){
    system("clear");

    Pile *pile = initialisation();

    for(int i = 0; i < 10; i++){
        piling(pile, i);
    }
    getPile(pile);

    for(int i = 0; i < 5; i++){
        printf("The returned element is: %d\n", unpile(pile));
    }
    getPile(pile);

    return 0;
}