#include "heap.h"

typedef struct content {
  uint32_t val;
} content_t;

content_t * create_content(uint32_t val) {
  content_t * c = calloc(1, sizeof(content_t));
  c->val = val;
  return c;
}

bool cmp(const void * a, const void * b) {
  int a1 = *((int *)a);
  int b1 = *((int *)b);

  return (a1 > b1) ? 1 : (a1 < b1) ? -1 : 0;
}

void print_h(struct heap_node * p) {
  if (p == NULL) 
    return;
  print_h(p->left);
  print_h(p->right);
  printf("%d\n", ((content_t *)p->content)->val);
}

int main(int argc, char ** argv) {
  struct heap * h = h_init(cmp, MAX_HEAP);

  for(int i = 11; i >= 0; i--) {
    h_insert(h, create_content(i));
  }

  print_h(h->root);

  return 0;
}
