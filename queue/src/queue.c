#include "queue.h"

// adds a new item to the queue containing the content
uint8_t q_enqueue(queue_t * queue, void * content) {
  queue_node_t * n = calloc(1, sizeof(queue_node_t));

  if (n == NULL) 
    return EMEMORY;

  n->content = content;

  if (queue->head == NULL) {
    queue->head = queue->tail = n;
  } else {
    queue->tail = (queue->tail->next = n);
  }

  queue->q_size++;

  return SUCCESS;
}

// remove the next time of the queue and returns it     
// the node returned is not freed (obviously), so it must be freed
// by the user
queue_node_t * q_dequeue(queue_t * queue) {
  if (queue->head != NULL) {
    queue_node_t * ret = queue->head;
    queue->head = queue->head->next;
    queue->q_size--;
    return ret;
  }

  return NULL;
}

// get the element at the front of the queue without removing it 
queue_node_t * q_peek(queue_t * queue) {
  return queue->head ? queue->head : NULL;
}

// checks if the queue is empty
bool q_empty(queue_t * queue) {
  return queue->head == NULL;
}

// returns the current size of the queu
uint32_t q_get_size(queue_t * queue) {
  return queue->q_size;
}

// frees the queue - attention the content of each node is not free'd
// user is responsible to free that memory
void q_free(queue_t * queue, bool free_content) {
  while(queue->head != NULL) {
    queue_node_t * p = q_dequeue(queue);

    if (free_content)
      free(p->content);

    free(p);
  }
}

// tries to free the content of every queue node - can be used at will
// if the content is supposed (and able) to be freed
void q_free_content(queue_t * queue) {
  queue_node_t * p = queue->head;
  while(p != NULL) {
    free(p->content);
    p = p->next;
  }
}
