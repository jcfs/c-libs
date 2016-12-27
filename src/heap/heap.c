#include "heap.h"
#include "../queue/queue.h"

/* static functions declaration */
static void _swap(struct heap_node *, struct heap_node *);
static int8_t _cntcmp(struct heap *, const void *, const void *);
static struct heap_node * find_tail_node(struct heap *);

/* creates the heap and sets the comparison function - it should be the only way */
/* to initialize the heap */
struct heap * h_init(int8_t (*cmp_func)(const void *, const void *), enum heap_type_t type) {
  struct heap * heap = calloc(1, sizeof(struct heap));

  if (heap == NULL) 
    return NULL;

  heap->cmp_func = cmp_func;
  heap->type = type;

  return heap;
}

uint8_t h_insert(struct heap * heap, void * content) {
  struct heap_node * n = calloc(1, sizeof(struct heap_node));

  if (n == NULL) 
    return EMEMERR;

  n->content = content;

  if (heap->root == NULL) {
    heap->root = n;
    return SUCCESS;
  }

  heap->tail = find_tail_node(heap);

  if (heap->tail->left == NULL) {
    heap->tail->left = n;
  } else {
    heap->tail->right = n;
  }

  n->parent = heap->tail;

  while(n->parent != NULL) {
    if (_cntcmp(heap, n->content, n->parent->content) > 0) {
      _swap(n->parent, n);
      n = n->parent;
    } else {
      break;
    }

  }

  return SUCCESS;
}

/************************************
  static functions implementation 
 *************************************/

/* 
   Swaps two nodes (parent and child)
   notice - the nodes aren't actually swapped, just the content is 
   (much easier and less messy this way) 
 */
static void _swap(struct heap_node * parent, struct heap_node * child) {
  void * tmp_content = child->content;
  child->content = parent->content;
  parent->content = tmp_content;  
}

/* 
   wrapper around the cmp function of the heap, it inverts the logic
   if it is a MAX_HEAP instead of a MIN_HEAP 
 */
static int8_t _cntcmp(struct heap * heap, const void * a, const void *b) {
  int8_t cmp = heap->cmp_func(a, b);

  if (heap->type == MAX_HEAP)
    cmp *= -1; 

  return cmp;
}

/* 
   BFS to find the first node that does not have both
   children - it means this is the current tail of the tree 
 */
static struct heap_node * find_tail_node(struct heap * heap) {
  struct queue q;
  struct heap_node * n;

  q_enqueue(&q, heap->root);

  while(!q_empty(&q)) {
    n = q_dequeue(&q)->content;

    if (n->left == NULL || n->right == NULL) 
      break;

    q_enqueue(&q, n->left);
    q_enqueue(&q, n->right);
  }  

  q_free(&q, false);

  return n;
}


