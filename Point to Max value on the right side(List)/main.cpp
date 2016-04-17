/*
 
 Author : Yeshwanth D.S
 
 Problem Description : 
 Given singly linked list with every node having an additional “arbitrary” pointer that currently points to NULL. We need to make the “arbitrary” pointer to greatest value node in a linked list on its right side.
 
 Problem Source : http://www.geeksforgeeks.org/
 
 Problem Link : http://www.geeksforgeeks.org/point-arbit-pointer-greatest-value-right-side-node-linked-list/
 
 */

#include<iostream>
#include<stack>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* a_next;
};

struct node* newNode(int data)
{
    struct node* temp = new node();
    
    temp -> data = data;
    temp -> next = NULL;
    temp -> a_next = NULL;
    
    return temp;
}

void printNextArbitPointers(struct node *node)
{
    printf("Node\tNext Pointer\tArbit Pointer\n");
    while (node != NULL)
    {
        cout << node->data << "\t\t";
        
        if(node->next)
            cout << node->next->data << "\t\t";
        else cout << "NULL" << "\t\t";
        
        if(node->a_next)
            cout << node->a_next->data;
        else cout << "NULL";
        
        cout << endl;
        node = node -> next;
    }
}

void _populateArbitatyNext(struct node* head, struct node **grt)
{
    if(!head)
        return;
    if(head -> next == NULL)
    {
        *grt = head;
        return ;
    }
    
    _populateArbitatyNext(head -> next, grt);

    head -> a_next = *grt;
    
    if((*grt) -> data < head -> data)
        *grt = head;
}

struct node* populateArbitatyNext(struct node *head)
{
    if(!head)
        return NULL;
    
    struct node *grt = NULL;
    _populateArbitatyNext(head, &grt);
    return head;
}

int main()
{
    struct node *head = newNode(5);
    head->next = newNode(10);
    head->next->next = newNode(2);
    head->next->next->next = newNode(3);
    
    head = populateArbitatyNext(head);
    
    printNextArbitPointers(head);
}