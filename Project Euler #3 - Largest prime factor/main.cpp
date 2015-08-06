/*
 Author : Yeshwanth D S
 Problem Statement
 
 This problem is a programming version of Problem 3 from projecteuler.net
 
 The prime factors of 13195 are 5, 7, 13 and 29.
 
 What is the largest prime factor of a given number N?
 
 Input Format
 First line contains T, the number of test cases. This is followed by T lines each containing an integer N.
 
 Output Format
 For each test case, display the largest prime factor of N.
 
 Constraints
 1≤T≤10
 10≤N≤1012
 Sample Input
 
 2
 10
 17
 Sample Output
 
 5
 17
 
 Problem source : hackerrank.com (Contest)
 
 Problem link : https://www.hackerrank.com/contests/projecteuler/challenges/euler003

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long largestPrimeFactor(long long  n)
{
    if(n == 0 || n == 2 )
        return n;
    while (n%2 == 0)
        n = n/2;
    if(n == 1)
        return 2;
    long i;
    for (i = 3; i <= sqrt(n); i += 2)
    {
        while (n%i == 0)
            n = n/i;
        if(n == 1)
            break;
    }
    if (n > 2)
        return n;
    else
        return i;
}

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        long long N;
        cin>>N;
        cout<<largestPrimeFactor(N)<<endl;
    }
    return 0;
}
