#include "queue.h"

static uint32_t q_size = 0;

// pointer to the head of the queue (first element to be dequeued)
static node_t * head = NULL;

// pointer to the tail of the queue (last element to be dequeued)
static node_t * tail = NULL;

// adds a new item to the queue containing the content
uint8_t q_enqueue(void * content) {
  node_t * n = malloc(sizeof(node_t));

  if (n == NULL) 
    return EMEMORY;

  n->content = content;

  if (head == NULL) {
    head = tail = n;
  } else {
    tail = (tail->next = n);
  }

  q_size++;
  return SUCCESS;
}

// remove the next time of the queue and returns it     
// the node returned is not freed (obviously), so it must be freed
// by the user
node_t * q_dequeue() {
  if (head != NULL) {
    node_t * ret = head;
    head = head->next;
    q_size--;
    return ret;
  }

  return NULL;
}

// get the element at the front of the queue without removing it 
node_t * q_peek() {
  return head ? head : NULL;
}

// checks if the queue is empty
bool q_empty() {
  return head == NULL;
}

// returns the current size of the queu
uint32_t q_get_size() {
  return q_size;
}

// frees the queue - attention the content of each node is not free'd
// user is responsible to free that memory
void q_free(bool free_content) {
  while(head != NULL) {
    node_t * p = q_dequeue();

    if (free_content)
      free(p->content);

    free(p);
  }
}

// tries to free the content of every queue node - can be used at will
// if the content is supposed (and able) to be freed
void q_free_content() {
  node_t * p = head;
  while(p != NULL) {
    free(p->content);
    p = p->next;
  }
}
