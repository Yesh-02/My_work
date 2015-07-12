/*
 Author : Yeshwanth D S
 Problem Statement
 
 You are given N sticks, where the length of each stick is a positive integer. A cut operation is performed on the sticks such that all of them are reduced by the length of the smallest stick.
 
 Suppose we have six sticks of the following lengths:
 
 5 4 4 2 2 8
 Then, in one cut operation we make a cut of length 2 from each of the six sticks. For the next cut operation four sticks are left (of non-zero length), whose lengths are the following:
 
 3 2 2 6
 The above step is repeated until no sticks are left.
 
 Given the length of N sticks, print the number of sticks that are left before each subsequent cut operations.
 
 Note: For each cut operation, you have to recalcuate the length of smallest sticks (excluding zero-length sticks).
 
 Input Format
 The first line contains a single integer N.
 The next line contains N integers: a0, a1,...aN-1 separated by space, where ai represents the length of ith stick.
 
 Output Format
 For each operation, print the number of sticks that are cut, on separate lines.
 
 Constraints
 1 ≤ N ≤ 1000
 1 ≤ ai ≤ 1000
 
 Sample Input #00
 
 6
 5 4 4 2 2 8
 Sample Output #00
 
 6
 4
 2
 1
 Sample Input #01
 
 8
 1 2 3 4 3 3 2 1
 Sample Output #01
 
 8
 6
 4
 1
 
 Source : HAckerrank.com
 Problem link : https://www.hackerrank.com/challenges/cut-the-sticks
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int getMin(int sticks[] , int n)
{
    int min=1001;
    for(int i=0;i<n;i++)
        if(sticks[i]==0)
            continue;
        else if(sticks[i]<min)
            min = sticks[i];
    return min;
}
void getAnswer(int sticks[],int n)
{
    int min = getMin(sticks,n),count=0;
    for(int i=0;i<n;i++)
        if(sticks[i]!=0)
        {
            sticks[i]-=min;
            count++;
        }
    if(count==0)
        return;
    else
        cout<<count<<endl;
    getAnswer(sticks,n);
}
int main() {
    int n;
    cin>>n;
    int sticks[n];
    for(int i=0;i<n;i++)
        cin>>sticks[i];
    getAnswer(sticks,n);
    return 0;
}