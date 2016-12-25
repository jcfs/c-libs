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

  for(int i = 500; i < 1000; i++) {
    q_enqueue(create_content(i));
  }  

  printf("peek    %d - q_size %d\n", ((content_t *)q_peek()->content)->val, q_get_size());
  printf("dequeue %d - q_size %d\n", ((content_t *)q_dequeue()->content)->val, q_get_size());
  printf("peek    %d - q_size %d\n", ((content_t *)q_peek()->content)->val, q_get_size());

  q_free(true);  
  printf("empty %d - q_size %d\n", q_empty(), q_get_size());

  return 0;
}
