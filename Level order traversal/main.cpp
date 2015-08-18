//      Author : Yeshwanth D S
//      Program to print the nodes of a tree in level order...

#include<iostream>
#include<queue>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void printLevelOrder(struct node *root)
{
    queue<struct node*> queue;
    struct node* temp = root;
    while(temp)
    {
        cout<<temp->data<<' ';
        if(root->left)
            queue.push(temp->left);
        if(root->right)
            queue.push(temp->right);
        temp = queue.front();
        queue.pop();
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

int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printLevelOrder(root);
    
    getchar();
    return 0;
}