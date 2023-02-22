#include "piles.c"
#include <stdio.h>
#include <stdlib.h>

// see below
int nameChk(int _index, char *_name);

int main(int argc, char *argv[]) {
  system("clear");

  printf("====== MENU ======\n\n");
  printf("Pick a value between 1 & 5\n\n");
  printf("1. Add an item\n");
  printf("2. Remove items\n");
  printf("3. Get items\n");
  printf("4. Get an item\n");
  printf("5. Quit program\n\n");

  // Init chained list and randomizer
  Pile *pile = initPile();
  srand(time(NULL));
  // seletion will lead cases and isQuitting stays negative until user quits
  int selection = 0, isQuitting = 0;
  char selec[2];

  while (!isQuitting && (selection = getchar()) != '\0') {

    // strcspn switches \n to \0 to avoid memory issues due to fgets
    fgets(selec, sizeof(selection), stdin);
    selec[strcspn(selec, "\n")] = '\0';

    switch (selection) {
    case '1':
      pileUp(pile, randomizer(0, 100));
      break;

    case '2':
      // delete all items instead of one by one
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

      // user enters an item name. the program sanitize the input by replacing
      // \n by \0
      fgets(itemName, sizeof(itemName), stdin);
      itemName[strcspn(itemName, "\n")] = '\0';

      // incrementing the count till the end of the string
      int index = hashing(itemName), count = 0;
      for (count = 0; selec[count] != '\0'; ++count)
        ;

      /*
      Any input not fitting a four characters long format will break the loop or
      if the slot is empty to avoid segmentation fault
      */
      if (hash_table[index] == NULL || count > 4) {
        printf("Error | No Item or wrong format\n");
        free(itemName);
        break;
      }

      /*
        It is possible that hash_table[index]->name_id is not equal to itemName
        due to the hash function, thus stored somewhere else in the chained
        list. To check whether the input exists or not, I use the recusion
        function nameChk (see below)
      */
      if (strcmp(hash_table[index]->name_id, itemName) != 0) {
        index = nameChk(index, itemName);
      }

      /*
      if nameChk returns -1, the item either does not exists or there is no
      more space available between 10 - (n-1) where n is strictly superior to
      -1.
      */
      if (index == -1) {
        printf("Error | non existent or clear memory\n");
        free(itemName);
        break;
      }

      // print item details
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

int nameChk(int _index, char *_name) {
  _index++;

  /*
  first step consists to check if the index is superior to 10 or if the given
  slot is empty. If the next slot is empty, it is certain that the input does
  not exist is the chained list (that's due to the very nature of the hashing algorithm -> hash.c)
  */
  if (_index > 9 || hash_table[_index] == NULL) {
    _index = -1;
    return _index;
  }

  /*
  until index reaches 10, nameChk calls itself to check if the input exists or not
  */
  if (strcmp(_name, hash_table[_index]->name_id) != 0) {
    return nameChk(_index, _name);
  } else {
    return _index;
  }
}
