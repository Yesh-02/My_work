/*
 Author : Yeshwanth D S
 Problem Statement
 
 You have to complete a function getNumber which receives a single argument H, where H is the head of a linked list. Each node of the linked list contains an integer which is either 1 or 0. Placing all the integers present in the linked list in a order from left to right, forms a binary number. Return the decimal representation of the binary number to the base 10.
 
 You have to add a function with the following definition
 
 long long getNumber(Node *head) {
 // Complete this function
 }
 Input Format
 
 First line of input will contain the length of linked list, N.
 In second line, there are N space separated integers, where each integer is either 0 or 1. The ith value represents the data at the corresponding node.
 
 Output Format
 
 Print the decimal format of integer represented by list.
 
 Constraints
 
 1≤N≤63
 Data at each node will be either 0 or 1
 The input can have preceding zeros.
 Input/output will be handled by us. Don't print anything in the code.
 Sample Input
 
 7
 0 0 1 1 0 1 0
 Sample Output
 
 26
 
 Source : hackerrank.com (Contest)
 
 Problem Link : https://www.hackerrank.com/contests/code-cpp-may-2015/challenges/linked-list-to-binary
 
 */

#include <iostream>
using namespace std;

class Node {
public:
    Node *next;
    int data;
};

Node* insertIntoList(Node *cur, int data) {
    if(cur == nullptr) {
        cur = new Node();
        cur->data = data;
        cur->next = nullptr;
    }
    else {
        cur->next = insertIntoList(cur->next, data);
    }
    return cur;
}
unsigned long long getDecimal(char num[],int max)
{
    unsigned long long mul=1,res=0;
    while(max--)
    {
        res+=mul*(num[max]-'0');
        mul*=2;
    }
    return res;
}
unsigned long long getNumber(Node *head) {
    Node *temp = head;
    char num[64]={},*ptr = num;
    int count = 0;
    while(temp != nullptr)
    {
        if(temp->data == 1)
            break;
        temp=temp->next;
    }
    while(temp != nullptr)
    {
        *ptr = temp->data + '0';
        ptr++;
        count++;
        temp=temp->next;
    }
    return getDecimal(num,count);
}
int main()
{
    int N;
    cin >> N;
    Node *head = nullptr;
    
    for(int i = 0; i < (int)N; ++i) {
        int curData;
        cin >> curData;
        head = insertIntoList(head, curData);
    }
    
    cout << getNumber(head) << endl;
    
    return 0;
}