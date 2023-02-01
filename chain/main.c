#include <stdio.h>
#include <stdlib.h>
#include "chained_lists.c"
  
int main(int argc, char *argv[]) {
  system("clear");

  int median = 0;

  List *list = initialisation();
  topInsertion(list, 88);
  topInsertion(list, 77);
  topInsertion(list, 66);

  getList(list);

  topDeletion(list);

  getList(list);

  printf("\nThe list is %d items long..", list->lenList);

  median = (list->lenList - 1) / 2;
  medianInsertion(list, 55, median);
  printf("\nThe list is %d items long..\n", list->lenList);
  getList(list);

  median = (list->lenList - 1) / 2;
  medianDeletion(list, median);
  printf("The list is %d items long..\n", list->lenList);
  getList(list);

  eraseList(list);
  getList(list);

  return 0;
}

