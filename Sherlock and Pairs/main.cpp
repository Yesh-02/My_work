/* 
Author : Yeshwanth D S
 Problem Statement
 
 Sherlock is given an array of N integers (A0, A1 ... AN−1 by Watson. Now Watson asks Sherlock how many different pairs of indices i and j exist such that i is not equal to j but Ai is equal to Aj.
 
 That is, Sherlock has to count the total number of pairs of indices (i,j) where Ai =Aj AND i≠j.
 
 Input Format
 The first line contains T, the number of test cases. T test cases follow.
 Each test case consists of two lines; the first line contains an integer N, the size of array, while the next line contains N space separated integers.
 
 Output Format
 For each test case, print the required answer on a different line.
 
 Constraints
 1≤T≤10
 1≤N≤105
 1≤A[i]≤106
 
 Sample input
 
 2
 3
 1 2 3
 3
 1 1 2
 Sample output
 
 0
 2
 
Source : hackerrank.com
Problem link : https://www.hackerrank.com/challenges/sherlock-and-pairs
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    long long n,cnt,tmp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[1000001]={0};
        cnt=0;
        for(long long i=0;i<n;i++)
        {
            cin>>tmp;
            ar[tmp]++;
        }
        for(long long i=1;i<=1000000;i++)
            if(ar[i]>=2)
                cnt+=(long long)ar[i]*(long long)(ar[i]-1);		
        cout<<cnt<<endl;
    }
    return 0;
}