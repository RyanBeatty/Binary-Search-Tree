#include <stdlib.h>
#include "bst.h"


Node *
new_bst_node(int data) {
	/* 
	* creates and initializes a new Node object
	* with the passed in data
	*
	* RETURNS: pointer to new Node object or NULL on failure
	*/
	Node *new_bst = NULL;

	// if calloc failed, return NULL
	if((new_bst = (Node *) calloc(1, sizeof(Node))) == NULL)
		return NULL;

	// initialize Node object attributes
	new_bst->data = data;
	new_bst->left = NULL;
	new_bst->right = NULL;
	return new_bst;
}

Node *
build_bst_tree(int *data_set, int set_size) {
	/*
	* takes an array of data objects and
	* builds a new bst tree
	*
	* RETURNS: a pointer to the root node
	*		   of the bst tree. or NULL on
	*		   failure
	*/

	// no input
	if(data_set == NULL)
		return NULL;

	Node *root = NULL;
	int i = 0;
	for(; i < set_size; ++i)
	{
		// insert next data object
		if(insert(&root, data_set[i]) < 0)
		{
			// insert failed, delete tree
			delete_bst_tree(&root);
			return NULL;
		}
	}

	return root;
}

void
delete_bst_tree(Node **root) {
	/* 
	* deletes entire bst tree
	* root should be NULL afterwards
	*
	* RETURNS: VOID
	*/

	// no input
	if(root == NULL)
		return ;

	// delete all nodes in tree
	while(*root != NULL)
		delete(root, (*root)->data);
}

/*******************************************************
* OLD INSERT METHOD.
* TO DO: REFACTOR TO ALLOW INSERT AT HEAD
*******************************************************/
// int
// insert(Node *head, int data) {
// 	// inserts new node into tree
// 	// returns 1 on success or -1 on failure
// 	// prevents duplicates

// 	// head is NULL so signal failure
// 	if(head == NULL)
// 		return -1;

// 	// set up new node to be inserted
// 	Node *new_node = new_bst_node(data);

// 	// node creation failed, return -1
// 	if(new_node == NULL)
// 		return -1;

// 	// iterate through tree, searching for place to
// 	// insert new node
// 	Node *cur_node = head;
// 	while(1) 
// 	{
// 		// data is already in tree
// 		if(new_node->data == cur_node->data)
// 			return 1;

// 		// move down left child
// 		if(new_node->data < cur_node->data) 
// 		{
// 			// found place to insert node
// 			if(cur_node->left == NULL) {
// 				cur_node->left = new_node;
// 				return 1;
// 			}

// 			// continue searching
// 			cur_node = cur_node->left;
// 		}

// 		// move down right child
// 		else
// 		{
// 			// found place to insert node
// 			if(cur_node->right == NULL) {
// 				cur_node->right = new_node;
// 				return 1;
// 			}

// 			// continue searching
// 			cur_node = cur_node->right;
// 		} 
// 	}
// }

int
insert(Node **cur_node, int target) {
	/*
	* recursively searches through the tree
	* and inserts target into correct position
	*
	* RETURNS: -1 on failure and 1 on success
	*/

	// invalid input
	if(cur_node == NULL)
		return -1;

	// found place to insert target
	if(*cur_node == NULL)
	{
		// create new node, add to tree, and check for failure
		*cur_node = new_bst_node(target);
		return *cur_node == NULL ? -1: 1;
	}

	// target already in tree
	else if(target == (*cur_node)->data)
		return 1;

	// move down left subtree
	else if(target < (*cur_node)->data)
		return insert(&((*cur_node)->left), target);

	// move down right subtree
	else
		return insert(&((*cur_node)->right), target);
}


int
search(Node *root, int target) {
	/*
	* Search through tree for target
	*
	* RETURNS: 1 if target is in tree or
	* 		   0 otherwise
	*/

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
	/* 
	* Recursively search through tree and
	* Remove Node with target data 
	*
	* RETURNS: VOID
	*/

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
	/* 
	* find smallest data element in left
	* subtree of a node
	*
	* NOTE: breaks if passed a NULL root node
	* NOTE: used only in delete()
	* RETURNS: value of smalles node in tree
	*/

	while(1)
	{
		if(root->left == NULL)
			return root->data;

		root = root->left;
	}
}
