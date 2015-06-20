#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int arr[50];
struct node* newNode(int data)

{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}
void findArray(struct node *root,int count)
{
    if(root==NULL)
        return;
    findArray(root->left,count-1);
    if (root)
    {
        arr[root->data]=count;
        printf("%d-%d\n",root->data,count);
    }
    findArray(root->right,count+1);
}
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
 
    findArray(root,0);
    
    for (int i=0;i<15;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;  
}