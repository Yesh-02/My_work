#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
 and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

// A utility function to get height of a binary tree
int height(struct node* node);

// A utility function to allocate a new node with given data
struct node* newNode(int data);

// A utility function that returns maximum value in arr[] of size n
int getMax(int arr[], int n);

// A function that fills count array with count of nodes at every
// level of given binary tree
void getMaxWidthRecur(struct node *root, int count[], int level);


/* Function to get the maximum width of a binary tree*/
int getMaxWidth(struct node* root)
{
    int width;
    int h = height(root);
    
    // Create an array that will store count of nodes at each level
    int *count = (int *)calloc(sizeof(int), h);
    
    int level = 0;
    
    // Fill the count array using preorder traversal
    getMaxWidthRecur(root, count, level);
    
    // Return the maximum value from count array
    return getMax(count, h);
}

// A function that fills count array with count of nodes at every
// level of given binary tree
void getMaxWidthRecur(struct node *root, int count[], int level)
{
    if(root)
    {
        getMaxWidthRecur(root->left, count, level+1);
        count[level]++;
        getMaxWidthRecur(root->right, count, level+1);
    }
}


/* UTILITY FUNCTIONS */
/* Compute the "height" of a tree -- the number of
 nodes along the longest path from the root node
 down to the farthest leaf node.*/
int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        /* use the larger one */
        
        return (lHeight > rHeight)? (lHeight+1): (rHeight+1);
    }
}
/* Helper function that allocates a new node with the
 given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Return the maximum value from count array
int getMax(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left  = newNode(6);
    root->right->right->right  = newNode(7);
    
    /*
     Constructed bunary tree is:
     1
     /  \
     2    3
     /  \     \
     4   5     8
     /  \
     6   7
     */
    printf("Maximum width is %d \n", getMaxWidth(root));
    getchar();
    return 0;
}