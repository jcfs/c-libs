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
struct queue_node {
  void * content;
  struct queue_node * next;
};

struct queue {
  struct queue_node * head;
  struct queue_node * tail;
  uint32_t q_size;
};

// adds a new item to the queue containing the content
extern uint8_t q_enqueue(struct queue *, void * content);

// remove the next time of the queue and returns it
// the node returned is not freed (obviously), so it must be freed
// by the user
extern struct queue_node * q_dequeue(struct queue *);

// get the element at the front of the queue without removing it
extern struct queue_node * q_peek(struct queue *);

// checks if the queue is empty
extern bool q_empty(struct queue *);

// returns the current size of the queue
extern uint32_t q_get_size(struct queue *);

// frees the queue - attention the content of each node is not free'd
// user is responsible to free that memory
extern void q_free(struct queue *, bool free_content);

// tries to free the content of every queue node - can be used at will
// if the content is supposed (and able) to be freed 
extern void q_free_content(struct queue *);

#endif /* QUEUE_H */
