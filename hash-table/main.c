#include "piles.c"
#include <stdio.h>

int recur(int _index, char *name);

int main(int argc, char *argv[]) {
  system("clear");

  printf("====== MENU ======\n\n");
  printf("Pick a value between 1 & 5\n\n");
  printf("1. Add an Item\n");
  printf("2. Remove an Item\n");
  printf("3. Get Items\n");
  printf("4. Get an Item\n");
  printf("5. Quit program\n\n");

  // setup global var ---------------------------------------
  Pile *pile = initPile();
  srand(time(NULL));

  // setup menu selection -----------------------------------
  int selection = 0, isQuitting = 0;
  char str[2];

  while (!isQuitting && (selection = getchar()) != '\0') {

    fgets(str, sizeof(selection), stdin);
    str[strcspn(str, "\n")] = '\0';

    switch (selection) {
    case '1':
      pileUp(pile, randomizer(0, 100));
      printf("Item added..\n\n");
      break;

    case '2':
      printf("Unpilled items: ");
      for (int i = 0; i < 10; i++) {
        printf("%d / ", unpille(pile));
        hash_table[i] = NULL;
      }
      printf("\n\n");

      break;

    case '3':
      getCells(pile);
      printf("\n");
      break;

    case '4':
      printf("Which item are you looking for? ");
      char *itemName = malloc(sizeof(itemName));

      fgets(itemName, sizeof(itemName), stdin);
	  itemName[strcspn(itemName, "\n")] = '\0';

      int index = hashing(itemName);

      if (strcmp(itemName, hash_table[index]->name_id) != 0) {
        index = recur(index, itemName);
      }

      printf("%s: %d\n\n", hash_table[index]->name_id,
             hash_table[index]->number);

      free(itemName);
      break;

    case '5':
      printf("Quitting..\n");
      isQuitting = 1;
      break;

    default:
      printf("Invalid input\n");
      break;
    }
  }
  return 0;
}

int recur(int _index, char *_name) {
  if (hash_table[_index]->name_id != _name) {
    _index++;
	printf("%s", _name);
    return recur(_index, _name);
  }
  return _index;
}
