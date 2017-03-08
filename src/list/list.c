#include "list.h"

uint8_t l_add(struct list * list_p, void * content) {

  struct list_node * n = calloc(1, sizeof(struct list_node));

  if (n == NULL)
    return EMEMORY;

  n->content = content;
  list_p->tail = n;

  if (!list_p->l_size) {
    list_p->head = n;
  } else {
    struct list_node * p = list_p->head;
    
    while(p->next) 
       p = p->next;
    
    n->prev = p;
    p->next = n;
  }

  list_p->l_size++;

  return SUCCESS;
}

uint8_t l_remove(struct list * list_p, uint32_t position) {
  struct list_node * p = l_get(list_p, position);

  if (p == NULL)
    return EERROR;

  /* if the prev element is present then we update its next element
     if the prev element is not present it means this was the head of 
     the list so we update it */
  if (p->prev)
    p->prev->next = p->next;
  else 
    list_p->head = p->next;

  /* if the next element is present then we update its prev element
     if the next element is not present it means this was the tail of 
     the list so we update it */
  if (p->next)
    p->next->prev = p->prev;
  else
    list_p->tail = p->prev;

  free(p->content);
  free(p);

  list_p->l_size--;

  return SUCCESS;
}

/* gets the item at the nth position of the list */
struct list_node * l_get(struct list * list_p, uint32_t position) {
  struct list_node * p = list_p->head;

  if (position > list_p->l_size)
    return NULL;

  while(position--)
    p = p->next;

  return p;
}


/* frees the list - attention the content of each node is not free'd */
/* user is responsible to free that memory */
void l_free(struct list * list_p, bool free_content) {
  while(list_p->head != NULL) 
    l_remove(list_p, 0);
}

/* tries to free the content of every list node - can be used at will */
/* if the content is supposed (and able) to be freed */
void q_free_content(struct list * list_p) {
  struct list_node * p = list_p->head;
  while(p != NULL) {
    free(p->content);
    p = p->next;
  }
}
