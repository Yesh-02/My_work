/*
 Author : Yeshwanth D S
 Problem Statement
 
 This problem is a programming version of Problem 1 from projecteuler.net
 
 If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 
 Find the sum of all the multiples of 3 or 5 below N.
 
 Input Format
 First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.
 
 Output Format
 For each test case, print an integer that denotes the sum of all the multiples of 3 or 5 below N.
 
 Constraints
 1≤T≤105
 1≤N≤109
 
 Sample Input
 
 2
 10
 100
 Sample Output
 
 23
 2318
 
 
 Source : hackerrank.com (Contest)
 
 problem Link : https://www.hackerrank.com/contests/projecteuler/challenges/euler001
 
 
 complexity of this problem is O(1). It uses the AP Formula..
 
 Sum of N numbers = total number of numbers to be added * (first number + last number) / 2;
 
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int i3 = 3,i5 = 5,i15 = 15;
        long long n3 = ((N%3==0)?floor(N/3)-1:floor(N/3)),n5 = ((N%5==0)?floor(N/5)-1:floor(N/5)),n15 = ((N%15==0)?floor(N/15)-1:floor(N/15)),l3 = (((N - (N%3)) == N)? N - 3 : (N - (N%3))),l5 = (((N - (N%5)) == N)? N - 5 : (N - (N%5))),l15 = (((N - (N%15)) == N)? N - 15 : (N - (N%15))),sum_of_3,sum_of_5,sum_of_15;
        //cout<<"n3:"<<n3<<"\nn5:"<<n5<<"\nn15"<<n15<<"\nl3:"<<l3<<"\nl5:"<<l5<<"\nl15:"<<l15<<endl;
        sum_of_3 = (n3 * (i3 + l3))/2;
        //cout<<"sum_of_3:"<<sum_of_3<<endl;
        sum_of_5 = (n5 * (i5 + l5))/2;
        //cout<<"sum_of_5:"<<sum_of_5<<endl;
        sum_of_15 = (n15 * (i15 + l15))/2;
        //cout<<"sum_of_15:"<<sum_of_15<<endl;
        cout<<sum_of_3+sum_of_5-sum_of_15<<endl;
    }
    return 0;
}