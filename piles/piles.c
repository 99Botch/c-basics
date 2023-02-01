#include "pile.h"
#include <stdio.h>
#include <stdlib.h>

Pile *initialisation() {
  Pile *pile = malloc(sizeof(*pile));
  pile->first = NULL;

  return pile;
}

void getPile(Pile *_pile) {
  if (_pile == NULL)
    exit(EXIT_FAILURE);

  Element *cell = _pile->first;

  while (cell != NULL) {
    printf("%d ; ", cell->number);
    cell = cell->next;
  }
  printf("\n\n");
}

void piling(Pile *_pile, int newNmb) {
  Element *newElem = malloc(sizeof(*newElem));

  if (_pile == NULL || newElem == NULL) {
    printf("%p", _pile);
  }

  newElem->number = newNmb;
  newElem->next = _pile->first;
  _pile->first = newElem;
}

int unpile(Pile *_pile) {
  if (_pile == NULL)
    exit(EXIT_FAILURE);

  int getInt = 0;
  Element *cell = _pile->first;

  if (_pile != NULL && _pile->first != NULL) {
    getInt = cell->number;
    _pile->first = cell->next;
    free(cell);
  }

  return getInt;
}
