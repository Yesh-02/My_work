/*
 Author : Yeshwanth D S
 Problem Statement
 
 A modified Kaprekar number is a positive whole number n with d digits, such that when we split its square into two pieces - a right hand piece r with d digits and a left hand piece l that contains the remaining d or d−1 digits, the sum of the pieces is equal to the original number (i.e. l + r = n).
 
 Alternatively, a modified Kaprekar number is a positive whole number n with 2d digits (if its number of digits is even) or 2d + 1 digits (if its number of digits is odd), such that when we split its square into two pieces, a right hand piece r containing d or d + 1 digits, and a left piece l containing the remaining d digits, the sum of the two pieces is equal to the original number.
 
 Note: r may have leading zeros.
 
 Here's an alternative explanation from Wikipedia: In mathematics, a Kaprekar number for a given base is a non-negative integer, the representation of whose square in that base can be split into two parts that add up to the original number again. For instance, 45 is a Kaprekar number, because 45² = 2025 and 20+25 = 45.
 
 The Task
 You are given the two positive integers p and q, where p is lower than q. Write a program to determine how many Kaprekar numbers are there in the range between p and q (both inclusive) and display them all.
 
 Input Format
 
 There will be two lines of input: p, lowest value q, highest value
 
 Constraints:
 0<p<q<100000
 Output Format
 
 Output each Kaprekar number in the given range, space-separated on a single line. If no Kaprekar numbers exist in the given range, print INVALID RANGE.
 
 Sample Input
 
 1
 100
 Sample Output
 
 1 9 45 55 99
 
 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/kaprekar-numbers
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int p,q;
    cin>>p>>q;
    long long int prod;
    int count=0;
    for(int i=p;i<=q;i++)
    {
        prod = pow(i,2);
        string str = to_string(prod);
        int len = str.length();
        string l,r;
        l=str.substr(0,(len/2));
        if(len%2 != 0)
            r=str.substr((len/2),(len/2)+1);
        else
        r=str.substr((len/2),len/2);
        int l_len=l.length(),r_len=r.length();
        long long int temp=1;
        if(str.length()%2 != 0)
            l_len++;
        while(l_len--)
            temp*=10;
        if(((prod/temp)+(prod%temp)) == i)
        {
            cout<<i<<' ';
            count++;
        }
    }
    if(count==0)
        cout<<"INVALID RANGE";
    return 0;
}
