CC = gcc
CFlags = -Wall

test: build_test
	./test/suite

build_test: ./test/test_bst.c ./src/bst.o
	gcc -Wall -o ./test/suite ./test/test_bst.c ./src/bst.o;

bst.o: bst.c bst.h
	gcc -Wall -c bst.c -o bst.o
