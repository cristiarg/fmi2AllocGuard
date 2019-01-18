#include "minunit.h"
#include "../src/avl.h"
//#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

void test_avl_clear_func(void* _data)
{
  // for testing, we're not using
  // actual allocated memory pointers, but reinterpreted ints
  if (_data != 0) {
    _data = 0;
  }
}

int test_avl_compare_func_lt(const void* const _left, const void* const _rite)
{
  if (_left < _rite )
    return -1;
  else if (_left > _rite)
    return 1;
  else
    return 0;
}

//int test_avl_compare_func_gt(const int _left, const int _rite)
//{
//  if (_left > _rite )
//    return -1;
//  else if (_left < _rite)
//    return 1;
//  else
//    return 0;
//}

bool test_98_check_order(const struct avl_node* const _root)
{
  if (_root != NULL) {
    const bool left_ok      = (_root->left == NULL) || test_98_check_order(_root->left);

    const bool left_lt_root = (_root->left == NULL) || (test_avl_compare_func_lt(_root->left->data, _root->data) == -1);
    const bool root_lt_rite = (_root->rite == NULL) || (test_avl_compare_func_lt(_root->data, _root->rite->data) == -1);

    const bool rite_ok      = (_root->rite == NULL) || test_98_check_order(_root->rite);

    return (left_ok && left_lt_root && root_lt_rite && rite_ok);
  }
  else {
    return true;
  }
}

void test_99_check_pare_consistency_recurse(const struct avl_node* const _root)
{
  if (_root != NULL) {
    if (_root->left != NULL) {
      mu_check(_root->left->pare == _root);
      test_99_check_pare_consistency_recurse(_root->left);
    }
    if (_root->rite != NULL) {
      mu_check(_root->rite->pare == _root);
      test_99_check_pare_consistency_recurse(_root->rite);
    }
  }
}

void test_99_check_pare_consistency_root(const struct avl_node* const _root)
{
  if (_root != NULL) {
    mu_check(_root->pare == NULL);
    test_99_check_pare_consistency_recurse(_root);
  }
}

MU_TEST(test_01_remove_from_empty)
{
  struct avl_node* root = { NULL };

  mu_check(avl_size(root) == 0);
  mu_check(avl_depth(root) == 0);

  mu_check(test_98_check_order(root) == true);

  mu_check(avl_rem(&root, (void*)10, test_avl_compare_func_lt, test_avl_clear_func) == false);

  mu_check(root == NULL);
  mu_check(avl_size(root) == 0);
}

MU_TEST(test_02_add_one_rem_one)
{
  struct avl_node* root = { NULL };

  mu_check(avl_size(root) == 0);

  mu_check(avl_add(&root, (void*)10, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)10, test_avl_compare_func_lt) == false);
  mu_check(avl_depth(root) == 1);
 
  mu_check(avl_size(root) == 1);

  mu_check(avl_rem(&root, (void*)11, test_avl_compare_func_lt, test_avl_clear_func) == false);

  mu_check(avl_size(root) == 1);

  mu_check(avl_rem(&root, (void*)10, test_avl_compare_func_lt, test_avl_clear_func) == true);
  mu_check(avl_rem(&root, (void*)10, test_avl_compare_func_lt, test_avl_clear_func) == false);
  mu_check(avl_depth(root) == 0);

  mu_check(root == NULL);
  mu_check(avl_size(root) == 0);
}

MU_TEST(test_03_add_two_one_in_left_child)
{
  struct avl_node* root = { NULL };

  mu_check(avl_add(&root, (void*)10, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)10, test_avl_compare_func_lt) == false);
  mu_check(avl_depth(root) == 1);

  mu_check(avl_add(&root, (void*)1, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)1, test_avl_compare_func_lt) == false);
  mu_check(avl_depth(root) == 2);

  mu_check(avl_size(root) == 2);

  mu_check(avl_rem(&root, (void*)10, test_avl_compare_func_lt, test_avl_clear_func) == true);
  mu_check(avl_rem(&root, (void*)10, test_avl_compare_func_lt, test_avl_clear_func) == false);
  mu_check(avl_depth(root) == 1);

  mu_check(avl_rem(&root, (void*)1, test_avl_compare_func_lt, test_avl_clear_func) == true);
  mu_check(avl_rem(&root, (void*)1, test_avl_compare_func_lt, test_avl_clear_func) == false);
  mu_check(avl_depth(root) == 0);

  mu_check(root == NULL);
}

MU_TEST(test_04_add_two_one_in_rite_child)
{
  struct avl_node* root = { NULL };

  mu_check(avl_add(&root, (void*)10, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)10, test_avl_compare_func_lt) == false);

  mu_check(avl_add(&root, (void*)11, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)11, test_avl_compare_func_lt) == false);

  mu_check(avl_size(root) == 2);

  mu_check(avl_rem(&root, (void*)10, test_avl_compare_func_lt, test_avl_clear_func) == true);
  mu_check(avl_rem(&root, (void*)10, test_avl_compare_func_lt, test_avl_clear_func) == false);

  mu_check(avl_rem(&root, (void*)11, test_avl_compare_func_lt, test_avl_clear_func) == true);
  mu_check(avl_rem(&root, (void*)11, test_avl_compare_func_lt, test_avl_clear_func) == false);

  mu_check(root == NULL);
}

MU_TEST(test_05_complete_tree_01)
{
  struct avl_node* root = { NULL };

  // root
  mu_check(avl_add(&root, (void*)50, test_avl_compare_func_lt) == true);
  // root->left & rite
  mu_check(avl_add(&root, (void*)25, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)75, test_avl_compare_func_lt) == true);
  // root->left->left & rite
  mu_check(avl_add(&root, (void*)15, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)35, test_avl_compare_func_lt) == true);
  // root->rite->left & rite
  mu_check(avl_add(&root, (void*)65, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)85, test_avl_compare_func_lt) == true);

  const int size_1 = avl_size(root);
  mu_check(size_1 == 7);

  // remove non-existing value
  mu_check(avl_rem(&root, (void*)101, test_avl_compare_func_lt, test_avl_clear_func) == false);

  // always remove the root
  int size_2 = 0;
  while (root != NULL) {
    void* val = root->data;
    const bool res = avl_rem(&root, val, test_avl_compare_func_lt, test_avl_clear_func);
    mu_check(res);
    if (res) {
      size_2 += 1;
    }
    mu_check(avl_rem(&root, val, test_avl_compare_func_lt, test_avl_clear_func) == false);
  }

  mu_check(size_1 == size_2);

  // post
  mu_check(root == NULL);
}

MU_TEST(test_06_rand)
{
  struct avl_node* root = { NULL };

  const int cnt_intended = 3000;

  long long sum_added = 0LL;
  int cnt_added = 0;
  for (int i = 0; i < cnt_intended; ++i) {
    const int val = rand();
    const bool res_add = avl_add(&root, (void*)(intptr_t)val, test_avl_compare_func_lt); // there can be duplicates
    if (res_add) {
      sum_added += val;
      cnt_added += 1;
      test_98_check_order(root);
      test_99_check_pare_consistency_root(root);
      mu_check(avl_size(root) == cnt_added);
    }
  }

  mu_check(test_98_check_order(root));

  const int size_added = avl_size(root);
  mu_check(cnt_added == size_added);

  long long sum_removed = 0LL;
  int cnt_removed = 0;
  while (root != NULL) {
    void* val = root->data;
    const bool res_rem = avl_rem(&root, val, test_avl_compare_func_lt, test_avl_clear_func);
    mu_check(res_rem);
    test_99_check_pare_consistency_root(root);
    if (res_rem) {
      sum_removed += (int)(intptr_t)val;
      cnt_removed += 1;
    }
    mu_check(avl_rem(&root, val, test_avl_compare_func_lt, test_avl_clear_func) == false);
  }

  mu_check(sum_added == sum_removed);
  mu_check(cnt_added == cnt_removed);

  // post
  mu_check(root == NULL);
}

MU_TEST(test_07_rand_in_an_array)
{
  struct avl_node* root = { NULL };
  static const int val_arr_size = 3000;
  int val_arr[ val_arr_size ];
  for (int i = 0; i < val_arr_size; ++i) {
    while(true) {
      const int val = rand();
      const bool res_add = avl_add(&root, (void*)(intptr_t)val, test_avl_compare_func_lt);
      if (res_add) {
        test_98_check_order(root);
        test_99_check_pare_consistency_root(root);
        mu_check(avl_size(root) == i + 1);
        val_arr[i] = val;
        break;
      }
    }
  }

  mu_check(test_98_check_order(root));
   
  for(int j = val_arr_size - 1 ; j >= 0; j--) {
    const int val = val_arr[j];

    mu_check(avl_find(root, (void*)(intptr_t)val, test_avl_compare_func_lt) == true);

    mu_check(avl_rem(&root, (void*)(intptr_t)val, test_avl_compare_func_lt, test_avl_clear_func));
    test_99_check_pare_consistency_root(root);

    mu_check(avl_find(root, (void*)(intptr_t)val, test_avl_compare_func_lt) == false);

    mu_check(avl_rem(&root, (void*)(intptr_t)val, test_avl_compare_func_lt, test_avl_clear_func) == false);
  }
}

MU_TEST(test_08_outer_tree)
{
  struct avl_node* root = { NULL };
  // root
  mu_check(avl_depth(root) == 0);
  mu_check(avl_add(&root, (void*)50, test_avl_compare_func_lt) == true);
  mu_check(avl_depth(root) == 1);
  // outer left
  mu_check(avl_add(&root, (void*)40, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)30, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)20, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)10, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*) 9, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)11, test_avl_compare_func_lt) == true);
  // outer rite
  mu_check(avl_add(&root, (void*)60, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)70, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)80, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)90, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)89, test_avl_compare_func_lt) == true);
  mu_check(avl_add(&root, (void*)91, test_avl_compare_func_lt) == true);

  test_98_check_order(root);
  test_99_check_pare_consistency_root(root);
  mu_check(avl_size(root) == 13);

  mu_check(avl_clear(&root, test_avl_clear_func) == 13);
  mu_check(root == NULL);
}

MU_TEST(test_09_slim_downwards)
{
  struct avl_node* root = { NULL };

  mu_check(avl_add(&root, (void*)50, test_avl_compare_func_lt));

  mu_check(avl_add(&root, (void*)20, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)49, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)21, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)48, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)22, test_avl_compare_func_lt));

  mu_check(avl_add(&root, (void*)80, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)51, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)79, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)52, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)78, test_avl_compare_func_lt));

  mu_check(avl_size(root) == 11);

  mu_check(avl_clear(&root, test_avl_clear_func) == 11);
  mu_check(root == NULL);
}

MU_TEST(test_10_linked_list_to_left)
{
  struct avl_node* root = { NULL };

  // construct a tree that actually looks like a linked list
  // each new element being added to the left of the last leaf
  const int node_count = 1000;
  for (int i = node_count; i > 0; i--) {
    mu_check(avl_add(&root, (void*)(intptr_t)i, test_avl_compare_func_lt));
    test_98_check_order(root);
    test_99_check_pare_consistency_root(root);
    mu_check(avl_size(root) == node_count - i + 1);
  }

  mu_check(avl_clear(&root, test_avl_clear_func) == node_count);
  mu_check(root == NULL);
}

MU_TEST(test_11_linked_list_to_rite)
{
  struct avl_node* root = { NULL };

  // construct a tree that actually looks like a linked list
  // each new element being added to the rite of the last leaf
  const int node_count = 1000;
  for (int i = 0; i < node_count; i++) {
    mu_check(avl_add(&root, (void*)(intptr_t)i, test_avl_compare_func_lt));
    test_98_check_order(root);
    test_99_check_pare_consistency_root(root);
    mu_check(avl_size(root) == i + 1);
  }

  mu_check(avl_clear(&root, test_avl_clear_func) == node_count);
  mu_check(root == NULL);
}

MU_TEST(test_12_balance_left_left)
{
  struct avl_node* root = { NULL };

  mu_check(avl_add(&root, (void*)50, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)30, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)20, test_avl_compare_func_lt));

  mu_check(avl_depth(root) == 2);
  test_98_check_order(root);
  test_99_check_pare_consistency_root(root);

  mu_check(avl_clear(&root, test_avl_clear_func) == 3);
  mu_check(root == NULL);
}

MU_TEST(test_13_balance_rite_rite)
{
  struct avl_node* root = { NULL };

  mu_check(avl_add(&root, (void*)10, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)20, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)30, test_avl_compare_func_lt));

  mu_check(avl_depth(root) == 2);
  test_98_check_order(root);
  test_99_check_pare_consistency_root(root);

  mu_check(avl_clear(&root, test_avl_clear_func) == 3);
  mu_check(root == NULL);
}

MU_TEST(test_14_balance_left_rite)
{
  struct avl_node* root = { NULL };

  mu_check(avl_add(&root, (void*)30, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)10, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)20, test_avl_compare_func_lt));

  mu_check(avl_depth(root) == 2);
  test_98_check_order(root);
  test_99_check_pare_consistency_root(root);

  mu_check(avl_clear(&root, test_avl_clear_func) == 3);
  mu_check(root == NULL);
}

MU_TEST(test_15_balance_rite_left)
{
  struct avl_node* root = { NULL };

  mu_check(avl_add(&root, (void*)30, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)50, test_avl_compare_func_lt));
  mu_check(avl_add(&root, (void*)40, test_avl_compare_func_lt));

  mu_check(avl_depth(root) == 2);
  test_98_check_order(root);
  test_99_check_pare_consistency_root(root);

  mu_check(avl_clear(&root, test_avl_clear_func) == 3);
  mu_check(root == NULL);
}

MU_TEST_SUITE(test_suite_01)
{
  MU_RUN_TEST(test_01_remove_from_empty);
  MU_RUN_TEST(test_02_add_one_rem_one);
  MU_RUN_TEST(test_03_add_two_one_in_left_child);
  MU_RUN_TEST(test_04_add_two_one_in_rite_child);
  MU_RUN_TEST(test_05_complete_tree_01);
  MU_RUN_TEST(test_06_rand);
  MU_RUN_TEST(test_07_rand_in_an_array);
  MU_RUN_TEST(test_08_outer_tree);
  MU_RUN_TEST(test_09_slim_downwards);
  MU_RUN_TEST(test_10_linked_list_to_left);
  MU_RUN_TEST(test_11_linked_list_to_rite);
  MU_RUN_TEST(test_12_balance_left_left);
  MU_RUN_TEST(test_13_balance_rite_rite);
  MU_RUN_TEST(test_14_balance_left_rite);
  MU_RUN_TEST(test_15_balance_rite_left);
}

int main()
{
  srand((unsigned)time(0));

  MU_SUITE_CONFIGURE_SHOW_PROGRESS(0);

  MU_RUN_SUITE(test_suite_01);
  MU_REPORT();

  return 0;
}
