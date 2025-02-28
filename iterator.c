
#include <stdlib.h>

#include "iterator.h"

void* next(iterator_t* iterator) {
  iterator->nip = &&next_return;
  push(iterator);
  unsafe_jumpto(iterator->fip);
next_return:
  return iterator->ret;
}

void free_iterator(iterator_t *iterator) {
  free(iterator->data);
  free(iterator);
}
