#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS    0
#define EMEMORY   -1
#define EEMPTY    -2

// queue element node
typedef struct node {
  void * content;
  struct node * next;
} node_t;

// adds a new item to the queue containing the content
extern uint8_t q_enqueue(void * content);

// remove the next time of the queue and returns it
// the node returned is not freed (obviously), so it must be freed
// by the user
extern node_t * q_dequeue();

// get the element at the front of the queue without removing it
extern node_t * q_peek();

// checks if the queue is empty
extern bool q_empty();

// returns the current size of the queue
extern uint32_t q_get_size();

// frees the queue - attention the content of each node is not free'd
// user is responsible to free that memory
extern void q_free(bool free_content);

// tries to free the content of every queue node - can be used at will
// if the content is supposed (and able) to be freed 
extern void q_free_content();

#endif /* QUEUE_H */
