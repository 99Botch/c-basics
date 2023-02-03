#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomizer(int _min, int _max) {
  int rand_num = 0;
  rand_num = (rand() % (_max - _min + 1)) + _min;
  return rand_num;
}