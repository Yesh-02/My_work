//      Author : Yeshwanth D S
//      Program to matke the given tree a mirror of itself..
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

void mirrorTree(struct node* root)
{
    if(root == NULL)
        return;
    mirrorTree(root->left);
    mirrorTree(root->right);
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;
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
    
    printf("Tree before calling mirror function\n");
    printTree(root);
    
    mirrorTree(root);
    
    printf("\nTree after calling mirror function\n");
    printTree(root);
    getchar();
    return 0;
}