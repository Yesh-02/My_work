#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

void printList(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        cout<<temp -> data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

struct node* mergeLists(struct node* head1, struct node* head2)
{
    struct node* node;
    if(head1 == NULL && head2 == NULL)
        return NULL;
    else if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    else
    {
        if(head1 -> data <= head2 -> data)
        {
            node = newNode(head1 -> data);
            node -> next = mergeLists(head1 -> next, head2);
        }
        else
        {
            node = newNode(head2 -> data);
            node -> next = mergeLists(head1 , head2 -> next);
        }
        return node;
    }
}

int main()
{
    struct node* head1 = newNode(1);
    head1 -> next = newNode(2);
    head1 -> next -> next = newNode(5);
    head1 -> next -> next -> next = newNode(7);
    struct node* head2 = newNode(2);
    head2 -> next = newNode(4);
    //head2 -> next -> next = newNode(6);
    //head2 -> next -> next -> next = newNode(8);
    
    printList(head1);
    printList(head2);
    
    struct node* head3 = mergeLists(head1,head2);
    
    printList(head3);
}