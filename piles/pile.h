#ifndef H_PILE
#define H_PILE

typedef struct Element Element;
struct Element {
  int number;
  Element *next;
};

typedef struct Pile Pile;
struct Pile {
  Element *first;
};

Pile *initialisation();
void getPile(Pile *_pile);
void piling(Pile *_pile, int newNmb);
int unpile(Pile *_pile);

#endif