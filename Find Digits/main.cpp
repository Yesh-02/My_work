/*
 Author : Yeshwanth D S
 Problem Statement
 
 You are given an integer N. Find the digits in this number that exactly divide N (division that leaves 0 as remainder) and display their count. For N=24, there are 2 digits (2 & 4). Both of these digits exactly divide 24. So our answer is 2.
 
 Note
 
 If the same number is repeated twice at different positions, it should be counted twice, e.g., For N=122, 2 divides 122 exactly and occurs at ones' and tens' position. So for this case, our answer is 3.
 Division by 0 is undefined.
 Input Format
 
 The first line contains T (the number of test cases), followed by T lines (each containing an integer N).
 
 Constraints
 1≤T≤15
 0<N<1010
 Output Format
 
 For each test case, display the count of digits in N that exactly divide N in a separate line.
 
 Sample Input
 
 2
 12
 1012
 Sample Output
 
 2
 3
 
 Source : hackerrank.com
 
 problem link : https://www.hackerrank.com/challenges/find-digits;
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int findNum(long long int n)
{
    int temp=n,count=0,div;
    while(temp>=10)
    {
        div = temp%10;
        if(div != 0 && n%div == 0)
            count++;
        temp=temp/10;
    }
    if(temp != 0 && n%temp == 0)
        count++;
    return count;
}

int main() {
    int t;
    long long int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<findNum(n)<<endl;
    }
    return 0;
}