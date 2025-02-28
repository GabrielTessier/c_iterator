
#include <stdlib.h>
#include <stdint.h>
#include "iterator.h"

iterator_t *number() {
  void *data = malloc(sizeof(int));
  int *di = (int *)data;
  *di = 0;
  iterator_t* iter = (iterator_t*)malloc(sizeof(iterator_t));
  iter->data = data;
  iter->fip = &&number_1;
  iter->nip = NULL;
  iter->ret = NULL;
  unsafe_jumpto(&&end);

  iterator_t *iterator_number;
 number_1:
  pop(iterator_number);
  iterator_number->ret = (void *)(intptr_t)*(int *)iterator_number->data;
  iterator_number->fip = &&number_2;
  unsafe_jumpto(iterator_number->nip);

 number_2:
  pop(iterator_number);
  (*(int*)iterator_number->data)++;
  iterator_number->ret = (void *)(intptr_t)*(int *)iterator_number->data;
  iterator_number->fip = &&number_3;
  unsafe_jumpto(iterator_number->nip);

 number_3:
  pop(iterator_number);
  iterator_number->ret = (void *)(intptr_t)-*(int *)iterator_number->data;
  iterator_number->fip = &&number_2;
  unsafe_jumpto(iterator_number->nip);

 end:
  return iter;
}
