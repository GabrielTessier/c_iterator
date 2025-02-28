
#ifndef ITERATOR_H
#define ITERATOR_H

#define unsafe_jumpto(a) asm("jmp *%0" ::"r"(a) :)
#define push(a) asm("push %0" ::"r"(a));
#define pop(a) asm("pop %0" ::"m"(a));

struct iterator_s {
  void *data;
  void *nip;
  void *fip;
  void *ret;
};
typedef struct iterator_s iterator_t;

void *next(iterator_t *iterator);

#endif // ITERATOR_H
