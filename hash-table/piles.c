#include "pile.h"
#include <stdio.h>
#include <stdlib.h>

// init pile
Pile *initPile() {
  Pile *pile = malloc(sizeof(*pile));
  pile->first = NULL;

  return pile;
}

// get items from pile
void getCells(Pile *_pile) {
  if (_pile == NULL)
    exit(EXIT_FAILURE);

  Cell *currentCell = _pile->first;

  while (currentCell != NULL) {
    printf("%d\n; ", currentCell->number);
    printf("%s\n; ", currentCell->name);
    currentCell = currentCell->next;
  }
  printf("\n\n");
}

// add item on top of pile
void pileUp(Pile *_pile, int _newNumb) {
  Cell *cell = malloc(sizeof(*cell));

  if (_pile == NULL || cell == NULL)
    exit(EXIT_FAILURE);
  cell->number = _newNumb;

  char intParser[20];
  sprintf(intParser, "%d", _newNumb);
  printf("%s; ", intParser);
  cell->name = intParser;

  cell->next = _pile->first;
  _pile->first = cell;
}

// remove last added item
int unpille(Pile *_pile) {
  if (_pile == NULL)
    exit(EXIT_FAILURE);

  Cell *currentCell = _pile->first;
  int unpilled = 0;

  if (_pile != NULL && _pile->first != NULL) {
    //unpilled = currentCell->number;
    _pile->first = currentCell->next;
    free(currentCell);
  }

  return unpilled;
}

/*
 * HASHING
 */