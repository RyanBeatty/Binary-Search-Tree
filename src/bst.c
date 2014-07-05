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

void
delete_bst_tree(Node **root) {
	// deletes entire bst tree, changes root to NULL

	if(root == NULL)
		return ;

	while(*root != NULL)
		delete(root, (*root)->data);
}

int
insert(Node *head, int data) {
	// inserts new node into tree
	// returns 1 on success or -1 on failure
	// prevents duplicates

	// head is NULL so signal failure
	if(head == NULL)
		return -1;

	// set up new node to be inserted
	Node *new_node = new_bst_node(data);

	// node creation failed, return -1
	if(new_node == NULL)
		return -1;

	// iterate through tree, searching for place to
	// insert new node
	Node *cur_node = head;
	while(1) 
	{
		// data is already in tree
		if(new_node->data == cur_node->data)
			return 1;

		// move down left child
		if(new_node->data < cur_node->data) 
		{
			// found place to insert node
			if(cur_node->left == NULL) {
				cur_node->left = new_node;
				return 1;
			}

			// continue searching
			cur_node = cur_node->left;
		}

		// move down right child
		else
		{
			// found place to insert node
			if(cur_node->right == NULL) {
				cur_node->right = new_node;
				return 1;
			}

			// continue searching
			cur_node = cur_node->right;
		} 
	}
}


int
search(Node *root, int target) {
	// Search through tree for target
	// Return 1 if target is in tree or
	// 0 otherwise

	Node *cur_node = root;
	while(cur_node != NULL)
	{
		// found target
		if(target == cur_node->data)
			return 1;

		// move down left subtree
		else if(target < cur_node->data)
			cur_node = cur_node->left;

		// move down right subtree
		else
			cur_node = cur_node->right;
	}

	return 0;
}


void
delete(Node **root, int target) {
	/* Recursively search through tree and
	   Remove Node with target data */

	if(root == NULL || *root == NULL)
		return ;

	// found target, so remove node
	if((*root)->data == target)
	{

		// node has no children, just delete node
		if((*root)->left == NULL && (*root)->right == NULL)
		{
			free(*root);
			*root = NULL;
		}

		// node has only right child, so replace with right
		else if((*root)->left == NULL)
		{
			Node *cur_node = *root;
			*root = (*root)->right;
			free(cur_node);
		}

		// node has only left child, so replace with left
		else if((*root)->right == NULL)
		{
			Node *cur_node = *root;
			*root = (*root)->left;
			free(cur_node);
		}

		// node has two children
		else
		{
			(*root)->data = find_minimum((*root)->right);
			delete(&((*root)->right), (*root)->data);
		}
	}

	// recurse down left subtree
	else if(target < (*root)->data)
		delete(&((*root)->left), target);

	// recurse down right subtree
	else
		delete(&((*root)->right), target);
}

int
find_minimum(Node *root) {
	/* returns smallest data element in tree
	   NOTE: breaks if passed a NULL root node */

	while(1)
	{
		if(root->left == NULL)
			return root->data;

		root = root->left;
	}
}

