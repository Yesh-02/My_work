/*
 Author : Yeshwanth D S
 Problem Statement
 
 Sorting is often useful as the first step in many different tasks. The most common task is to make finding things easier, but there are other uses, as well.
 
 Challenge
 Given a list of unsorted integers, A={a1,a2,…,aN}, can you find the pair of elements that have the smallest absolute difference between them? If there are multiple pairs, find them all.
 
 Input Format
 The first line of input contains a single integer, N, representing the length of array A.
 In the second line, there are N space-separated integers, a1,a2,…,aN, representing the elements of array A.
 
 Output Format
 Output the pairs of elements with the smallest difference. If there are multiple pairs, output all of them in ascending order, all on the same line (consecutively) with just a single space between each pair of numbers. If there's a number which lies in two pair, print it two times (see the sample case #3 for explanation).
 
 Constraints
 
 2≤N≤200000
 −107≤ai≤107
 ai≠aj,where 1≤i<j≤N
 Sample Input #1
 
 10
 -20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854
 Sample Output #1
 
 -20 30
 Explanation
 (30) - (-20) = 50, which is the smallest difference.
 
 Sample Input #2
 
 12
 -20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854 -520 -470
 Sample Output #2
 
 -520 -470 -20 30

 Problem Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/closest-numbers

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void swap(long* a, long* b)
{
    long t = *a;
    *a = *b;
    *b = t;
}
int partition (long arr[], long l, long h)
{
    long x = arr[h];
    long i = (l - 1);
    
    for (long j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
void quickSort(long arr[], long l, long h)
{
    if (l < h)
    {
        long p = partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}
void printPairs(long arr[],long n)
{
    vector <long> ans;
    long min = 99999999,i=0,j=1;
    quickSort(arr,0,n-1);
    while(j<n)
    {
        if(i == j)
            j++;
        long diff = abs(arr[i] - arr[j]);
        if(diff <= min)
        {
            if(diff < min)
                ans.clear();
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
            min = diff;
            j++;
        }
        else
            i++;
    }
    vector <long> ::iterator it;
    for(it = ans.begin();it != ans.end();it++)
        cout<<*it<<' ';
}
int main() {
    long n,temp;
    cin>>n;
    long arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    printPairs(arr,n);
    return 0;
}