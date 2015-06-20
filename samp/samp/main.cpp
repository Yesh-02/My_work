#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    long long data;
    long index;
    struct Node *next;
    struct Node *prev;
}*head=NULL;
struct Node* createNode(long long data)
{
    static struct Node *sHead = head,*tail = head;
    struct Node *nNode = new Node();
    static long new_ind = 1;
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
long findLeft(struct Node *node)
{
    static long prevl = 0;
    int run = 1;
    long long cur_data = node->data;
    struct Node *temp = node;
    temp=temp->prev;
    if(node->data < temp->data && run !=1)
        return prevl;
    while(temp != NULL)
    {
        run=0;
        if(temp->data > cur_data)
        {
            prevl = temp->index;
            return prevl;
        }
        temp = temp->prev;
    }
    return 0;
}
long findRight(struct Node *node)
{
    long long cur_data = node->data;
    static long prevr = 0;
    int run = 1;
    struct Node *temp = node;
    temp=temp->next;
    if(node->prev->data > node->data && run != 1)
        return prevr;
    while(temp != NULL)
    {
        run=0;
        if(temp->data > cur_data)
        {
            prevr = temp->index;
            return prevr;
        }
        temp = temp->next;
    }
    return 0;
}
long long findMaxIndexProd()
{
    long long max_prod = 0,prod = 0;
    struct Node *temp = head;
    if(temp->next != NULL)
        temp = temp->next;
    while(temp->next != NULL)
    {
        long left,right;
        left = findLeft(temp);
        if(left != 0)
        {
            right = findRight(temp);
            prod = left*right;
            temp=temp->next;
        }
        else
        {
            temp=temp->next;
            continue;
        }
        if(prod > max_prod)
            max_prod = prod;
    }
    return max_prod;
}
int main()
{
    long N;
    cin>>N;
    clock_t t = clock();
    for(long i = 0 ; i < N ; i++)
    {
        int data;
        cin>>data;
        head=createNode(data);
    }
    cout<<"input read time:"<<((double)clock()-t)/CLOCKS_PER_SEC<<endl;
    cout<<findMaxIndexProd()<<endl;
    cout<<"total time:"<<((double)clock()-t)/CLOCKS_PER_SEC;
    return 0;
}