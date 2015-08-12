/*
 Author : Yeshwanth D S
 Problem Statement
 
 Sansa has an array. She wants to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-ing the values thus obtained. Can you help her in this task?
 
 Note : [5,7,5] is contiguous subarray of [4,5,7,5] while [4,7,5] is not.
 
 Input Format
 First line contains an integer T, number of the test cases.
 The first line of each test case contains an integer N, number of elements in the array.
 The second line of each test case contains N integers that are elements of the array.
 
 Output Format
 Print the answer corresponding to each test case in a seperate line.
 
 Constraints
 1≤T≤5
 2≤N≤105
 1≤numbers in array≤108
 
 Sample Input
 
 2
 3
 1 2 3
 4
 4 5 7 5
 Sample Output
 
 2
 0
 
 Source : Hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/sansa-and-xor
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
    while(T--)
    {
        long N,temp,ans = 0;
        cin>>N;
        if(N%2==0)
        {
            for(long i=0;i<N;i++)
                cin>>temp;
        }
        else
        {
            for(long i=0;i<N;i++)
            {
                cin>>temp;
                if(i%2==0)
                    ans^=temp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}