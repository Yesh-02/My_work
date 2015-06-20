#include<iostream>
using namespace std;
struct Node
{
    long long int data;
    int index;
    struct Node *next;
    struct Node *prev;
}*head,*head1;
struct Node* createNode(struct Node *head,int data)
{
    struct Node *temp=head,*nNode= new Node();
    static int ind=0;
    if(head == NULL)
    {
        nNode->data = data;
        nNode->index = ind;
        nNode->next = NULL;
        nNode->prev = NULL;
        ind++;
        return nNode;
    }
    else if(temp->next == NULL)
    {
        nNode->data = data;
        nNode->index = ind;
        nNode->next = NULL;
        nNode->prev = NULL;
        ind++;
        temp->next = nNode;
        nNode->prev = temp;
        return temp;
    }
    else
    {
        while(temp->next != NULL)
            temp=temp->next;
        temp = createNode(temp,data);
        return head;
    }
}
struct Node* createNode(int data)
{
    static struct Node *sHead =head1,*tail=head1;
    struct Node *nNode= new Node();
    static int new_ind=0;
    if(sHead == NULL)
    {
        nNode->data = data;
        nNode->index = new_ind;
        nNode->next = NULL;
        nNode->prev = NULL;
        new_ind++;
        sHead=nNode;
        tail=nNode;
    }
    else
    {
        nNode->data = data;
        nNode->index = new_ind;
        nNode->next = NULL;
        nNode->prev = NULL;
        new_ind++;
        tail->next = nNode;
        nNode->prev = tail;
        tail=tail->next;
    }
    return sHead;
}
void print(struct Node *head)
{
    struct Node *temp = head;
    while(temp!= NULL)
    {
        cout<<'|'<<temp->data<<'|'<<temp->index<<'|'<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    int i=10;
    while(i--)
    {
        head=createNode(head,i);
        head1=createNode(i);
    }
    print(head);
    print(head1);
    cout<<sizeof(int)<<endl;
    cout<<sizeof(long int);
    return 0;
}