#ifndef H_PILE
#define H_PILE

typedef struct Cell Cell;
struct Cell {
  char *name;
  int number;
  Cell *next;
};

typedef struct Pile Pile;
struct Pile {
  Cell *first;
};

Pile *initPile();
void getCells(Pile *_pile);
void pileUp(Pile *_pile, int _newNumb);
int unpille(Pile *_pile);

#endif