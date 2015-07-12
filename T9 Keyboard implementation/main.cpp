#include<iostream>
using namespace std;
struct Tree
{
    char data;
    struct Tree *next[8];
}*head;
struct Tree* newNode(char ch)
{
    struct Tree *node = new Tree();
    node->data = ch;
    int i=7;
    while(i--)
        node->next[i] = head;
    return node;
}
struct Tree* createKeyboard()
{
    head = newNode('0');
    head->next[0]=newNode('A');
    head->next[0]->next[0]=newNode('B');
    head->next[0]->next[0]->next[0]=newNode('C');
    head->next[1]=newNode('D');
    head->next[1]->next[1]=newNode('E');
    head->next[1]->next[1]->next[1]=newNode('F');
    head->next[2]=newNode('G');
    head->next[2]->next[2]=newNode('H');
    head->next[2]->next[2]->next[2]=newNode('I');
    head->next[3]=newNode('J');
    head->next[3]->next[3]=newNode('K');
    head->next[3]->next[3]->next[3]=newNode('L');
    head->next[4]=newNode('M');
    head->next[4]->next[4]=newNode('N');
    head->next[4]->next[4]->next[4]=newNode('O');
    head->next[5]=newNode('P');
    head->next[5]->next[5]=newNode('Q');
    head->next[5]->next[5]->next[5]=newNode('R');
    head->next[5]->next[5]->next[5]->next[5]=newNode('S');
    head->next[6]=newNode('T');
    head->next[6]->next[6]=newNode('U');
    head->next[6]->next[6]->next[6]=newNode('V');
    head->next[7]=newNode('W');
    head->next[7]->next[7]=newNode('X');
    head->next[7]->next[7]->next[7]=newNode('Y');
    head->next[7]->next[7]->next[7]->next[7]=newNode('Z');
    return head;
}
void valueAt(char data,int count)
{
    if(data == '|')
        return;
    int param = data - '0';
    param-=2;
    struct Tree *temp=head;
    if(count == 0)
        cout<<temp->next[param]->data;
    else
    {
        while(count >= 0)
        {
            temp=temp->next[param];
            count--;
            if(temp == head)
                temp=temp->next[param];
        }
        cout<<temp->data;
    }
}
int main()
{
    head = createKeyboard();
    string input;
    char param;
    cin>>input;
    int i=0,j, size = input.length(),count;
    param = input[0];
    if(size == 1)
        valueAt(param,0);
    else if(size == 2 && input[0] == '|')
        valueAt(input[1],0);
    else
    {
        j=1;
        while(j <= size)
        {
            if(input[i] == ' ')
            {
                printf(" ");
                i++;
                j++;
            }
            else if(input[i] == '|')
            {
                i++;
                j++;
            }
            else if(input[j] == ' ')
            {
                valueAt(param,count);
                printf(" ");
                i=j+1;
                j+=2;
                param = input[i];
                count=0;
            }
            else if(input[j] == '|')
            {
                valueAt(param,count);
                i=j+1;
                j+=2;
                param = input[i];
                count=0;
            }
            else if(input[i]==input[j])
            {
                param = input[i];
                count++;
                j++;
            }
            else if(input[i]!=input[j])
            {
                valueAt(param,count);
                param = input[j];
                count=0;
                i=j;
                j++;
            }
            
        }
    }
    printf("\n");
    return 0;
}