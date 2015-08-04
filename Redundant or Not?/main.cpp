/*
 Author : Yeshwanth D S
 Problem Statement
 
 You are given a list of N numbers, {a1,a2,…,aN}, to be added to a database.
 Each of these numbers must be added to the database in the order in which they are given.
 If a number has already been added to the database, print "REDUNDANT" (without quotation marks).
 Otherwise, add it to the database and print "ADDED"(again, without quotation marks).
 The answer of each operation should be printed in a new line.
 
 Input Format
 
 The first line contains a single integer N, denoting the number of numbers to be added.
 The second line contains the N space-separated integers - a1,a2,…aN.
 
 Output Format
 
 N lines, each having the answer to the subsequent operation.
 
 Constraints
 
 1≤N≤105
 −109≤ai≤109, where i∈[1,N]
 Sample Input
 
 5
 4
 3
 -3
 3
 100000
 Sample Output
 
 ADDED
 ADDED
 ADDED
 REDUNDANT
 ADDED
 
 
 Source : hackerrank.com(Contest)
 
 Problem Link : https://www.hackerrank.com/contests/code-cpp-may-2015/challenges/redundant-or-not
 
 */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long int N;
    cin>>N;
    long long arr[100001]={0},temp;
    for(long i = 0; i < N; i++)
    {
        cin>>temp;
        if(temp>=0)
        {
            if(arr[temp] == 0)
            {
                arr[temp] = 1;
                cout<<"ADDED"<<endl;
            }
            else if(arr[temp] == -1)
            {
                arr[temp] = 2;
                cout<<"ADDED"<<endl;
            }
            else if(arr[temp] == 1 || arr[temp] == 2)
                cout<<"REDUNDANT"<<endl;
        }
        else
        {
            if(arr[-temp] == 0)
            {
                arr[-temp] = -1;
                cout<<"ADDED"<<endl;
            }
            else if(arr[-temp] == 1)
            {
                arr[-temp] = 2;
                cout<<"ADDED"<<endl;
            }
            else if(arr[-temp] == -1 || arr[-temp] == 2)
                cout<<"REDUNDANT"<<endl;
        }
    }
    return 0;
}