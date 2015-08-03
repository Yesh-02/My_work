/*
 Author : Yeshwanth D S
 Problem statement:
    Implementing a hashtable
 Problem source : self
 */

#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node * createList(struct node * head,int data)
{
    struct node * newNode = new struct node(),*cur;
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
        cur = newNode;
    }
    else
    {
        cur->next = newNode;
        cur = newNode;
    }
    return head;
}
void printList(struct node * head)
{
    struct node * temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    struct node * hashmap[100]={0};
    for(int i=0;i<10;i++)
        for(int j=0;j<500;j++)
            hashmap[i]=createList(hashmap[i],j*i);
    for(int i=0;i<10;i++)
            printList(hashmap[i]);
}