
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "iterator.h"
#include "range.h"

int main(int argc, char **argv) {
  if (argc != 3)
    return 0;
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  iterator_t *r = range(a, b);
  while (next(r)) {
    printf("%ld, ", (intptr_t)r->ret);
  }
  printf("\n");
  return 0;
}
