/*
Author : Yeshwanth D S
 Problem Statement
 
 Русский \| 中文
 Watson gives Sherlock an array A of length N. Then he asks him to determine if there exists an element in the array such that the sum of the elements on its left is equal to the sum of the elements on its right. If there are no elements to the left/right, then the sum is considered to be zero.
 Formally, find an i, such that, A1+A2...Ai-1 =Ai+1+Ai+2...AN.
 
 Input Format
 The first line contains T, the number of test cases. For each test case, the first line contains N, the number of elements in the array A. The second line for each test case contains N space-separated integers, denoting the array A.
 
 Output Format
 For each test case print YES if there exists an element in the array, such that the sum of the elements on its left is equal to the sum of the elements on its right; otherwise print NO.
 
 Constraints
 1≤T≤10
 1≤N≤105
 1≤Ai ≤2×104
 1≤i≤N
 Sample Input
 
 2
 3
 1 2 3
 4
 1 2 3 3
 Sample Output
 
 NO
 YES

 Source : Hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/sherlock-and-array
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long getSum(int arr[],long max)
{
    long long sum =0;
    for(long i=0;i<max;i++)
        sum+=arr[i];
    return sum;
}
string solve(int arr[],long max)
{
    long long sum = getSum(arr,max);
    long long lsum=0,rsum = 0;
    for(long i = 0;i < max;i++)
    {
        sum -= arr[i];
        rsum = sum;
        if(lsum == rsum)
            return "YES";
        lsum+=arr[i];
    }
    return "NO";
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        int arr[n];
        for(long i=0;i<n;i++)
            cin>>arr[i];
        cout<<solve(arr,n)<<endl;
    }
    return 0;
}