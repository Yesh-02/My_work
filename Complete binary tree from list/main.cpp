#include<iostream>
#include<queue>
using namespace std;

struct tnode
{
    int data;
    struct tnode* left;
    struct tnode* right;
};

struct lnode
{
    int data;
    struct lnode* next;
};

struct lnode* lnewNode(int data)
{
    struct lnode* temp = new struct lnode();
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

struct tnode* tnewNode(int data)
{
    struct tnode* temp = new struct tnode();
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

struct tnode* createTree(struct lnode* head, struct tnode* root)
{
    if(head == NULL)
        return NULL;
    
    queue <struct tnode*> queue;
    
    root = tnewNode(head -> data);
    queue.push(root);
    
    while(!queue.empty())
    {
        struct tnode * temp = queue.front();
        cout<<"Popped "<<temp -> data<<" from queue\n";
        queue.pop();
        
        if(head -> next)
            head = head -> next;
        else
            return root;
        temp -> left = tnewNode(head -> data);
        queue.push(temp -> left);
        cout<<"Pushed left value: "<<temp -> left -> data<<" into queue\n";
        
        if(head -> next)
            head = head -> next;
        else
            return root;
        temp -> right = tnewNode(head -> data);
        cout<<"Pushed right value: "<<temp -> right -> data<<" into queue\n";
        queue.push(temp->right);
    }
    return root;
}

void printTree(struct tnode* root, char n)
{
    if(root == NULL)
        return;
    else
        cout << root->data << n <<' ';
    printTree(root -> left, 'l');
    printTree(root -> right, 'r');
}

void levelOrder(struct tnode* root)
{
    queue<struct tnode*> queue;
    
    queue.push(root);
    
    while (!queue.empty())
    {
        struct tnode* temp = queue.front();
        
        queue.pop();
        
        printf("%d ", temp->data);
        
        if (temp->left)
            queue.push(temp -> left);
        if (temp->right)
            queue.push(temp -> right);
    }
}

void printList(struct lnode* head)
{
    struct lnode* temp = head;
    while(temp)
    {
        cout<<temp -> data << "->";
        temp = temp-> next;
    }
    cout<<"NULL\n";
}

int main()
{
    struct lnode* head = lnewNode(1);
    head -> next = lnewNode(2);
    head -> next -> next = lnewNode(3);
    head -> next -> next -> next = lnewNode(4);
    head -> next -> next -> next -> next = lnewNode(5);
    head -> next -> next -> next -> next -> next = lnewNode(6);
    
    struct tnode* root = createTree(head,root);
    
    cout<<"List:"<<endl;
    
    printList(head);
    
    cout<<"Preorder :"<<endl;
    
    printTree(root,'r');
    
    cout<<"\nLevel Order :"<<endl;
    
    levelOrder(root);
    
}