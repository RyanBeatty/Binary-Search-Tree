#ifndef BST_H
#define BST_H

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

} Node;

Node *new_bst_node(int data);
Node *build_bst_tree(int *data_set, int set_sizse);
// int insert(Node *head, int data);
int insert(Node **head, int data);
int search(Node *root, int target);
void delete(Node **root, int target);
void delete_bst_tree(Node **root);


int find_minimum(Node *root);

#endif