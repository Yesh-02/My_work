/*
 Author : Yeshwanth D S
 Problem Statement
 
 John Watson performs an operation called Right Circular Rotation on an integer array [a0,a1,...aN−1]. Right Circular Rotation transforms the array from [a0,a1,...aN−1] to [aN−1,a0,...,aN−2].
 
 He performs the operation K times and tests Sherlock's ability to identify the element at a particular position in the array. He asks Q queries. Each query consists of one integer, idx, for which you have to print the element at index idx in the rotated array, i.e. aidx.
 
 Input Format
 The first line consists of three integers, N, K, and Q,, separated by a single space.
 The next line contains N space-separated integers which indicate the elements of the array A.
 Each of the next Q lines contains one integer per line denoting idx.
 
 Output Format
 For each query, print the value at index idx in the updated array separated by newline.
 
 Constraints
 
 1≤N≤105
 1≤ai ≤105
 1≤K≤105
 1≤Q≤500
 0≤idx≤N−1
 Sample input
 
 3 2 3
 1 2 3
 0
 1
 2
 Sample output
 
 2
 3
 1
 
 Problem Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/sherlock-and-watson
 
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long n,k,idx;
    int q;
    cin>>n>>k>>q;
    k %= n;//missed this out ;)
    long arr[n]={0};
    for(long i=0;i<n;i++)
        cin>>arr[i];
    while(q--)
    {
        cin>>idx;
        idx -= k;
        if(idx < 0)
            idx = n + idx;
        cout<<arr[idx]<<endl;
    }
    return 0;
}