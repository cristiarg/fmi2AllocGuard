#ifndef AVL_H
#define AVL_H

#include <stddef.h>
#include <stdbool.h>

#ifdef FMI2AG_COMPILE_FOR_UNITTEST
# ifdef __cplusplus
extern "C" {
# endif
#endif
  // needed for unit testing

struct avl_node;

struct avl_node {
  int data;

  struct avl_node* left;
  struct avl_node* rite;

  struct avl_node* pare;
};

bool avl_add(struct avl_node** const _root, const int _data);
bool avl_rem(struct avl_node** const _root, const int _data);

bool avl_find(const struct avl_node* const _root, const int _data);

int avl_size(const struct avl_node* const _root);
int avl_depth(const struct avl_node* const _root);

int avl_clear(struct avl_node** const _root);

#ifdef FMI2AG_COMPILE_FOR_UNITTEST
# ifdef __cplusplus
} // extern "C"
# endif
#endif

#endif
