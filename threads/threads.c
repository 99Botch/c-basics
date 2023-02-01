#include "thread.h"
#include <stdio.h>
#include <stdlib.h>

Thread *initialisation() {
  Thread *thread = malloc(sizeof(*thread));
  thread->first = NULL;

  return thread;
}

void getThread(Thread *_thread) {
  if (_thread == NULL)
    exit(EXIT_FAILURE);

  Element *cell = _thread->first;

  while (cell != NULL) {
    printf("%d ; ", cell->number);
    cell = cell->next;
  }
  printf("\n");
}

void threading(Thread *_thread, int _newNmb) {
  Element *newElem = malloc(sizeof(*newElem));

  if (_thread == NULL || newElem == NULL)
    exit(EXIT_FAILURE);

  newElem->number = _newNmb;
  newElem->next = NULL;

  if (_thread->first != NULL) {
    Element *cell = _thread->first;
    while (cell->next != NULL) {
      cell = cell->next;
    }
    cell->next = newElem;
  } else {
    _thread->first = newElem;
  }
}

int unthread(Thread *_thread) {
  if (_thread == NULL)
    exit(EXIT_FAILURE);

  Element *cell = _thread->first;
  int elem = cell->number;

  if (_thread != NULL && _thread->first != NULL) {
    _thread->first = cell->next;
    free(cell);
  }

  return elem;
}