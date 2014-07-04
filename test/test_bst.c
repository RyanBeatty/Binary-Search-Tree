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

static
char *
test_return4(){
	mu_assert("return4 error", return4() == 4);
	return 0;
}

static char * all_tests() {
	/*
	run all tests in the suite
	*/
	mu_run_test(test_return4);
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
