#include "minunit.h"
#include "../src/avl.h"
//#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool test_98_check_order(const struct avl_node* const _root)
{
  if (_root != NULL) {
    const bool left_ok      = (_root->left == NULL) || test_98_check_order(_root->left);

    const bool left_lt_root = (_root->left == NULL) || (_root->left->data < _root->data);
    const bool root_lt_rite = (_root->rite == NULL) || (_root->data < _root->rite->data);

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

  mu_check(avl_rem(&root, 10) == false);

  mu_check(root == NULL);
  mu_check(avl_size(root) == 0);
}

MU_TEST(test_02_add_one_rem_one)
{
  struct avl_node* root = { NULL };

  mu_check(avl_size(root) == 0);

  mu_check(avl_add(&root, 10) == true);
  mu_check(avl_add(&root, 10) == false);
  mu_check(avl_depth(root) == 1);
 
  mu_check(avl_size(root) == 1);

  mu_check(avl_rem(&root, 11) == false);

  mu_check(avl_size(root) == 1);

  mu_check(avl_rem(&root, 10) == true);
  mu_check(avl_rem(&root, 10) == false);
  mu_check(avl_depth(root) == 0);

  mu_check(root == NULL);
  mu_check(avl_size(root) == 0);
}

MU_TEST(test_03_add_two_one_in_left_child)
{
  struct avl_node* root = { NULL };

  mu_check(avl_add(&root, 10) == true);
  mu_check(avl_add(&root, 10) == false);
  mu_check(avl_depth(root) == 1);

  mu_check(avl_add(&root, 1) == true);
  mu_check(avl_add(&root, 1) == false);
  mu_check(avl_depth(root) == 2);

  mu_check(avl_size(root) == 2);

  mu_check(avl_rem(&root, 10) == true);
  mu_check(avl_rem(&root, 10) == false);
  mu_check(avl_depth(root) == 1);

  mu_check(avl_rem(&root, 1) == true);
  mu_check(avl_rem(&root, 1) == false);
  mu_check(avl_depth(root) == 0);

  mu_check(root == NULL);
}

MU_TEST(test_04_add_two_one_in_rite_child)
{
  struct avl_node* root = { NULL };

  mu_check(avl_add(&root, 10) == true);
  mu_check(avl_add(&root, 10) == false);

  mu_check(avl_add(&root, 11) == true);
  mu_check(avl_add(&root, 11) == false);

  mu_check(avl_size(root) == 2);

  mu_check(avl_rem(&root, 10) == true);
  mu_check(avl_rem(&root, 10) == false);

  mu_check(avl_rem(&root, 11) == true);
  mu_check(avl_rem(&root, 11) == false);

  mu_check(root == NULL);
}

MU_TEST(test_05_complete_tree_01)
{
  struct avl_node* root = { NULL };

  // root
  mu_check(avl_add(&root, 50) == true);
  // root->left & rite
  mu_check(avl_add(&root, 25) == true);
  mu_check(avl_add(&root, 75) == true);
  // root->left->left & rite
  mu_check(avl_add(&root, 15) == true);
  mu_check(avl_add(&root, 35) == true);
  // root->rite->left & rite
  mu_check(avl_add(&root, 65) == true);
  mu_check(avl_add(&root, 85) == true);

  const int size_1 = avl_size(root);
  mu_check(size_1 == 7);

  // remove non-existing value
  mu_check(avl_rem(&root, 101) == false);

  // always remove the root
  int size_2 = 0;
  while (root != NULL) {
    int root_data = root->data;
    const bool res = avl_rem(&root, root_data);
    mu_check(res);
    if (res) {
      size_2 += 1;
    }
    mu_check(avl_rem(&root, root_data) == false);
  }

  mu_check(size_1 == size_2);

  // post
  mu_check(root == NULL);
}

MU_TEST(test_06_rand)
{
  struct avl_node* root = { NULL };

  const int cnt_intended = 3000;

  //printf("cnt_intended = %d\n", cnt_intended);

  long long sum_added = 0LL;
  int cnt_added = 0;
  for (int i = 0; i < cnt_intended; ++i) {
    const int val = rand();
    const bool res_add = avl_add(&root, val); // there can be duplicates
    if (res_add) {
      test_99_check_pare_consistency_root(root);
      //printf("  %d", val);
      sum_added += val;
      cnt_added += 1;
    }
  }

  mu_check(test_98_check_order(root));

  const int size_added = avl_size(root);
  //printf("\n sum_added = %ld\n cnt_added = %d\n size_added = %d\n", sum_added, cnt_added, size_added);
  mu_check(cnt_added == size_added);

  long long sum_removed = 0LL;
  int cnt_removed = 0;
  while (root != NULL) {
    const int val = root->data;
    const bool res_rem = avl_rem(&root, val);
    mu_check(res_rem);
    test_99_check_pare_consistency_root(root);
    if (res_rem) {
      sum_removed += val;
      cnt_removed += 1;
    }
    mu_check(avl_rem(&root, val) == false);
  }
  //printf("\n sum_removed = %ld\n cnt_removed = %d\n", sum_removed, cnt_removed);

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
      const bool res_add = avl_add(&root, val);
      if (res_add) {
        test_99_check_pare_consistency_root(root);
        val_arr[i] = val;
        break;
      }
    }
  }

  mu_check(test_98_check_order(root));
   
  for(int j = val_arr_size - 1 ; j >= 0; j--) {
    const int val = val_arr[j];

    mu_check(avl_find(root, val) == true);

    mu_check(avl_rem(&root, val));
    test_99_check_pare_consistency_root(root);

    mu_check(avl_find(root, val) == false);

    mu_check(avl_rem(&root, val) == false);
  }
}

MU_TEST(test_08_outer_tree)
{
  struct avl_node* root = { NULL };
  // root
  mu_check(avl_depth(root) == 0);
  mu_check(avl_add(&root, 50) == true);
  mu_check(avl_depth(root) == 1);
  // outer left
  mu_check(avl_add(&root, 40) == true);
  mu_check(avl_depth(root) == 2);
  mu_check(avl_add(&root, 30) == true);
  mu_check(avl_depth(root) == 3);
  mu_check(avl_add(&root, 20) == true);
  mu_check(avl_depth(root) == 4);
  mu_check(avl_add(&root, 10) == true);
  mu_check(avl_depth(root) == 5);
  mu_check(avl_add(&root,  9) == true);
  mu_check(avl_depth(root) == 6);
  mu_check(avl_add(&root, 11) == true);
  mu_check(avl_depth(root) == 6);
  // outer rite
  mu_check(avl_add(&root, 60) == true);
  mu_check(avl_depth(root) == 6);
  mu_check(avl_add(&root, 70) == true);
  mu_check(avl_depth(root) == 6);
  mu_check(avl_add(&root, 80) == true);
  mu_check(avl_depth(root) == 6);
  mu_check(avl_add(&root, 90) == true);
  mu_check(avl_depth(root) == 6);
  mu_check(avl_add(&root, 89) == true);
  mu_check(avl_depth(root) == 6);
  mu_check(avl_add(&root, 91) == true);
  mu_check(avl_depth(root) == 6);

  mu_check(avl_size(root) == 13);

  mu_check(avl_clear(&root) == 13);

  mu_check(root == NULL);
}

MU_TEST(test_09_slim_downwards)
{
  struct avl_node* root = { NULL };

  mu_check(avl_add(&root, 50));

  mu_check(avl_add(&root, 20));
  mu_check(avl_add(&root, 49));
  mu_check(avl_add(&root, 21));
  mu_check(avl_add(&root, 48));
  mu_check(avl_add(&root, 22));

  mu_check(avl_add(&root, 80));
  mu_check(avl_add(&root, 51));
  mu_check(avl_add(&root, 79));
  mu_check(avl_add(&root, 52));
  mu_check(avl_add(&root, 78));

  mu_check(avl_size(root) == 11);

  mu_check(avl_clear(&root) == 11);
  
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
}

int main()
{
  srand((unsigned)time(0));

  //MU_SUITE_CONFIGURE_PROGRESS(0);

  MU_RUN_SUITE(test_suite_01);
  MU_REPORT();

  return 0;
}
