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

typedef struct heap {
  bool (*cmp_func)(void * ca, void * cb);
  head_node_t * root;
} heap_t;

extern heap_t * h_init(bool (*cmp_func)(void * ca, void * cb));
extern uint8_t h_insert(heap_t * heap, void * content);
extern heap_node_t * h_remove_min(heap_t * heap);
extern heap_node_t * h_find_min(heap_t * heap); 


#endif /* HEAP_H */
