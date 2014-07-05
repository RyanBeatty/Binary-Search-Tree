#ifndef BST_SEEN
#define BST_SEEN

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

} Node;

Node *new_bst_node(int data);
int insert(Node *head, int data);
int search(Node *root, int target);
int delete(Node **root, int target);


int find_minimum(Node *root);

#endif