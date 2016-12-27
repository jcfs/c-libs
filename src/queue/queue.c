#include "queue.h"

/* adds a new item to the queue containing the content */
uint8_t q_enqueue(struct queue * queue_p, void * content) {
  struct queue_node * n = calloc(1, sizeof(struct queue_node));

  if (n == NULL) 
    return EMEMORY;

  n->content = content;

  if (!queue_p->q_size) {
    queue_p->head = (queue_p->tail = n);
  } else {
    queue_p->tail = (queue_p->tail->next = n);
  }

  queue_p->q_size++;

  return SUCCESS;
}

/* remove the next time of the queue and returns it      */
/* the node returned is not freed (obviously), so it must be freed */
/* by the user */
struct queue_node * q_dequeue(struct queue * queue_p) {
  if (queue_p->head != NULL) {
    struct queue_node * ret = queue_p->head;
    queue_p->head = queue_p->head->next;
    queue_p->q_size--;
    return ret;
  }

  return NULL;
}

/* get the element at the front of the queue without removing it  */
struct queue_node * q_peek(struct queue * queue_p) {
  return queue_p->head ? queue_p->head : NULL;
}

/* checks if the queue is empty */
bool q_empty(struct queue * queue_p) {
  return queue_p->head == NULL;
}

/* returns the current size of the queu */
uint32_t q_get_size(struct queue * queue_p) {
  return queue_p->q_size;
}

/* frees the queue - attention the content of each node is not free'd */
/* user is responsible to free that memory */
void q_free(struct queue * queue_p, bool free_content) {
  while(queue_p->head != NULL) {
    struct queue_node * p = q_dequeue(queue_p);

    if (p != NULL) {
      if (free_content)
        free(p->content);
      free(p);
    }
  }
}

/* tries to free the content of every queue node - can be used at will */
/* if the content is supposed (and able) to be freed */
void q_free_content(struct queue * queue_p) {
  struct queue_node * p = queue_p->head;
  while(p != NULL) {
    free(p->content);
    p = p->next;
  }
}
