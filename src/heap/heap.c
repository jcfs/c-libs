#include "heap.h"
#include "../queue/queue.h"

/* static functions declaration */
static void _swap_content(struct heap_node *, struct heap_node *);
static int8_t _cntcmp(struct heap *, const void *, const void *);
static struct heap_node * update_heap_tail(struct heap *);

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

  /* we update the heap tail */
  update_heap_tail(heap);

  if (heap->tail->left == NULL) {
    heap->tail->left = n;
  } else {
    heap->tail->right = n;
  }

  n->parent = heap->tail;

  while(n->parent != NULL) {
    if (_cntcmp(heap, n->content, n->parent->content) > 0) 
      _swap_content(n->parent, n);
    n = n->parent;
  }

  return SUCCESS;
}

struct heap_node * h_remove(struct heap * heap) {
  struct heap_node * ret_val = heap->root;
  struct heap_node * p = heap->tail;

  if (heap->root == NULL) 
    return NULL;

  if (p == heap->root) {
    heap->root = heap->tail = NULL;
    return ret_val;
  }

  /* remove the p node from the bottom  */
  if (p->parent->left == p) 
    p->parent->left = NULL;
  else 
    p->parent->right = NULL;

  /* assign it to root */
  p->left = ret_val->left;
  p->right = ret_val->right;
  
  if (p->left != NULL)
    p->left->parent = p;

  if (p->right != NULL)
    p->right->parent = p; 

  heap->root = p;

/*
   while(has_children(p)) {
   if (has_one_child(p)) {
    child = get_child(p);
    if (heap_property_broken(p, child)) {
      _swap(p, child);
    } 
    p = child;
    } else if (has_two_child(p)) {
      child = get_smallest_child(p);
      if (heap_property_broken(p, child)) {
        _swap(p, child);
      }
      p = child;
    }
   }

   while(p->right != NULL && p->left != NULL) {
   if (p->left != NULL && p->right == NULL) {
   if (_cntcmp(heap, p->content, p->left->content) > 0)
   _swap_content(p, p->left);
   p = p->left;
   } else if (p->right != NULL && p->left == NULL) {
   if (_cntcmp(heap, p->content, p->right->content) > 0)
   _swap_content(p, p->right);
   p = p->right;
   } else {
   if (_cntcmp(heap, p->right->content, p->left->content) > 0) {
   if (_cntcmp(heap, p->content, p->right->content) > 0)
   _swap_content(p, p->right);
   p = p->right;
   } else {
   if (_cntcmp(heap, p->content, p->left->content) > 0)
   _swap_content(p, p->left);
   p = p->left;
   } 
   }
   }
 */
  update_heap_tail(heap);

  return ret_val;
}

/************************************
  static functions implementation 
 *************************************/

/* 
   Swaps two nodes (parent and child)
   notice - the nodes aren't actually swapped, just the content is 
   (much easier and less messy this way) 
 */
static void _swap_content(struct heap_node * parent, struct heap_node * child) {
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
static struct heap_node * update_heap_tail(struct heap * heap) {
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

  heap->tail = n;
  return n;
}


