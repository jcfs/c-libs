#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define SUCCESS    0
#define ECMPFUN   -1
#define EINVHEA   -2
#define EMEMERR   -3

struct heap_node {
  void * content;
  struct heap_node * parent;
  struct heap_node * left;
  struct heap_node * right;
};

/* enum to the heap type (min or max heap) */
enum heap_type_t { MIN_HEAP, MAX_HEAP };

/* heap type structure, it holds the root heap_node and a function pointer that should 
   be able to compare to 2 heap_nodes. The function must return -1, 0 or 1 if arg1 is 
   lesser, equal or greater than arg2. */
struct heap {
  bool (*cmp_func)(const void *, const void *);
  uint32_t heap_size;
  struct heap_node * root;
  struct heap_node * tail;
  enum heap_type_t type;
};

/* creates the heap and sets the comparison function - it should be the only way 
   to initialize the heap */
extern struct heap * h_init(bool (*cmp_func)(const void *, const void *), enum heap_type_t type);

/* insert content into the given heap */
extern uint8_t h_insert(struct heap * heap, void * content);

/* removes the nex value of the heap (min if it is a MIN_HEAP, max if it is a MAX_HEAP), 
   the heap_node is not freed, it should be freed by the user */
extern struct heap_node * h_remove(const struct heap * heap);

/* returns the min of the heap */
extern struct heap_node * h_find(const struct heap * heap); 

/* merge struct heap h1 and struct heap h2 into a new heap */
extern struct heap merge(const struct heap * h1, const struct heap * h2);

#endif /* HEAP_H */
