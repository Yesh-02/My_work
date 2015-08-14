/*
 Author : Yeshwanth D S
 Problem Statement
 
 This problem is a programming version of Problem 4 from projecteuler.net
 
 A palindromic number reads the same both ways. The smallest 6 digit palindrome made from the product of two 3-digit numbers is 101101=143×707.
 
 Find the largest palindrome made from the product of two 3-digit numbers which is less than N.
 
 Input Format
 First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.
 
 Output Format
 Print the required answer for each test case in a new line.
 
 Constraints
 1≤T≤100
 101101<N<1000000
 Sample Input
 
 2
 101110
 800000
 Sample Output
 
 101101
 793397
 
 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/contests/projecteuler/challenges/euler004
 
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool isPal(int num)
{
    int digit, rev=0, ck_num;
    ck_num = num;
    while (num)
    {
        digit = num % 10;
        num /= 10;
        rev = rev * 10 + digit;
    }
    
    if (rev == ck_num)
        return true;
    else
        return false;
}

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        long N,max = 0;
        cin>>N;
        for(int i = 999;i >= 100;i--)
            for(int j=100 ;j <= 999;j++)
            {
                long temp = i*j;
                if(temp > N)
                    continue;
                if(isPal(temp) && temp > max)
                    max = temp;
            }
        cout<<max<<endl;
    }
    return 0;
}