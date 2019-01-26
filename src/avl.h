#ifndef AVL_H
#define AVL_H

#include <stddef.h>
#include <stdbool.h>

//#ifdef FMI2AG_COMPILE_FOR_UNITTEST
//# ifdef __cplusplus
//extern "C" {
//# endif
//#endif
  // needed for unit testing

struct avl_node;

struct avl_node {
  void* data;

  struct avl_node* left;
  struct avl_node* rite;

  struct avl_node* pare;
};

typedef void (*avl_clear_func)(void* _data);
typedef int(*avl_compare_func)(const void* const _left, const void* const _rite);

bool avl_add(struct avl_node** const _root, void* _data, avl_compare_func _compare_func);
bool avl_rem(struct avl_node** const _root, void* _data, avl_compare_func _compare_func, avl_clear_func _clear_func);

bool avl_find(const struct avl_node* const _root, void* _data, avl_compare_func _compare_func);

int avl_size(const struct avl_node* const _root);
int avl_depth(const struct avl_node* const _root);

int avl_clear(struct avl_node** const _root, avl_clear_func _clear_func);

//#ifdef FMI2AG_COMPILE_FOR_UNITTEST
//# ifdef __cplusplus
//} // extern "C"
//# endif
//#endif

#endif
