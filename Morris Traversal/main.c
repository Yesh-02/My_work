#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};


void morrisTraversal(struct node *root)
{
    if(root == NULL)
        return;
    struct node *cur,*prev;
    cur = root;
    while(cur)
    {
        if(cur -> left == NULL)
        {
            printf(" %d ",cur->data);
            cur = cur->right;
        }
        else
        {
            prev = cur->left;
            while(prev->right != NULL && prev ->right != cur)
                prev=prev->right;
            if(prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                printf(" %d ",cur->data);
                cur = cur->right;
            }
        }
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
    morrisTraversal(root);
    
    printf("\nTree after calling mirror function\n");
    printTree(root);
    getchar();
    return 0;
}