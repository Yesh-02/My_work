/*
 Author : Yeshwanth D S
 Problem Statement
 
 This problem is a programming version of Problem 6 from projecteuler.net
 
 The sum of the squares of the first ten natural numbers is, 12+22+...+102=385. The square of the sum of the first ten natural numbers is, (1+2+⋯+10)2=552=3025. Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025−385=2640.
 
 Find the difference between the sum of the squares of the first N natural numbers and the square of the sum.
 
 Input Format
 First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.
 
 Output Format
 Print the required answer for each test case.
 
 Constraints
 1≤T≤104
 1≤N≤104
 
 Sample Input
 
 2
 3
 10
 Sample Output
 
 22
 2640
 
 Problem Source : hackerrank.com(Contest)
 problem Link : https://www.hackerrank.com/contests/projecteuler/challenges/euler006
 
 This program works on the fact that:
 
            (a+b)^2 = a^2 + b^2 + 2ab
            
            a+b)^2 - (a^2 + b^2) = 2ab   // move a^2 + b^2 left side..
 
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long sum = (n*(n+1))/2;
        long long prod = 0;
        int i=1;
        while(i<n)
        {
            sum-=i;
            prod+=2*i*(sum);
            i++;
        }
        cout<<prod<<endl;
    }
    return 0;
}