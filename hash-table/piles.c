#include "hash.c"
#include "pile.h"
#include "randomizer.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH

// recursion() act like nameChk in main.c without the memory leak constraints
int recursion(int _hash);
Cell *hash_table[10];

// init pile with no value
Pile *initPile() {
  Pile *pile = malloc(sizeof(*pile));
  pile->first = NULL;

  return pile;
}

// get items from pile
void getCells(Pile *_pile) {
  (_pile == NULL) ? exit(EXIT_FAILURE) : NULL;

  Cell *currentCell = _pile->first;

  while (currentCell != NULL) {
    printf("%s > %d \n", currentCell->name_id, currentCell->number);
    currentCell = currentCell->next;
  }
}

// add item on top of pile
void pileUp(Pile *_pile, int _newNumb) {
  Cell *cell = malloc(sizeof(*cell));

  (_pile == NULL || cell == NULL) ? exit(EXIT_FAILURE) : NULL;

  char *randStr = randName();
  int hash = hashing(randStr);
  hash = recursion(hash);

  if (hash == -1) {
    printf(
        "No more space in cue!!! Release memory before adding items again..");
    free(randStr);
    return;
  }

  hash_table[hash] = cell;

  strcpy(cell->name_id, randStr);
  cell->number = _newNumb;
  cell->next = _pile->first;
  _pile->first = cell;
  free(randStr);

  printf("Item added..\n\n");
}

// remove last added item
int unpille(Pile *_pile) {
  (_pile == NULL) ? exit(EXIT_FAILURE) : NULL;

  Cell *currentCell = _pile->first;
  int unpilled = 0;

  if (_pile != NULL && _pile->first != NULL) {
    unpilled = currentCell->number;
    _pile->first = currentCell->next;
    free(currentCell);
  }

  return unpilled;
}

int recursion(int _hash) {
  printf(">><<TRUE\n");

  if (_hash >= 10) {
    _hash = -1;
    return _hash;
  }

  if (hash_table[_hash] != NULL && _hash < 10) {
    _hash++;
    return recursion(_hash);
  }

  return _hash;
}
