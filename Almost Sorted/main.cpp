/*
 Author : Yeshwanth D S
 Problem Statement
 
 Given an array with n elements, can you sort this array in ascending order using only one of the following operations?
 
 Swap two elements.
 Reverse one sub-segment.
 Input Format
 The first line contains a single integer, n, which indicates the size of the array.
 The next line contains n integers separated by spaces.
 
 n
 d1 d2 ... dn
 Constraints
 2≤n≤100000
 0≤di ≤1000000
 All di are distinct.
 
 Output Format
 1. If the array is already sorted, output yes on the first line. You do not need to output anything else.
 
 If you can sort this array using one single operation (from the two permitted operations) then output yes on the first line and then:
 
 a. If you can sort the array by swapping dl and dr, output swap l r in the second line. l and r are the indices of the elements to be swapped, assuming that the array is indexed from 1 to n.
 
 b. Else if it is possible to sort the array by reversing the segment d[l...r], output reverse l r in the second line. l and r are the indices of the first and last elements of the subsequence to be reversed, assuming that the array is indexed from 1 to n.
 
 d[l...r] represents the sub-sequence of the array, beginning at index l and ending at index r, both inclusive.
 
 If an array can be sorted by either swapping or reversing, stick to the swap-based method.
 
 If you cannot sort the array in either of the above ways, output no in the first line.
 
 Sample Input #1
 
 2
 4 2
 Sample Output #1
 
 yes
 swap 1 2
 Sample Input #2
 
 3
 3 1 2
 Sample Output #2
 
 no
 Sample Input #3
 
 6
 1 5 4 3 2 6
 Sample Output #3
 
 yes
 reverse 2 5
 
 Problem Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/almost-sorted
 
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool isSorted(long arr[], long Max, long left, long right)
{
    while(left < right)
    {
        if(arr[left] > arr[left+1] && arr[right] < arr[right-1])
        {
            left++;
            right--;
        }
        else
            return false;
    }
    return true;
}

int main() {
    long n;
    cin>>n;
    long arr[n+2];
    arr[0] = -1;
    arr[n+1] = 1000001;
    for(long i=1;i<=n;i++)
        cin>>arr[i];
    long l = 1, r = n;
    bool sorted = true, NeedReverse;
    while(l<n)
    {
        if(arr[l]<arr[l+1])
            l++;
        if(arr[r]>arr[r-1])
            r--;
        if(arr[l] > arr[l+1] && arr[r] < arr[r-1])
        {
            sorted = false;
            NeedReverse = isSorted(arr,n,l,r);
            if(NeedReverse && (arr[r] > arr[l-1] && arr[l] < arr[r+1]) && r-l > 1)
            {
                cout<<"yes\nreverse "<<l<<' '<<r;
            }
            else
            {
                if(NeedReverse && (arr[r] > arr[l-1] && arr[l] < arr[r+1]) && r-l == 1)
                    cout<<"yes\nswap "<<l<<' '<<r;
                else if(arr[r]>arr[l-1] && arr[r]<arr[l+1] && arr[l]>arr[r-1] && arr[l]<arr[r+1])
                    cout<<"yes\nswap "<<l<<' '<<r;
                else
                    cout<<"no";
            }
            break;
        }
    }
    if(sorted)
        cout<<"yes";
    return 0;
}