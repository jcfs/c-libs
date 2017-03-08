#include <stdio.h>
#include <stdlib.h>
#include "../list/list.h"

typedef struct content {
  uint32_t val;
} content_t;

content_t * create_content(uint32_t val) {
  content_t * c = calloc(1, sizeof(content_t));
  c->val = val;
  return c;
}

int main(int argc, char ** argv) {
  struct list q1;
  q1.l_size = 0;

  for(int i = 0; i < 15; i++) {
    l_add(&q1, create_content(i * 100));
    printf("added %d\n", i);
  }  

  for(int i = 0; i < 15; i++)
    printf("item   %5d - l_size %3d\n", ((content_t *)((struct list_node *)l_get(&q1, i)->content))->val, q1.l_size);

  for(int i = 0; i < 15; i++) 
    printf("removed   %5d - l_size %3d\n", l_remove(&q1, 0), q1.l_size);

  l_free(&q1, true);
  return 0;
}
