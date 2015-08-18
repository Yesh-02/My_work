#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int checkSumProperty(struct node *root)
{
    if(root == NULL)
        return 1;
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    int left = checkSumProperty(root->left);
    int right = checkSumProperty(root->right);
    
    int left_data=0,right_data = 0;
    if(root->left)
        left_data = root->left->data;
    if(root->right)
        right_data = root->right->data;
    
    if(left && right && root->data == left_data + right_data)
        return 1;
    else
        return 0;
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
    struct node *root  = newNode(10);
    root->left         = newNode(8);
    root->right        = newNode(2);
    root->left->left   = newNode(3);
    root->left->right  = newNode(5);
    root->right->right = newNode(3);
    
    if(checkSumProperty(root))
        printf("YES");
    else
        printf("NO");
    getchar();
    return 0;
}