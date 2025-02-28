
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "iterator.h"
#include "number.h"
#include "range.h"

int main(int argc, char **argv) {
  if (argc != 3)
    return 0;
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  printf("range : \n");
  iterator_t *r = range(a, b);
  while (next(r)) {
    printf("%ld, ", (intptr_t)r->ret);
  }
  printf("\n");

  free(r->data);
  free(r);

  printf("number : \n");
  iterator_t *n = number();
  for (int i = 0; i < 30; i++) {
    printf("%ld, ", (intptr_t) next(n));
  }
  printf("\n");
  free(n->data);
  free(n);
  return 0;
}
