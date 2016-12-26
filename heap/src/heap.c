#include "heap.h"

// creates the heap and sets the comparison function - it should be the only way
// to initialize the heap
struct heap * h_init(bool (*cmp_func)(const void *, const void *), heap_type_t type) {
  struct heap * heap = calloc(1, sizeof(struct heap));

  if (heap == NULL) {
    // error in memory allocation... woot
    return NULL;
  }

  heap->cmp_func = cmp_func;
  heap->type = type;
  
  return heap;
}
