#ifndef BST_SEEN
#define BST_SEEN

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

} Node;

Node *new_bst_node(int data);

#endif