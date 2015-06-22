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
    struct Node *rNext;
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
        nNode->rNext = NULL;
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
        nNode->rNext = NULL;
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
    long long cur_data = node->data;
    struct Node *temp = node;
    cout<<"L="<<cur_data<<endl;
    if(node->rNext != NULL)
        if(node->rNext->prev != NULL)
            temp=node->rNext->prev;
        else
            return 0;
    else
        temp=temp->prev;
    if(temp == NULL)
    {
        return prevl;
    }
    else if(node->data < temp->data)
    {
        if(node->index == 2)
            return 1;
        return prevl;
    }
    else if((node->data > temp->data && node->data < prevl))
        return prevl;
    while(temp != NULL)
    {
        if(temp->data > cur_data)
        {
            cout<<"cur data:"<<cur_data<<' '<<"temp data:"<<temp->data<<endl;
            prevl = temp->index;
            cout<<"L = "<<prevl<<endl;
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
    cout<<"R="<<cur_data<<endl;
    struct Node *temp = node;
    temp=temp->next;
    if(node->prev == NULL)
        NULL;
    else if(node->prev->data > node->data)
        return prevr;
    else if(node->data > node->prev->data && node->data < prevr && node->index != 2)
        return prevr;
    while(temp != NULL)
    {
        if(temp->data > cur_data)
        {
            cout<<"cur data:"<<cur_data<<' '<<"temp data:"<<temp->data<<endl;
            prevr = temp->index;
            temp->rNext = node;
            cout<<"R = "<<prevr<<endl;
            cout<<temp->data<<"->"<<temp->rNext->data<<endl;
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
    //if(temp->next != NULL)
        //temp = temp->next;
    while(temp->next != NULL)
    {
        cout<<"pass:"<<temp->data<<endl;
        long left,right;
        right = findRight(temp);
        if(right != 0)
        {
            left = findLeft(temp);
            prod = left*right;
            temp=temp->next;
        }
        else
        {
            temp=temp->next;
            cout<<"end"<<endl<<endl<<endl;
            continue;
        }
        cout<<"max left = "<<left<<' '<<"MAx reight = "<<right<<endl;
        cout<<"prod = "<<prod<<endl;
        if(prod > max_prod)
            max_prod = prod;
        cout<<"Max prod = "<<max_prod<<endl;
        cout<<"end"<<endl;
        cout<<endl;
    }
    return max_prod;
}
void print()
{
    struct Node *temp=head;
    cout<<"head to tail"<<endl;
    while(temp->next != NULL)
    {
        cout<<'|'<<temp->index<<','<<temp->data<<'|'<<"->";
        temp=temp->next;
    }
    cout<<'|'<<temp->index<<','<<temp->data<<'|'<<temp->next<<endl;
    cout<<"tail to head"<<endl;
    while(temp->prev != NULL)
    {
        cout<<'|'<<temp->index<<','<<temp->data<<'|'<<"->";
        temp=temp->prev;
    }
    cout<<'|'<<temp->index<<','<<temp->data<<'|'<<temp->prev<<endl;
}
struct Node* alterList(struct Node *head)
{
    struct Node *curr = head,*next = curr->next;
    while(next != NULL)
    {
        while(curr->data == next->data && next != NULL)
                next = next->next;
        if(curr->next != next)
        {
            curr->next = next;
            next->prev = curr;
        }
        curr=curr->next;
        next=next->next;
    }
    return head;
}
int main()
{
    long N,count=0;
    clock_t t;
    t = clock();
    cin>>N;
    for(long i = 0 ; i < N ; i++)
    {
        long data;
        cin>>data;
        count++;
        head=createNode(data);
    }
    //print();
    cout<<"read in "<<((double)clock() - t)/CLOCKS_PER_SEC<<endl;
    //head=alterList(head);
    cout<<findMaxIndexProd()<<endl;
    cout<<"completed in "<<((double)clock() - t)/CLOCKS_PER_SEC;
    return 0;
}