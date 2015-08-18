//      Author : Yeshwanth D S
//      Program to find the depth of a given binary tree..
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int max(int l, int r)
{
    return (l > r)? l: r;
}

int findDepth(struct node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int left = findDepth(node->left);
        int right = findDepth(node->right);
        
        return max(left,right)+1;
    }
}

struct node* newNode(int data)
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
    struct node *root = newNode(5);
    
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(6);
    
    printf("Depth of the given tree is %d",findDepth(root));
    
    getchar();
    return 0;
}