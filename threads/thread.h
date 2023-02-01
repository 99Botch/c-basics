#ifndef H_THREAD
#define H_THREAD

typedef struct Element Element;
struct Element {
  int number;
  Element *next;
};

typedef struct Thread Thread;
struct Thread {
  Element *first;
};

Thread *initialisation();
void getThread(Thread *_thread);
void threading(Thread *_thread, int _newNmb);
int unthread(Thread *_thread);
#endif