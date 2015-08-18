//      Author : Yeshwanth D S
//      Program to delete all the elements of a tree..
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

void _deleteTree(struct node *root)
{
    if(root == NULL)
        return;
    else
    {
        _deleteTree(root->left);
        _deleteTree(root->right);
        free(root);
    }
}

struct node* deleteTree(struct node *root)
{
    _deleteTree(root);
    return NULL;
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

void printTree(struct node *root)
{
    if(root == NULL)
        return;
    printTree(root->left);
    printf("%d ",root->data);
    printTree(root->right);
}
int main()
{
    struct node *root = newNode(5);
    
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(6);
    
    printf("Tree before deleting\n");
    printTree(root);
    
    root = deleteTree(root);
    
    printf("\nTree after deleting\n");
    printTree(root);
    getchar();
    return 0;
}