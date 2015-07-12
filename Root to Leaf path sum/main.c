//Check if there is a root to leaf path with the given sum

#include<stdio.h>
#include<stdlib.h>
#define bool int
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
bool isSumPath(struct node * root, int sum)
{
    if(root==NULL) return (sum == 0);
    else if(root->left == NULL && root->right == NULL && sum == 0)
    {
        return 1;
    }
    return isSumPath(root->left,sum-root->data)||isSumPath(root->right,sum-root->data);
}
struct node* newnode(int data)
{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main()
{
    int sum = 12;
    struct node *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(2);
    root->left->left  = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);
    
    if(isSumPath(root, sum))
        printf("There is a root-to-leaf path with sum %d\n", sum);
    else
        printf("There is no root-to-leaf path with sum %d\n", sum);
    return 0;
}