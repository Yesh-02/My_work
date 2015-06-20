#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
}head;
Node* SortedInsert(Node *head,int data)
{
    struct Node *nNode = (struct Node*)malloc(sizeof(struct Node)), *temp = head,*cur;
    nNode->data = data;
    nNode->next = NULL;
    nNode->prev = NULL;
    if(head == NULL)
        return nNode;
    while(temp->data < data && temp->next != NULL)
    {
        temp=temp->next;
    }
    cur=temp->prev;
    nNode->next = temp;
    nNode->prev = cur;
    if(cur)
    cur->next = nNode;
    temp->prev = nNode;
    return head;
}
void printNodes(struct Node *head)
{
    struct Node *temp=head;
    while(temp->next)
    {
        cout<<temp->data<<' ';
        temp=temp->next;
    }
}
int main(int argc, const char * argv[])
{
    SortedInsert(&head,1);
    SortedInsert(&head,3);
    SortedInsert(&head,5);
    SortedInsert(&head,7);
    SortedInsert(&head,9);
    SortedInsert(&head,11);
    SortedInsert(&head,13);
    SortedInsert(&head,15);
    SortedInsert(&head,17);
    printNodes(&head);
    return 0;
}
