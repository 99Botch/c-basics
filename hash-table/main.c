#include "piles.c"
#include "randomizer.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  system("clear");

  // setup global var----------------------------------------
  Pile *pile = initPile();
  srand(time(NULL));
  int unpilleElem[5] = {0};

  // pile values --------------------------------------------
  for (int i = 0; i < 10; i++) {
    pileUp(pile, randomizer(0, 100));
  }
  getCells(pile);

  // // unpile values ------------------------------------------
  // for (int i = 0; i < 5; i++) {
  //   unpilleElem[i] += unpille(pile);
  // }

  // printf("List of unpilled elems: ");
  // for (int i = 0; i < 5; i++) {
  //   printf("%d ; ", unpilleElem[i]);
  // }
  // printf("\n\n");

  // // end result ---------------------------------------------
  // printf("List of remaining elems: ");
  // getCells(pile);

  return 0;
}