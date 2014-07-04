#include <stdlib.h>
#include "bst.h"


Node *
new_bst_node(int data) {
	// creates and initializes a new Node object
	// or returns NULL if calloc fails
	Node *new_bst = NULL;

	if( (new_bst = (Node *) calloc(1, sizeof(Node))) == NULL)
		return NULL;

	new_bst->data = data;
	new_bst->left = NULL;
	new_bst->right = NULL;
	return new_bst;
}
