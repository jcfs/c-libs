#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define SUCCESS    0
#define ECMPFUN   -1
#define EINVHEA   -2

struct node {
  void * content;
  struct node * left;
  struct node * right;
};

typedef enum { MIN_HEAP, MAX_HEAP } heap_type_t;

// heap type structure, it holds the root node and a function pointer that should
// be able to compare to 2 nodes. The function must return -1, 0 or 1 if arg1 is
// lesser, equal or greater to arg2.
struct heap {
  bool (*cmp_func)(const void *, const void *);
  struct node * root;
  struct node * tail;
  heap_type_t type;
};

// creates the heap and sets the comparison function - it should be the only way
// to initialize the heap
extern struct heap * h_init(bool (*cmp_func)(const void *, const void *), heap_type_t type);

// insert content into the given heap
extern uint8_t h_insert(const struct heap * heap, const void * content);

// removes the min of the heap, the node is not freed, it should be freed by the user
extern struct node * h_remove_min(const struct heap * heap);

// returns the min of the heap
extern struct node * h_find_min(const struct heap * heap); 

// merge struct heap h1 and struct heap h2 into a new heap
extern struct heap merge(const struct heap * h1, const struct heap * h2);


#endif /* HEAP_H */
