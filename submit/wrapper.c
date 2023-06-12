#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"
#include "mmu.h"

// implement wrapper functions for homework here
int thread_create(void (*func)(void *, void *), void* arg1, void* arg2)
{
  void* stack;
  // allocate from this wrapper
  stack = malloc(PGSIZE);

  return clone(func, arg1, arg2, stack);
}

int thread_join()
{
  void * stackPtr;
  int x = join(&stackPtr);
  return x;
}