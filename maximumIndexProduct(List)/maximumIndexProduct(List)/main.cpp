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
    //cout<<"L="<<cur_data<<endl;
    temp=temp->prev;
    if(node->data < temp->data && run !=1)
        return prevl;
    else if((node->data > temp->data && node->data < prevl))
        return prevl;
    while(temp != NULL)
    {
        run=0;
        if(temp->data > cur_data)
        {
            //cout<<"cur data:"<<cur_data<<' '<<"temp data:"<<temp->data<<endl;
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
    //cout<<"R="<<cur_data<<endl;
    struct Node *temp = node;
    temp=temp->next;
    if(node->prev->data > node->data && run != 1)
        return prevr;
    else if(node->data > node->prev->data && node->data < prevr)
        return prevr;
    while(temp != NULL)
    {
        run=0;
        if(temp->data > cur_data)
        {
            //cout<<"cur data:"<<cur_data<<' '<<"temp data:"<<temp->data<<endl;
            prevr = temp->index;
            return prevr;
        }
        temp = temp->next;
    }
    return 0;
}
long long findMaxIndexProd()
{
    long long max_prod = 0,prod = 1;
    struct Node *temp = head;
    if(temp->next != NULL)
        temp = temp->next;
    while(temp->next != NULL)
    {
        //cout<<"pass:"<<temp->data<<endl;
        long left,right;
        left = findLeft(temp);
        if(left != 0)
            right = findRight(temp);
        else
            right = 0;
        //cout<<"max left = "<<left<<' '<<"MAx reight = "<<right<<endl;
        prod = left*right;
        //cout<<"prod = "<<prod<<endl;
        if(prod > max_prod)
            max_prod = prod;
        //cout<<"Max prod = "<<max_prod<<endl;
        temp=temp->next;
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
    print();
    head=alterList(head);
    cout<<"end";
    cout<<findMaxIndexProd()<<endl;
    cout<<((double)clock() - t)/CLOCKS_PER_SEC;
    return 0;
}