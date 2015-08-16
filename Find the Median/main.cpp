/*
Author : Yeshwanth D S
 Problem Statement
 
 In the Quicksort challenges, you sorted an entire array. Sometimes, you just need specific information about a list of numbers, and doing a full sort would be unnecessary. Can you figure out a way to use your partition code to find the median in an array?
 
 Challenge
 Given a list of numbers, can you find the median?
 
 Input Format
 There will be two lines of input:
 
 n - the size of the array
 ar - n numbers that makes up the array
 Output Format
 Output one integer, the median.
 
 Constraints
 
 1≤n≤1000001
 n is odd
 −10000≤x≤10000,x∈ar
 Sample Input
 
 7
 0 1 2 4 6 5 3
 Sample Output
 
 3
 
 Problem Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/find-median
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
    
    for (int j = l; j <= h- 1; j++)
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
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

int main() {
    long n;
    cin>>n;
    int arr[n];
    for(long i=0;i<n;i++)
        cin>>arr[i];
    quickSort(arr,0,n-1);
    cout<<arr[n/2];
    return 0;
}