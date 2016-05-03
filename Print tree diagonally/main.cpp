/*
 Author : Yeshwanth D S
 
 Program DEscription :
 Program to pring the tree nodes diagonally.
 
 Program Source : GeeksforGeeks
 Working program link : http://ideone.com/VYVZyU
 
 */
 

#include<iostream>
#include<queue>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node* newNode(int data)
{
    struct node* temp = new struct node();
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    
    return temp;
}

void printInorder(struct node* root)
{
    if(!root)
        return;
    printInorder(root -> left);
    cout << root -> data << " ";
    printInorder(root -> right);
}

void printDiaglonal(struct node* root)
{
    if(root == NULL)
        return;
    
    queue<struct node*> que;
    
    que.push(root);
    
    //add the root of the tree to the queue..
    while(!que.empty())
    {
        int size = que.size();
        /*
         The idea here is to take the left most node of each diagonal 
         into the queue and print out all the nodes lying on the right
         of this node(nodes to the right in the same diagonal).
         in the above example:
         8 is the leftmost node of the first diagonal. So we print all
         the nodes on the right of this node in this diagonal. So we print
         10 and 14.
         In this process we add all the immediate left child of these 
         nodes into the queue since they are the leftmost nodes of
         the next consecutive diagonals.
         
         We use the size variable to keep track the number of nodes in 
         the queue that belong to the current diagonal.
         in the above example:
         once we print the first diagonal 8, 10, 14 the queue will have 2
         nodes 3 and 13 which are the leftmost nodes of the
         next diagonal. So we use these to print the corresponding nodes.
         In this process we will add nodes 1, 4 into the queue. So if we
         dont have the size of the queue, before pusing these new nodes
         then we will not be able to track the elemets that belong to this
         diagonal. For this purpose we use the variable size in our program.
         
         Hope this helps..
         */
        while(size--)
        {
            struct node* temp = que.front();
            que.pop();
        
            while(temp)
            {
                cout << temp -> data << " ";
                if(temp -> left)
                    que.push(temp -> left);
                temp = temp -> right;
            }
        }
        cout << endl;
    }
}

int main()
{
    struct node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    
    cout << "Pre order traversal : " << endl;
    printInorder(root);
    
    cout << "\nDiagonal traversal :" << endl;
    
    printDiaglonal(root);
}