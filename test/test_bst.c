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

	Node *bst = new_bst_node(5);

	insert(bst, 5);
	mu_assert("failed: test_insert: insert 5",
			  bst->left == NULL && bst->right == NULL);

	insert(bst, 3);
	insert(bst, 7);

	mu_assert("failed: test_insert: bst->left->data != 4",
			  bst->left->data == 3);
	mu_assert("failed: test_insert: bst->right->data != 6",
			  bst->right->data == 7);


	insert(bst, 2);
	insert(bst, 4);
	insert(bst, 6);
	insert(bst, 8);

	mu_assert("failed: test_insert: insert 2",
			  bst->left->left->data == 2);
	mu_assert("failed: test_insert: insert 2",
			  bst->left->right->data == 4);
	mu_assert("failed: test_insert: insert 6",
			  bst->right->left->data == 6);
	mu_assert("failed: test_insert: insert 8",
			  bst->right->right->data == 8);

	insert(bst, 0);
	insert(bst, -2);

	mu_assert("failed: test_insert: insert 0",
			  search(bst, 0) == 1);

	mu_assert("failed: test_insert: insert -2",
			  search(bst, -2) == 1);



	return 0;
}

static char *
test_search() {
	Node *bst = NULL;

	mu_assert("failed: test_search: empty tree",
			  search(bst, 5) == 0);

	bst = new_bst_node(5);
	insert(bst, 3);
	insert(bst, 2);
	insert(bst, 4);
	insert(bst, 8);
	insert(bst, 7);
	insert(bst, 9);

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
	return 0;
}

static char *
test_find_smallest() {
	Node *bst = new_bst_node(5);

	mu_assert("failed: test_find_smallest: should return 5",
			  find_smallest(bst) == 5);

	insert(bst, 6);
	mu_assert("failed: test_find_smallest: should return 5",
			  find_smallest(bst) == 5);

	insert(bst, 3);
	mu_assert("failed: test_find_smallest: should return 3",
			  find_smallest(bst) == 3);

	insert(bst, 4);
	mu_assert("failed: test_find_smallest: should return 3",
			  find_smallest(bst) == 3);

	insert(bst, 2);
	mu_assert("failed: test_find_smallest: should return 2",
			  find_smallest(bst) == 2);
	return 0;
}

static char * all_tests() {
	/*
	run all tests in the suite
	*/
	mu_run_test(test_new_bst);
	mu_run_test(test_insert_null_head);
	mu_run_test(test_insert);
	mu_run_test(test_search);
	mu_run_test(test_find_smallest);
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
