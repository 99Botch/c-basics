#include <stdio.h>
#include <stdlib.h>

#define CHAR_ALLOWED                                                           \
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUWVXYZ1234567890"

int randomizer(int _min, int _max) {
  int rand_num = 0;
  rand_num = (rand() % (_max - _min + 1)) + _min;
  return rand_num;
}

char *randName() {
  char *name = malloc(sizeof(*name));
  const char ALLOWED[] = CHAR_ALLOWED;
  for (int i = 0; i < 4; i++) {
    int c = (rand() % (61 - 0 + 1) + 0);
    name[i] = ALLOWED[c];
  }
  name[4] = '\0';

  return name;
}
