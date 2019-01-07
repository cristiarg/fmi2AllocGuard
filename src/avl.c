#include "avl.h"
#include <stdlib.h>

//
// internals
//

bool avl_internal_add(struct avl_node** _node, const int _data)
{
  if (*_node == NULL) {
    *_node = (struct avl_node*)calloc(1, sizeof(struct avl_node));
    (*_node)->data = _data;
    return true;
  }
  else {
    if ((*_node)->data < _data) {
      return avl_internal_add(&(*_node)->rite, _data);
    }
    else {
      if (_data < (*_node)->data) {
        return avl_internal_add(&(*_node)->left, _data);
      }
      else {
        return false;
      }
    }
  }
}

// detach the ritemost node in a subtree supplied initially
struct avl_node* avl_internal_detach_ritemost(struct avl_node* const _root, struct avl_node** const _detached)
{
  if (_root->rite != NULL) {
    _root->rite = avl_internal_detach_ritemost(_root->rite, _detached);
    return _root;
  }
  else {
    // _root->rite is NULL
    // _root is to be detached
    struct avl_node* const saved_left_child = _root->left;
    _root->left = NULL;
    *_detached = _root;
    return saved_left_child;
  }
}

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
          free(_node);
          *_found = true;
          return left_subtree;
        }
        else if (_node->left == NULL && _node->rite != NULL) {
          // replace node with rite subtree
          struct avl_node* const rite_subtree = _node->rite;
          _node->rite = NULL;
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
          _node->left = NULL;
          detached_leftmost_of_rite_subtree->rite = remaining_rite_subtree;
          _node->rite = NULL;
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

bool avl_check(const struct avl_node* const _root)
{
  if (_root != NULL) {
    const bool left_ok      = (_root->left == NULL) || avl_check(_root->left);

    const bool left_lt_root = (_root->left == NULL) || (_root->left->data < _root->data);
    const bool root_lt_rite = (_root->rite == NULL) || (_root->data < _root->rite->data);

    const bool rite_ok      = (_root->rite == NULL) || avl_check(_root->rite);

    return (left_ok && left_lt_root && root_lt_rite && rite_ok);
  }
  else {
    return true;
  }
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
