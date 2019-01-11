#include "avl.h"
#include <stdlib.h>

//
// internals
//

struct avl_node* avl_internal_new_node(const int _data)
{
  struct avl_node* new_node = (struct avl_node*)calloc(1, sizeof(struct avl_node));
  new_node->data = _data;
  return new_node;
}

bool avl_internal_add(struct avl_node** _node, const int _data)
{
  if (*_node == NULL) {
    *_node = avl_internal_new_node(_data);
    // pare remains null
    return true;
  }
  else {
    if (_data < (*_node)->data) {
      if ((*_node)->left != NULL) {
        return avl_internal_add(&(*_node)->left, _data);
      }
      else {
        struct avl_node* new_node = avl_internal_new_node(_data);
        new_node->pare = *_node;
        (*_node)->left = new_node;
        return true;
      }
    }
    else if ((*_node)->data < _data) {
      if ((*_node)->rite != NULL) {
        return avl_internal_add(&(*_node)->rite, _data);
      }
      else {
        struct avl_node* new_node = avl_internal_new_node(_data);
        new_node->pare = *_node;
        (*_node)->rite = new_node;
        return true;
      }
    }
    else {
      // data already in tree; cannot add
      return false;
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

struct avl_node* avl_internal_rem(struct avl_node* _node, const int _data, bool* const _found)
{
  if (_node == NULL) {
    *_found = false;
    return NULL;
  }
  else {
    if (_data < _node->data) {
      _node->left = avl_internal_rem(_node->left, _data, _found);
      return _node;
    }
    else {
      if (_node->data < _data) {
        _node->rite = avl_internal_rem(_node->rite, _data, _found);
        return _node;
      }
      else {
        // _data == _node->data
        if (_node->left == NULL && _node->rite == NULL) {
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

          free(_node);
          *_found = true;
          return detached_leftmost_of_rite_subtree;
        }
      }
    }
  }
}

//
// public
//

bool avl_add(struct avl_node** const _root, const int _data)
{
  const bool res_add = avl_internal_add(_root, _data);
  return res_add;
}

bool avl_rem(struct avl_node** const _root, const int _data)
{
  bool found = false;
  *_root = avl_internal_rem(*_root, _data, &found);
  return found;
}

bool avl_find(const struct avl_node* const _root, const int _data)
{
  // non-recursive
  const struct avl_node* l_root = _root;
  while (l_root != NULL) {
    if (_data < l_root->data) {
      l_root = l_root->left;
    }
    else if (l_root->data < _data) {
      l_root = l_root->rite;
    }
    else if (l_root->data == _data) {
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

  static const int STACK_MAX_SIZE = 10000;
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
    }

    if (top.node->rite != NULL) {
      stack[stack_next_index  ].node = top.node->rite;
      stack[stack_next_index++].dept = top.dept + 1;
    }
  }

  return max_depth;
}

int avl_clear(struct avl_node** const _root)
{
  int count = 0;
  struct avl_node* curr = *_root;
  while (curr != NULL) {
    // recurse left all the way
    if (curr->left != NULL) {
      curr = curr->left;
      continue;
    }

    // recurse rite all the way
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
    free(curr);
    ++count;
    curr = pare;
  }

  *_root = curr;

  return count;
}

