/*
 Author : Yeshwanth D S
 Problem Statement
 
 You will be given two integers A and B. You are required to compute the bitwise AND amongst all natural numbers lying between A and B, both inclusive.
 
 Input Format
 
 First line of the input contains T, the number of testcases to follow.
 Each testcase in a newline contains A and B separated by a single space.
 
 Constraints
 
 1≤T≤200
 0≤A≤B<232
 Output Format
 
 Output one line per test case with the required bitwise AND.
 
 Sample Input
 
 3
 12 15
 2 3
 8 13
 Sample Output
 
 12
 2
 8
 
 Source : hackerrank.com
 
 Problem Link : https://www.hackerrank.com/challenges/and-product
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long getClosestNum(unsigned long long A,int *power)
{
    unsigned long long num = 1; int count=0;
    for(num;num < A; num*=2)
        count++;
    *power = count;
    return num;
}

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        unsigned long long A,B;
        cin>>A>>B;
        if(A == 0 || B == 0)
        {
            cout<<0<<endl;
            continue;
        }
        int power=0;
        unsigned long long closestNum = getClosestNum(A,&power),ans = A;
        if(closestNum > A && closestNum <= B)
            ans = 0;
        else
            if(B >= (1L<<power+1))
                ans = 0;
            else
            {
                while(A<B)
                {
                    ans &= (A&B);
                    A++;
                    B--;
                }
            }
        cout<<ans<<endl;
    }
    return 0;
}