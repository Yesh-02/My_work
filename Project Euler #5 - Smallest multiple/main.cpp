/*
 Author : Yeshwanth D S
 Problem Statement
 
 This problem is a programming version of Problem 5 from projecteuler.net
 
 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 What is the smallest positive number that is evenly divisible(divisible with no remainder) by all of the numbers from 1 to N?
 
 Input Format
 First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.
 
 Output Format
 Print the required answer for each test case.
 
 Constraints
 1≤T≤10
 1≤N≤40
 
 Sample Input
 
 2
 3
 10
 Sample Output
 
 6
 2520
 
 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/contests/projecteuler/challenges/euler005
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    int arr[41]={0};
    arr[1] = 1;
    for(int i=2;i<=40;i++)
        if(arr[i] == 0)
        {
            arr[i]=i;
            for(int j=2*i;j<=40;j+=i)
                arr[j] = 1;
            for(int j=i*i;j<=40;j*=i)
                arr[j] = i;
        }
    while(T--)
    {
        int N;
        long prod = 1;
        cin>>N;
        for(int i=1;i<=N;i++)
            prod*=arr[i];
        cout<<prod<<endl;
    }
    return 0;
}