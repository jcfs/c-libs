#include "heap.h"

heap_t * h_init(bool (*cmp_func)(const void *, const void *)) {
  heap_t * heap = calloc(1, sizeof(heap_t));

  if (heap == NULL) {
    // error in memory allocation... woot
    return NULL;
  }

  heap->cmp_func = cmp_func;
  
  return heap;
}
