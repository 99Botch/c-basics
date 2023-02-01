#include "chained_list.h"
#include <stdio.h>
#include <stdlib.h>

List *initialisation() {
  List *list = malloc(sizeof(*list));
  Element *element = malloc(sizeof(*element));

  if (list == NULL || element == NULL) {
    exit(EXIT_FAILURE);
  }

  element->number = 99;
  element->next = NULL;

  list->first = element;
  list->lenList = 1;

  return list;
}

void topInsertion(List *list, int _newNmb) {
  /* Création du nouvel élément */
  Element *addElemTop = malloc(sizeof(*addElemTop));
  if (list == NULL || addElemTop == NULL) {
    exit(EXIT_FAILURE);
  }
  addElemTop->number = _newNmb;

  /* Insertion de l'élément au début de la list */
  addElemTop->next = list->first;
  list->first = addElemTop;
  list->lenList++;
}

void medianInsertion(List *list, int _newNmb, int _median) {
  Element *addElemMedian = malloc(sizeof(*addElemMedian));
  if (list == NULL || addElemMedian == NULL) {
    exit(EXIT_FAILURE);
  }
  addElemMedian->number = _newNmb;

  Element *cell = list->first;

  int accumulator = 0;
  do {
    cell = cell->next;
    accumulator++;

    if(accumulator == _median){
      addElemMedian->next = cell->next;
      cell->next = addElemMedian;
    }
  } while (accumulator != _median);
  list->lenList++;
  printf("\n");
}

void topDeletion(List *list) {
  if (list == NULL)
    exit(EXIT_FAILURE);

  if (list->first != NULL) {
    Element *toDelete = list->first;
    list->first = list->first->next;
    free(toDelete);
    list->lenList--;
  }
}

void medianDeletion(List *list, int _median) {
  if (list == NULL)
    exit(EXIT_FAILURE);

  Element *cell = list->first;

  int accumulator = 0;
  do {
    Element *predecessor = cell;
    cell = cell->next;
    accumulator++;

    if(accumulator == _median){
      predecessor->next = cell->next;
      free(cell);
    }
  } while (accumulator != _median);
  list->lenList--;
  printf("\n");
}


void getList(List *list) {
  if (list == NULL)
    exit(EXIT_FAILURE);

  Element *cell = list->first;

  while (cell != NULL) {
    printf("%d -> ", cell->number);
    cell = cell->next;
  }
  printf("NULL\n");
}

void eraseList(List *list) {
  if (list == NULL)
    exit(EXIT_FAILURE);

  Element *cell = list->first;
  Element *predecessor = NULL;

  while (cell != NULL) {
    predecessor = cell->next;
    free(cell);
    cell = predecessor;
  }
  printf("\n");
}
