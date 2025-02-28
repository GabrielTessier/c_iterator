
#include <stdlib.h>
#include <stdint.h>
#include "iterator.h"

iterator_t *range(int a, int b) {
  void *data = malloc(sizeof(int) * 2);
  int *di = (int *)data;
  int *db = (int *)(data + sizeof(int));
  *di = a;
  *db = b;
  iterator_t* iter = (iterator_t*)malloc(sizeof(iterator_t));
  iter->data = data;
  iter->fip = &&range_i;
  iter->nip = NULL;
  iter->ret = NULL;
  unsafe_jumpto(&&end);

  iterator_t *iterator_range;
 range_i:
  pop(iterator_range);
  int *iterator_di = (int *)iterator_range->data;
  int *iterator_db = (int *)(iterator_range->data + sizeof(int));
  if (*iterator_di > *iterator_db) iterator_range->ret = NULL;
  else iterator_range->ret = (void*) (intptr_t) *(int*)iterator_range->data;
  (*iterator_di)++;
  iterator_range->fip = &&range_i;
  unsafe_jumpto(iterator_range->nip);

 end:
  return iter;
}
