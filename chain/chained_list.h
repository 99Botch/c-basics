#ifndef H_CHAINED_LIST
#define H_CHAINED_LIST

typedef struct Element Element;
struct Element {
  int number;
  Element *next;
};

typedef struct List List;
struct List {
  Element *first;
  int lenList;
};

List *initialisation();
void topInsertion(List *list, int newNmb);
void medianInsertion(List *list, int newNmb, int median);
void topDeletion(List *list);
void medianDeletion(List *list, int median);
void getList(List *list);
void eraseList(List *list);

#endif
