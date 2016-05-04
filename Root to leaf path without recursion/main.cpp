/*
 Author : Yeshwanth D S
 Program Description:
    A program to print all the root to leaf path without using recursion.(using morris traversal.)
 Complexity :
    Time : O(n);
    Space : O(n);
 Source : geeksforgeeks.com
 Problem link : http://ideone.com/uBYbnA
*/

#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node* newNode(int data)
{
    struct node *temp = new node();
    
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    
    return temp;
}

void printVector(vector<struct node*> &vec)
{
    static int count = 1;
    cout << count++ << ") ";
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i]-> data << " ";
    
        cout << endl;
}

int isLeaf(struct node *root)
{
    if(root -> left == NULL && root -> right == NULL)
        return 1;
    else
        return 0;
}

void rootToLeafUsingMorris(struct node *root)
{
    if(!root)
        return;
    
    struct node *cur = root, *pre;
    
    vector<struct node*> vec;
    
    while(cur != NULL)
    {
        if(cur -> left == NULL)
        {
            vec.push_back(cur);
            if(cur -> right == NULL && isLeaf(cur))
                printVector(vec);
            cur = cur -> right;
        }
        else
        {
            for(pre = cur -> left; pre->right != NULL && pre->right != cur; pre = pre->right);
            
            if(pre -> right == NULL)
            {
                pre -> right = cur;
                vec.push_back(cur);
                cur = cur -> left;
            }
            else
            {
                pre -> right = NULL;
                /* below if condition is to prevent printing paths with just one right node missing.. run the program
                by commenting this if condition with my example and you will understand :) .. the program will 
                 print 6 paths but there are only 5 root to leaf paths without the nodes 8, 13 and 14..*/
                if(isLeaf(pre))
                    printVector(vec);
                while(!vec.empty() && vec.back() != cur) //removing all the nodes on the left child of the current node
                    vec.pop_back();
                cur = cur -> right;
                
            }
        }
    }
    
}

int main()
{
    struct node* root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root -> right -> right = newNode(7);
    //root -> left -> left -> left = newNode(8);
    root -> left -> left -> right = newNode(9);
    root -> left -> right -> left = newNode(10);
    root -> left -> right -> right = newNode(11);
    root -> right -> left -> left = newNode(12);
    //root -> right -> left -> right = newNode(13);
    //root -> right -> right -> left = newNode(14);
    root -> right -> right -> right = newNode(15);
    
    cout << "Root to Leaf path using morris traversal : " << endl;
    rootToLeafUsingMorris(root);
    cout << endl;
}