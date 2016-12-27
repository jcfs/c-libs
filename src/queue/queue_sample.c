#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct content {
  uint32_t val;
} content_t;

content_t * create_content(uint32_t val) {
  content_t * c = calloc(1, sizeof(content_t));
  c->val = val;
  return c;
}

int main(int argc, char ** argv) {
  struct queue q1;
  struct queue q2;

  for(int i = 0; i < 15; i++) {
    q_enqueue(&q1, create_content(i));
    q_enqueue(&q2, create_content(i * 100));
  }  

  printf("Enqueued\n");
  printf("peek    %5d - q_size %3d\n", ((content_t *)q_peek(&q1)->content)->val, q_get_size(&q1));
  printf("dequeue %5d - q_size %3d\n", ((content_t *)q_dequeue(&q1)->content)->val, q_get_size(&q1));
  printf("peek    %5d - q_size %3d\n", ((content_t *)q_peek(&q1)->content)->val, q_get_size(&q1));

  q_free(&q1, true);  
  printf("empty   %5d - q_size %3d\n", q_empty(&q1), q_get_size(&q1));

  for(int i = 0; i < 15; i++) {
    printf("dequeue %5d - q_size %3d\n", ((content_t *)q_dequeue(&q2)->content)->val, q_get_size(&q2));
  }

  q_free(&q2, true);
  printf("empty   %5d - q_size %3d\n", q_empty(&q2), q_get_size(&q2));
  return 0;
}
