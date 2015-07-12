#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)

{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}
void inOrder(struct node* node)
{
    if (node == NULL)
        return;
    
    inOrder(node->left);
    printf("%d ", node->data);
    
    inOrder(node->right);
}
int isMirror(struct node* node1,struct node* node2)
{
    if (node1 == NULL && node2== NULL)
        return 1;
    if (node1->data != node2->data)
        return 0;
    return isMirror(node1->left,node2->left) && isMirror(node1->right,node2->right);
}
int main()
{
    struct node *root1 = newNode(1);
    root1->left        = newNode(2);
    root1->right       = newNode(3);
    root1->left->left  = newNode(3);
    root1->left->right = newNode(5);
    
    struct node *root2 = newNode(1);
    root2->left        = newNode(1);
    root2->right       = newNode(3);
    root2->left->left  = newNode(3);
    root2->left->right = newNode(5);
    
    if(isMirror(root1,root2))  printf("true\n");
    else printf("false\n");
    inOrder(root1);
    printf("\n");
    inOrder(root2);
    return 0;
}