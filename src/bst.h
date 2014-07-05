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
void delete(Node **root, int target);
void delete_bst_tree(Node **root);


int find_minimum(Node *root);

#endif