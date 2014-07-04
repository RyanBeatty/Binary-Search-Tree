CC = gcc
CFlags = -Wall


# build_test: ./test/minunit_example.c ./src/ex.o
# 	gcc -Wall -o test ./test/test_bst.c ./src/ex.o
test: build_test
	./test/suite

build_test: ./test/test_bst.c ./src/bst.o
	gcc -Wall -o ./test/suite ./test/test_bst.c ./src/bst.o;

bst.o: bst.c bst.h
	gcc -Wall -c bst.c -o bst.o
