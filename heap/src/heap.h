#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define SUCCESS    0
#define ECMPFUN   -1
#define EINVHEA   -2

typedef struct node {
  void * content;
  struct node * left;
  struct node * right;
} heap_node_t;

// heap type structure, it holds the root node and a function pointer that should
// be able to compare to 2 nodes. The function must return -1, 0 or 1 if arg1 is
// lesser, equal or greater to arg2.
typedef struct heap {
  bool (*cmp_func)(const void *, const void *);
  heap_node_t * root;
} heap_t;

// creates the heap and sets the comparison function - it should be the only way
// to initialize the heap
extern heap_t * h_init(bool (*cmp_func)(const void *, const void *));

// insert content into the given heap
extern uint8_t h_insert(const heap_t * heap, const void * content);

// removes the min of the heap, the node is not freed, it should be freed by the user
extern heap_node_t * h_remove_min(const heap_t * heap);

// returns the min of the heap
extern heap_node_t * h_find_min(const heap_t * heap); 

// merge heap_t h1 and heap_t h2 into a new heap
extern heap_t merge(const heap_t * h1, const heap_t * h2);


#endif /* HEAP_H */
