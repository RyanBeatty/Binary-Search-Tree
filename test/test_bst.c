#include <stdio.h>
#include "minunit.h"
#include "../src/bst.h"

int tests_run = 0;

static char *
test_new_bst() {
	// test that new_bst returns a new non NULL head Node
	// and that node's data was initialized to 5

	Node *bst = new_bst_node(5);
	mu_assert("failed: test_new_bst: new_bst() returned NULL",
			  bst != NULL);
	mu_assert("failed: test_new_bst: node->data != 5",
			  bst->data == 5);

	delete_bst_tree(&bst);
	return 0;
}

static char *
test_insert_null_head() {
	// test that insert() fails when passed a NULL head

	mu_assert("failed: test_insert_null_head: insert() != -1",
			  insert(NULL, 5) == -1);
	return 0;
}

static char *
test_insert() {

	// Node *bst = new_bst_node(5);
	Node *bst = NULL;
	mu_assert("failed: insert 5",
			  insert(&bst, 5) == 1);
	mu_assert("failed: test_insert 5",
			  bst->data == 5);

	mu_assert("failed: insert 5 again",
		      insert(&bst, 5) == 1);
	mu_assert("failed: test_insert: insert 5",
			  bst->left == NULL && bst->right == NULL);

	mu_assert("failed: insert 3",
			  insert(&bst, 3) == 1);
	mu_assert("failed: insert 7",
			  insert(&bst, 7) == 1);

	mu_assert("failed: test_insert: bst->left->data != 4",
			  bst->left->data == 3);
	mu_assert("failed: test_insert: bst->right->data != 6",
			  bst->right->data == 7);


	mu_assert("failed: test_insert", 
			  insert(&bst, 2));
	mu_assert("failed: test_insert", 
			  insert(&bst, 4));
	mu_assert("failed: test_insert", 
			  insert(&bst, 6));
	mu_assert("failed: test_insert", 
			  insert(&bst, 8));

	mu_assert("failed: test_insert: insert 2",
			  bst->left->left->data == 2);
	mu_assert("failed: test_insert: insert 2",
			  bst->left->right->data == 4);
	mu_assert("failed: test_insert: insert 6",
			  bst->right->left->data == 6);
	mu_assert("failed: test_insert: insert 8",
			  bst->right->right->data == 8);

	mu_assert("failed: test_insert", 
			  insert(&bst, 0));
	mu_assert("failed: test_insert", 
			  insert(&bst, -2));

	mu_assert("failed: test_insert: insert 0",
			  search(bst, 0) == 1);

	mu_assert("failed: test_insert: insert -2",
			  search(bst, -2) == 1);


	delete_bst_tree(&bst);
	return 0;
}

static char *
test_search() {
	Node *bst = NULL;

	mu_assert("failed: test_search: empty tree",
			  search(bst, 5) == 0);

	mu_assert("failed: test_search: insert",
			  insert(&bst, 5) == 1);
	mu_assert("failed: test_search: insert",
			  insert(&bst, 3) == 1);
	mu_assert("failed: test_search: insert",
			  insert(&bst, 2) == 1);
	mu_assert("failed: test_search: insert",
			  insert(&bst, 4) == 1);
	mu_assert("failed: test_search: insert",
			  insert(&bst, 8) == 1);
	mu_assert("failed: test_search: insert",
			  insert(&bst, 7) == 1);
	mu_assert("failed: test_search: insert",
			  insert(&bst, 9) == 1);

	mu_assert("failed: test_search: search 5",
			  search(bst, 5) == 1);
	mu_assert("failed: test_search: search 3",
			  search(bst, 3) == 1);
	mu_assert("failed: test_search: search 2",
			  search(bst, 2) == 1);
	mu_assert("failed: test_search: search 4",
			  search(bst, 4) == 1);
	mu_assert("failed: test_search: search 8",
			  search(bst, 8) == 1);
	mu_assert("failed: test_search: search 7",
			  search(bst, 7) == 1);
	mu_assert("failed: test_search: search 9",
			  search(bst, 9) == 1);
	mu_assert("failed: test_search: search 10",
			  search(bst, 10) == 0);

	delete_bst_tree(&bst);
	return 0;
}

static char *
test_find_minimum() {
	Node *bst = new_bst_node(5);

	mu_assert("failed: test_find_minimum: should return 5",
			  find_minimum(bst) == 5);

	insert(&bst, 6);
	mu_assert("failed: test_find_minimum: should return 5",
			  find_minimum(bst) == 5);

	insert(&bst, 3);
	mu_assert("failed: test_find_minimum: should return 3",
			  find_minimum(bst) == 3);

	insert(&bst, 4);
	mu_assert("failed: test_find_minimum: should return 3",
			  find_minimum(bst) == 3);

	insert(&bst, 2);
	mu_assert("failed: test_find_minimum: should return 2",
			  find_minimum(bst) == 2);

	delete_bst_tree(&bst);
	return 0;
}

static char *
test_delete_no_children() {

	delete(NULL, 0);
	
	Node *bst = new_bst_node(5);

	delete(&bst, 4);
	delete(&bst, 6);
	delete(&bst, 5);
	mu_assert("failed: test_delete: delete root, no children",
			  bst == NULL);

	delete_bst_tree(&bst);
	bst = new_bst_node(6);
	insert(&bst, 4);
	insert(&bst, 7);

	delete(&bst, 4);
	mu_assert("failed: test_delete: delete left child",
			  bst->left == NULL);

	delete(&bst, 7);
	mu_assert("failed: test_delete: delete left child",
			  bst->right == NULL);

	delete_bst_tree(&bst);
	return 0;
}

static char *
test_delete_one_child() {

	Node *bst = new_bst_node(5);
	insert(&bst, 3);

	delete(&bst, 5);
	mu_assert("failed: test_delete: check delete root, w/ left child",
			  bst->data == 3);

	insert(&bst, 6);

	delete(&bst, 3);
	mu_assert("failed: test_delete: check delete root, w/ right child",
			  bst->data == 6);

	insert(&bst, 4);
	insert(&bst, 3);

	delete(&bst, 4);
	mu_assert("failed: test_delete: check delete 4",
			  bst->left->data == 3);

	insert(&bst, 4);

	delete(&bst, 3);
	mu_assert("failed: test_delete: check delete 3",
			  bst->left->data == 4);

	insert(&bst, 8);
	insert(&bst, 7);

	delete(&bst, 8);
	mu_assert("failed: test_delete: check delete 8",
			  bst->right->data == 7);

	insert(&bst, 9);

	delete(&bst, 7);
	mu_assert("failed: test_delete: check delete 7",
			  bst->right->data == 9);

	delete_bst_tree(&bst);
	return 0;
}

static char *
test_delete_two_children_head() {
	Node *bst = new_bst_node(5);
	insert(&bst, 4);
	insert(&bst, 6);

	delete(&bst, 5);
	mu_assert("failed: test_delete: check delete head w/ 2 children",
			  bst->data == 6 && bst->left->data == 4 && bst->right == NULL);

	insert(&bst, 8);
	insert(&bst, 7);
	insert(&bst, 9);

	delete(&bst, 6);
	mu_assert("failed: test_delete: check delete head w/ 2 children",
			  bst->data == 7 && bst->left->data == 4);
	mu_assert("failed: test_delete: check delete head w/ 2 children",
			  bst->right->data == 8 && bst->right->right->data == 9);
	mu_assert("failed: test_delete: check delete head w/ 2 children",
			  bst->right->left == NULL);

	delete_bst_tree(&bst);
	return 0;
}

static char *
test_delete_two_children() {

	Node *bst = new_bst_node(6);

	insert(&bst, 4);
	insert(&bst, 8);
	insert(&bst, 7);
	insert(&bst, 9);

	delete(&bst, 8);
	mu_assert("failed: test_delete: check delete right w/ 2 children",
			  bst->data == 6 && bst->left->data == 4);
	mu_assert("failed: test_delete: check delete right w/ 2 children",
			  bst->right->data == 9 && bst->right->left->data == 7);
	mu_assert("failed: test_delete: check delete right w/ 2 children",
			  bst->right->right == NULL);

	delete_bst_tree(&bst);
	bst = new_bst_node(10);
	insert(&bst, 5);
	insert(&bst, 8);
	insert(&bst, 2);
	insert(&bst, 7);
	insert(&bst, 6);
	insert(&bst, 9);

	delete(&bst, 5);
	mu_assert("failed: test_delete: check delete left w/ 2 children",
			  bst->left->data == 6 && bst->left->left->data == 2);
	mu_assert("failed: test_delete: check delete left w/ 2 children",
			  bst->left->right->data == 8 && bst->left->right->left->data == 7);
	mu_assert("failed: test_delete: check delete left w/ 2 children",
			  bst->left->right->right->data == 9);

	delete_bst_tree(&bst);
	return 0;
}

static char *
test_delete_bst_tree() {

	Node *bst = new_bst_node(10);
	insert(&bst, 5);
	insert(&bst, 14);
	insert(&bst, 12);
	insert(&bst, 15);
	insert(&bst, 13);
	insert(&bst, 8);
	insert(&bst, 7);
	insert(&bst, 9);
	insert(&bst, 3);
	insert(&bst, 2);
	insert(&bst, 1);

	delete_bst_tree(&bst);
	mu_assert("failed: test_delete_bst_tree: deletion failed",
			  bst == NULL);

	return 0;
}

static char *
test_build_bst_tree_null_data() {
	mu_assert("failed: test_build_bst_tree_null_data failed",
			  build_bst_tree(NULL, 1) == NULL);

	return 0;
}

static char *
test_build_bst_tree() {
	int data[] = {5, 3, 7, 4, 8, 1, 9};

	Node *bst = NULL;
	bst = build_bst_tree(data, 7);
	mu_assert("failed: bst tree is NULL",
			  bst != NULL);

	return 0;
}

static char *
all_tests() {
	/*
	run all tests in the suite
	*/
	mu_run_test(test_new_bst);
	mu_run_test(test_insert_null_head);
	mu_run_test(test_insert);
	mu_run_test(test_search);
	mu_run_test(test_find_minimum);
	mu_run_test(test_delete_no_children);
	mu_run_test(test_delete_one_child);
	mu_run_test(test_delete_two_children_head);
	mu_run_test(test_delete_two_children);
	mu_run_test(test_delete_bst_tree);
	mu_run_test(test_build_bst_tree_null_data);
	mu_run_test(test_build_bst_tree);
	return 0;
}

int main(int argc, char **argv) {
 char *result = all_tests();
 if (result != 0) {
     printf("%s\n", result);
 }
 else {
     printf("ALL TESTS PASSED\n");
 }
 printf("Tests run: %d\n", tests_run);

 return result != 0;
}
