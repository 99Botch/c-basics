#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SALT 10

int hashing(char *_id) {
  int hash = 0;
  _id[strcspn(_id, "\n")] = '\0';
  for (int i = 0; _id[i] != '\0'; i++) {
    hash += _id[i];
  }
  hash %= SALT;
  return hash;
}
