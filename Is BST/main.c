//      Author : Yeshwanth D S
//      Program to check if the given tree is a Binary Search Tree.. Condition is that the nodes
//      to the left of the tree should be lesser than root and on the value on the right should be grater..
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int isBST(struct node* node)
{
    if (node -> left == NULL && node -> right == NULL)
        return 1;
    else
    {
        int left = isBST(node->left);
        if(!left) return 0;
        int right = isBST(node->right);
        
        if (left && right && node->data > node->left->data && node->right->data > node->data)
            return 1;
        else return 0;
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
    
    if(isBST(root))
        printf("YES");
    else
        printf("NO");
    
    getchar();
    return 0;
}