/*
 Author : Yeshwanth D S
 Problem Statement
 
 You are given an array of N integers which is a permutation of the first N natural numbers. You can swap any two elements of the array. You can make at most K swaps. What is the largest permutation, in numerical order, you can make?
 
 Input Format
 The first line of the input contains two integers, N and K, the size of the input array and the maximum swaps you can make, respectively. The second line of the input contains a permutation of the first N natural numbers.
 
 Output Format
 Print the lexicographically largest permutation you can make with at most K swaps.
 
 Constraints
 1≤N≤105
 1≤K≤109
 
 Sample Input#00
 
 5 1
 4 2 3 5 1
 Sample Output#00
 
 5 2 3 4 1
 Explanation#00
 You can swap any two numbers in [4,2,3,5,1] and see the largest permutation is [5,2,3,4,1]
 Sample Input#01
 
 3 1
 2 1 3
 Sample Output#01
 
 3 1 2
 Explanation#01
 With 1 swap we can get [1,2,3], [3,1,2] and [2,3,1] out of these [3,1,2] is the largest permutation.
 
 Sample Input#02
 
 2 1
 2 1
 Sample Output#02
 
 2 1
 Explanation#02
 We can see that [2,1] is already the largest permutation. So we don't need any swaps.
 
 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/largest-permutation
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void swap(long *arr,long l,long r)
{
    long temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}
void printArray(long arr[],long max)
{
    for(long i=1;i<=max;i++)
        cout<<arr[i]<<' ';
    cout<<endl;
}

int main() {
    long n,k;
    cin>>n>>k;
    long ind[n+1],val[n+1],temp1,temp2,count=0;
    for(long i = 1;i<=n;i++)
    {
        cin>>ind[i];
        val[ind[i]]=i;
    }
    for(long i = n;i>=1;i--)
    {
        if(val[i] == n-i+1)
            continue;
        else if(count<k)
        {
            temp1=ind[val[i]];
            temp2=ind[val[ind[n-i+1]]];
            swap(ind,val[i],val[ind[n-i+1]]);
            swap(val,temp1,temp2);
            count++;
        }
        else if(count >= k)
            break;
    }
    for(long i = 1;i<=n;i++)
        cout<<ind[i]<<' ';
    return 0;
}