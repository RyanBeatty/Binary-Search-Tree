#include <stdio.h>
#include "minunit.h"
#include "../src/bst.h"

int tests_run = 0;

// int foo = 7;
// int bar = 4;

// static char * test_foo() {
//  mu_assert("error, foo != 7", foo == 7);
//  return 0;
// }

// static char * test_bar() {
//  mu_assert("error, bar != 4", bar == 4);
//  return 0;
// }

// static
// char *
// test_return3() {
//     mu_assert("return3 error", return3() == 2);
//     return 0;
// }

// static char * all_tests() {
//  mu_run_test(test_foo);
//  mu_run_test(test_bar);
//  mu_run_test(test_return3);
//  return 0;
// }

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

static char * all_tests() {
	/*
	run all tests in the suite
	*/
	mu_run_test(test_new_bst);
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
