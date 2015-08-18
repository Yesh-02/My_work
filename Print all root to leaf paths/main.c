//      Author : Yeshwanth D S
//      Program to print all the root to leaf paths..
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void printArray(int arr[],int max)
{
    for(int i=0;i<max;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void printRootToLeafPaths(struct node* root,int arr[],int i)
{
    if(root == NULL)
        return;
    arr[i]=root->data;
    i++;
    if(!root->left && !root->right)
        printArray(arr,i);
    printRootToLeafPaths(root->left,arr,i);
    printRootToLeafPaths(root->right,arr,i);
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
    int arr[100]={0};
    
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    
    printRootToLeafPaths(root,arr,0);
    
    printTree(root);
    getchar();
    return 0;
}