#include "../heap/heap.h"

typedef struct content {
  uint32_t val;
} content_t;

content_t * create_content(uint32_t val) {
  content_t * c = calloc(1, sizeof(content_t));
  c->val = val;
  return c;
}

int8_t cmp(const void * a, const void * b) {
  int a1 = *((int *)a);
  int b1 = *((int *)b);

  return (a1 > b1) ? 1 : (a1 < b1) ? -1 : 0;
}

void print_h(struct heap_node * p) {
  if (p == NULL) 
    return;

  printf("%d\n", ((content_t *)p->content)->val);
  print_h(p->left);
  print_h(p->right);

}

int main(int argc, char ** argv) {
  struct heap * h = h_init(cmp, MIN_HEAP);

  for(int i = 11; i >= 0; i--) {
    h_insert(h, create_content(i));
  }

    print_h(h->root);
  while(1) {
    struct heap_node * p = h_remove(h);
    if (p == NULL) 
      break;

    printf("got: %d\n", *(int *)p->content);
    print_h(h->root);
  }



  return 0;
}
