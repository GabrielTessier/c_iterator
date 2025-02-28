
#include <stdint.h>

#include "iterator.h"

void* next(iterator_t* iterator) {
  iterator->nip = &&next_return;
  push(iterator);
  unsafe_jumpto(iterator->fip);
next_return:
  return iterator->ret;
}



