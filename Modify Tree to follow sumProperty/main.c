#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
//--------------->> CONVERT ENTIRE TREE <<----------------------
/*
 void makeSumProperty(struct node *root)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
        return;
    
    makeSumProperty(root->left);
    makeSumProperty(root->right);
    
    int left_data=0,right_data = 0;
    if(root->left)
        left_data = root->left->data;
    if(root->right)
        right_data = root->right->data;
    
    if(root->data != left_data + right_data)
        root->data = left_data+right_data;
    else
        return;
}
 */

void changeChildNodes(struct node *root, int diff)
{
    if(root->left != NULL)
    {
        root->left->data +=diff;
        changeChildNodes(root->left,diff);
    }
    else if(root->right != NULL)
    {
        root->right->data += diff;
        changeChildNodes(root->right,diff);
    }
}

void makeSumProperty(struct node *root)
{
    if(root == NULL)
        return;
    
    if(root->left == NULL && root->right == NULL)
        return;
    
    makeSumProperty(root->left);
    makeSumProperty(root->right);
    
    int left_data=0,right_data = 0;
    if(root->left)
        left_data = root->left->data;
    if(root->right)
        right_data = root->right->data;
    int diff = root->data - (left_data + right_data);
    if(diff < 0)
        root->data-= diff;
    else
        changeChildNodes(root,diff);
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
    struct node *root = newNode(50);
    root->left        = newNode(7);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left  = newNode(1);
    root->right->right = newNode(30);
    
    printf("Tree before calling mirror function\n");
    printTree(root);
    
    makeSumProperty(root);
    
    printf("\nTree after calling mirror function\n");
    printTree(root);
    getchar();
    return 0;
}