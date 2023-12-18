//functions to create tree nodes and to print final AST
#include"treenode.h"
#include<stdio.h>
#define COUNT 10

struct Node *createNode(char c,int x,struct Node *left,struct Node *right)
    {
    	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    	newNode->op=(char*)malloc(sizeof(char));
    	*(newNode->op)=c;
    	newNode->val=x;
    	newNode->left=left;
    	newNode->right=right;
    	return newNode;
    }
    
void print2DTree(struct Node* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DTree(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    if(*(root->op)=='N')
    	printf("%d\n",root->val);
    else
    	printf("%c\n",*(root->op));
 
    // Process left child
    print2DTree(root->left, space);
}
 
