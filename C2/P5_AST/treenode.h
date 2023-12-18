//header file for struct definition
struct Node
{
	int val;
	char *op;
	struct Node *left,*right;
};
    
struct Node *createNode(char c,int x,struct Node *left,struct Node *right);

void print2DTree(struct Node* root, int space);
