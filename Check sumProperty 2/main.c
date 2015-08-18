#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int _checkSumProperty(struct node *root, int *sum)
{
    int lsum = 0, rsum = 0,lt = 0,rt = 0;
    if(root == NULL)
    {
        *sum = 0;
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
    {
        *sum = root->data;
        return 1;
    }
    else
    {
        if(root->left)
            lt = _checkSumProperty(root->left,&lsum);
        else
            lt = 1;
        if(root->right)
            rt = _checkSumProperty(root->right,&rsum);
        else
            rt = 1;
        //printf("lsum:%d,rsum:%d,lt:%d,rt:%d,root->data:%d\n",lsum,rsum,lt,rt,root->data);
        if(lt && rt &&(lsum+rsum == root->data))
        {
            *sum = 2*root->data;
            return 1;
        }
        else
            return 0;
    }
}

int checkSumProperty(struct node *root)
{
    int sum = 0;
    return _checkSumProperty(root,&sum);
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
    struct node *root  = newNode(32);
    root->left         = newNode(10);
    root->right        = newNode(6);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
    root->right->right->left = newNode(1);
    root->right->right->right = newNode(2);
    
    if(checkSumProperty(root))
        printf("YES");
    else
        printf("NO");
    getchar();
    return 0;
}