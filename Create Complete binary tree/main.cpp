#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* temp = new struct node();
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}
struct node* insertNode(struct node** arr, int index, int data)
{
    int x;
    if(index == 0)
    {
        arr[index] = newNode(data);
        return arr[index];
    }
    else if(index % 2 == 0)
    {
        x = (index - 2)/2;
        arr[index] = newNode(data);
        arr[x] -> right = arr[index];
        return arr[0];
    }
    else
    {
        x = (index - 1)/2;
        arr[index] = newNode(data);
        arr[x] -> left = arr[index];
        return arr[0];
    }
    
}

void printTree(struct node* root)
{
    if(root == NULL)
        return;
    else
        cout << root->data <<' ';
    printTree(root -> left);
    printTree(root -> right);
}

void levelOrder(struct node* root)
{
    queue<struct node*> queue;
    
    queue.push(root);
    
    while (!queue.empty())
    {
        struct node* temp = queue.front();
        
        queue.pop();
        
        printf("%d ", temp->data);
        
        if (temp->right)
            queue.push(temp -> right);
        
        if (temp->left)
            queue.push(temp -> left);
        
        
    }
}

int main()
{
    struct node** arr = (struct node**)calloc(500,sizeof(struct node));
    struct node* root;
    int i=0;
    int count = 15;
    
    while(count--)
    {
        root = insertNode(arr,i,15 - count);
        i++;
    }
    cout<<"Pre0rder:"<<endl;
    
    printTree(root);
    
    cout<<endl;
    
    cout<<"Level Order:"<<endl;
    
    levelOrder(root);
    
    return 0;
}