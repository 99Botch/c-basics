#include "threads.c"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  system("clear");

  Thread *thread = initialisation();

  for (int i = 0; i < 10; i++) {
    threading(thread, i);
  }
  getThread(thread);

  for (int i = 0; i < 4; i++) {
    printf("The unthread element is: %d\n", unthread(thread));
  }
  getThread(thread);

  return 0;
}