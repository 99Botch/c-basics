#include "pile.h"
#include <stdio.h>
#include <stdlib.h>

/*
  The salt determines the slot which the item is stored in
  if a given item has the same number to another item already stored in the
  chained list. The function checks if the next slot is available and does so
  untils it reached 10 (in which case the function returns -1 to signify there is
  no more space for allocation)
*/
int recursion(Cell _hash_table, int _hash) {
  if (_hash >= 10) {
    _hash = -1;
    return _hash;
  }

  if (_hash_table[_hash] != NULL && _hash < 10) {
    _hash++;
    return recursion(_hash_table, _hash);
  }

  return _hash;
}
