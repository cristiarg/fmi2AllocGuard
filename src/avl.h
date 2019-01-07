#ifndef AVL_H
#define AVL_H

#include <stddef.h>
#include <stdbool.h>

struct avl_node;

struct avl_node {
  int data;
  struct avl_node* left;
  struct avl_node* rite;
};

bool avl_add(struct avl_node** const _root, const int _data );
bool avl_rem(struct avl_node** const _root, const int _data );

bool avl_check(const struct avl_node* const _root);

int avl_size(const struct avl_node* const _root);

#endif
