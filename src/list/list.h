#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS    0
#define EMEMORY   -1
#define EEMPTY    -2
#define EERROR    -3

/* list element node */
struct list_node {
  void * content;
  struct list_node * next;
  struct list_node * prev;
};

struct list {
  struct list_node * head;
  struct list_node * tail;
  uint32_t l_size;
};

/* adds an element to the nth position of the list */
extern uint8_t l_add(struct list *, void * content);

/* removes the item at the nth position of the list */
extern uint8_t l_remove(struct list *, uint32_t position);

/* gets the item at the nth position of the list */
extern struct list_node * l_get(struct list *, uint32_t position);

/* frees the list - attention the content of each node is not free'd */
/* user is responsible to free that memory */
extern void l_free(struct list *, bool free_content);

/* tries to free the content of every list node - can be used at will */
/* if the content is supposed (and able) to be freed  */
extern void l_free_content(struct list *);

#endif /* LIST_H */
