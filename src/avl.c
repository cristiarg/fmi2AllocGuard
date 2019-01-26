#include "avl.h"
#include <stdlib.h>
//#include <stdio.h>

//
// internals
//

struct avl_node* avl_internal_new_node(void* _data)
{
  struct avl_node* new_node = (struct avl_node*)calloc(1, sizeof(struct avl_node));
  if (new_node != NULL) {
    new_node->data = _data;
    return new_node;
  }
  else {
    return NULL;
  }
}

struct avl_node* avl_internal_add(struct avl_node** _node, void* _data, avl_compare_func _compare_func)
{
  if (*_node == NULL) {
    *_node = avl_internal_new_node(_data);
    // pare remains null
    return *_node;
  }
  else {
    const int compare_res = _compare_func(_data, (*_node)->data);
    if (compare_res == -1) {
      if ((*_node)->left != NULL) {
        return avl_internal_add(&(*_node)->left, _data, _compare_func);
      }
      else {
        struct avl_node* new_node = avl_internal_new_node(_data);
        new_node->pare = *_node;
        (*_node)->left = new_node;
        return new_node;
      }
    }
    else if (compare_res == 1) {
      if ((*_node)->rite != NULL) {
        return avl_internal_add(&(*_node)->rite, _data, _compare_func);
      }
      else {
        struct avl_node* new_node = avl_internal_new_node(_data);
        new_node->pare = *_node;
        (*_node)->rite = new_node;
        return new_node;
      }
    }
    else {
      // data already in tree; cannot add
      return NULL;
    }
  }
}

// detach the ritemost node in a subtree supplied initially
//struct avl_node* avl_internal_detach_ritemost(struct avl_node* const _root, struct avl_node** const _detached)
//{
//  if (_root->rite != NULL) {
//    _root->rite = avl_internal_detach_ritemost(_root->rite, _detached);
//    return _root;
//  }
//  else {
//    // _root->rite is NULL
//    // _root is to be detached
//    struct avl_node* const saved_left_child = _root->left;
//    _root->left = NULL;
//    *_detached = _root;
//    return saved_left_child;
//  }
//}

// detach the leftmost node in a subtree supplied initially
struct avl_node* avl_internal_detach_leftmost(struct avl_node* const _root, struct avl_node** const _detached)
{
  if (_root->left != NULL) {
    _root->left = avl_internal_detach_leftmost(_root->left, _detached);
    return _root;
  }
  else {
    // _root->left is NULL
    // _root is to be detached
    struct avl_node* const saved_rite_child = _root->rite;
    _root->rite = NULL;
    if (saved_rite_child != NULL) {
      saved_rite_child->pare = _root->pare;
    }
    _root->pare = NULL;
    *_detached = _root;
    return saved_rite_child;
  }
}

struct avl_node* avl_internal_rem(
      struct avl_node* _node
    , void* _data
    , bool* const _found
    , avl_compare_func _compare_func
    , avl_clear_func _clear_func)
{
  if (_node == NULL) {
    *_found = false;
    return NULL;
  }
  else {
    const int compare_res = _compare_func(_data, _node->data);
    if (compare_res == -1) {
      _node->left = avl_internal_rem(_node->left, _data, _found, _compare_func, _clear_func);
      return _node;
    }
    else {
      if (compare_res == 1) {
        _node->rite = avl_internal_rem(_node->rite, _data, _found, _compare_func, _clear_func);
        return _node;
      }
      else {
        // _data == _node->data
        if (_node->left == NULL && _node->rite == NULL) {
          _clear_func(_node->data);
          free(_node);
          _node = NULL;
          *_found = true;
          return _node;
        }
        else if (_node->left != NULL && _node->rite == NULL) {
          // replace node with left subtree
          struct avl_node* const left_subtree = _node->left;
          _node->left = NULL;
          left_subtree->pare = _node->pare;
          _node->pare = NULL;
          _clear_func(_node->data);
          free(_node);
          *_found = true;
          return left_subtree;
        }
        else if (_node->left == NULL && _node->rite != NULL) {
          // replace node with rite subtree
          struct avl_node* const rite_subtree = _node->rite;
          _node->rite = NULL;
          rite_subtree->pare = _node->pare;
          _node->pare = NULL;
          _clear_func(_node->data);
          free(_node);
          *_found = true;
          return rite_subtree;
        }
        else {
          // both children are non NULL
          // TODO: just choose whichever is deepest
          struct avl_node* detached_leftmost_of_rite_subtree = NULL;
          struct avl_node* const remaining_rite_subtree = avl_internal_detach_leftmost(_node->rite, &detached_leftmost_of_rite_subtree);

          detached_leftmost_of_rite_subtree->left = _node->left;
          if (detached_leftmost_of_rite_subtree->left != NULL) {
            detached_leftmost_of_rite_subtree->left->pare = detached_leftmost_of_rite_subtree;
          }
          _node->left = NULL;

          detached_leftmost_of_rite_subtree->rite = remaining_rite_subtree;
          if (detached_leftmost_of_rite_subtree->rite != NULL) {
            detached_leftmost_of_rite_subtree->rite->pare = detached_leftmost_of_rite_subtree;
          }
          _node->rite = NULL;

          detached_leftmost_of_rite_subtree->pare = _node->pare;
          _node->pare = NULL;

          _clear_func(_node->data);
          free(_node);
          *_found = true;
          return detached_leftmost_of_rite_subtree;
        }
      }
    }
  }
}

int avl_internal_balance_factor(const struct avl_node* const _root)
{
  if (_root == NULL) {
    return 0;
  }
  else {
    const int left_dept = (_root->left != NULL) ? avl_depth(_root->left) : 0;
    const int rite_dept = (_root->rite != NULL) ? avl_depth(_root->rite) : 0;
    //printf(" [%d %d]", left_dept, rite_dept);
    const int diff = left_dept - rite_dept;
    if (diff <= -2) {
      // imbalance to the right
      // rotation needed
      return -1;
    }
    else if (diff >= 2) {
      // imbalance to the left
      // rotation needed
      return 1;
    }
    return 0;
  }
}

void avl_internal_nop(const struct avl_node* const _)
{
  if (_ != NULL) {
  }
}

struct avl_node* avl_internal_rotate_rite(struct avl_node* const _z)
{
  struct avl_node* const y = _z->left;
  struct avl_node* const T3 = y->rite;
  // re-attach T3 as left child of z
  _z->left = T3;
  if (T3 != NULL) {
    T3->pare = _z;
  }
  // re-attach z as rite child of y
  y->rite = _z;
  _z->pare = y;
  // y is the new root of the subtree received as param
  return y;
}

struct avl_node* avl_internal_rotate_left(struct avl_node* const _z)
{
  struct avl_node* const y = _z->rite;
  struct avl_node* const T2 = y->left;
  // re-attach T2 as rite child of z
  _z->rite = T2;
  if (T2 != NULL) {
    T2->pare = _z;
  }
  // re-attach z as left child of y
  y->left = _z;
  _z->pare = y;
  // y is the new root of the subtree received as param
  return y;
}

void avl_internal_balance(struct avl_node** const _root, const struct avl_node* _new_node)
{
  //printf("\n");
  const struct avl_node* x = _new_node;
        struct avl_node* y = (x != NULL && x->pare != NULL) ? x->pare : NULL;
        struct avl_node* z = (y != NULL && y->pare != NULL) ? y->pare : NULL;
  while (x != NULL && y != NULL && z != NULL) {
    const int z_balance_factor = avl_internal_balance_factor(z);
    if (z_balance_factor != 0) {

      // detach z from its parent
      // keep a pointer to its parent's child where the new root should be attached
      struct avl_node* const z_pare = z->pare;
      struct avl_node** const z_pare_child_to_reattach_to
          = (z_pare == NULL)
              ? NULL
              : (z == z_pare->left)
                  ? &z_pare->left
                  : &z_pare->rite;
      if (z_pare_child_to_reattach_to != NULL) {
        *z_pare_child_to_reattach_to = NULL;
      }
      z->pare = NULL;

      struct avl_node* new_z = NULL;
      if (y == z->left && x == y->left ) {
        // left left ==> rite rotate z

        // balance
        new_z = avl_internal_rotate_rite(z);

        //printf(" ==LL==");
      }
      else if (y == z->left && x == y->rite) {
        // left rite ==> left rotate y; rite rotate z 

        // left rotate y
        y->pare = NULL;
        z->left = avl_internal_rotate_left(y);
        z->left->pare = z;

        // rite rotate z
        new_z = avl_internal_rotate_rite(z);

        //printf(" ==LR==");
      }
      else if (y == z->rite && x == y->left) {
        // rite left ==> rite rotate y; left rotate z

        // rite rotate y
        y->pare = NULL;
        z->rite = avl_internal_rotate_rite(y);
        z->rite->pare = z;

        // left rotate z
        new_z = avl_internal_rotate_left(z);

        //printf(" ==RL==");
      }
      else if (y == z->rite && x == y->rite) {
        // rite rite ==> left rotate z

        // balance
        new_z = avl_internal_rotate_left(z);

        //printf(" ==RR==");
      }
      else {
        //printf(" ==RETURN");
        return;
      }

      // re-attach
      if (z_pare_child_to_reattach_to != NULL) {
        *z_pare_child_to_reattach_to = new_z;
      }
      new_z->pare = z_pare;
      // if z was the root, new_z sould be the new root
      if (z_pare == NULL) {
        *_root = new_z;
      }
      // new_z is balanced, upwards is balanced too

      break;
    }
    else {
      // move one level up
      x = y;
      y = z;
      z = (z->pare != NULL) ? z->pare : NULL;
    }
  }

  // post conditions
  //if (x != NULL) {
  //  const int x_balance_factor = avl_internal_balance_factor(x);
  //  if (x_balance_factor != 0) {
  //    avl_internal_nop(x);
  //  }
  //}
  //if (y != NULL) {
  //  const int y_balance_factor = avl_internal_balance_factor(y);
  //  if (y_balance_factor != 0) {
  //    avl_internal_nop(y);
  //  }
  //}
  //if (z != NULL) {
  //  const int z_balance_factor  = avl_internal_balance_factor(z);
  //  if (z_balance_factor != 0) {
  //    avl_internal_nop(z);
  //  }
  //}
}

//
// public
//

bool avl_add(struct avl_node** const _root, void* _data, avl_compare_func _compare_func)
{
  const struct avl_node* new_node = avl_internal_add(_root, _data, _compare_func);
  avl_internal_balance(_root, new_node);
  return (new_node != NULL);
}

bool avl_rem(struct avl_node** const _root, void* _data
    , avl_compare_func _compare_func, avl_clear_func _clear_func)
{
  bool found = false;
  *_root = avl_internal_rem(*_root, _data, &found, _compare_func, _clear_func);
  return found;
}

bool avl_find(const struct avl_node* const _root, void* _data, avl_compare_func _compare_func)
{
  // non-recursive
  const struct avl_node* l_root = _root;
  while (l_root != NULL) {
    const int compare_res = _compare_func(_data, l_root->data);
    if (compare_res == -1) {
      l_root = l_root->left;
    }
    else if (compare_res == 1) {
      l_root = l_root->rite;
    }
    else if (compare_res == 0) {
      return true;
    }
  }
  return false;
}

int avl_size(const struct avl_node* const _root)
{
  if (_root == NULL) {
    return 0;
  }
  else {
    const int left_child_size
        = (_root->left == NULL)
          ? 0
          : avl_size(_root->left);
    const int rite_child_size
        = (_root->rite == NULL)
          ? 0
          : avl_size(_root->rite);
    return left_child_size + 1 + rite_child_size;
  }
}

int avl_depth(const struct avl_node* const _root)
{
  if (_root == NULL) {
    return 0;
  }

  int max_depth = 0;

  #define STACK_MAX_SIZE 1000
  struct stack_elem {
    const struct avl_node*  node;
    int                     dept;
  } stack[STACK_MAX_SIZE];
  int stack_next_index = 0;

  stack[stack_next_index  ].node = _root;
  stack[stack_next_index++].dept = 1;

  while (stack_next_index > 0) {
    // remove the top of the stack
    struct stack_elem top = stack[--stack_next_index];
    if (top.dept > max_depth) {
      max_depth = top.dept;
    }

    if (top.node->left != NULL) {
      stack[stack_next_index  ].node = top.node->left;
      stack[stack_next_index++].dept = top.dept + 1;
        // TODO: check stack_next_index againt max constant or make dynamic
    }

    if (top.node->rite != NULL) {
      stack[stack_next_index  ].node = top.node->rite;
      stack[stack_next_index++].dept = top.dept + 1;
        // TODO: check stack_next_index againt max constant or make dynamic
    }
  }

  return max_depth;
}

int avl_clear(struct avl_node** const _root, avl_clear_func _clear_func)
{
  int count = 0;
  struct avl_node* curr = *_root;
  while (curr != NULL) {
    // recurse left
    if (curr->left != NULL) {
      curr = curr->left;
      continue;
    }

    // recurse rite
    if (curr->rite != NULL) {
      curr = curr->rite;
      continue;
    }

    // neither left nor rite children
    struct avl_node* pare = curr->pare;
    if (pare != NULL) {
      if (pare->left == curr) {
        // left child of parent
        pare->left = NULL;
      }
      else if (pare->rite == curr) {
        // rite child of parent
        pare->rite = NULL;
      }
      else {
        // should not happen
        return - 1;
      }
    }
    if (curr != NULL) { // check to please static analyser
      _clear_func(curr->data);
      free(curr);
      ++count;
    }
    curr = pare;
  }

  *_root = curr;

  return count;
}

