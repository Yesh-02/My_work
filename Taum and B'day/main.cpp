/*
 Author : Yeshwanth D S
 Problem Statement
 
 Taum is planning to celebrate the birthday of his friend, Diksha. There are two types of gifts that Diksha wants from Taum: one is black and the other is white. To make her happy, Taum has to buy B number of black gifts and W number of white gifts.
 
 The cost of each black gift is X units.
 The cost of every white gift is Y units.
 The cost of converting each black gift into white gift or vice versa is Z units.
 Help Taum by deducing the minimum amount he needs to spend on Diksha's gifts.
 
 Input Format
 
 The first line will contain an integer T which will be the number of test cases.
 There will be T pairs of lines. The first line of each test case will contain the values of integers B and W. Another line of each test case will contain the values of integers X, Y, and Z.
 
 Constraints
 1≤T≤10
 0≤X,Y,Z,B,W≤109
 Output Format
 
 T lines, each containing an integer: the minimum amount of units Taum needs to spend on gifts.
 
 Sample Input
 
 5
 10 10
 1 1 1
 5 9
 2 3 4
 3 6
 9 1 1
 7 7
 4 2 1
 3 3
 1 9 2
 Sample Output
 
 20
 37
 12
 35
 12
 
 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/taum-and-bday
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long findCost(long long b,long long w,long long x,long long y)
{
    return (b*x)+(w*y);
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long long b,w,x,y,z,temp1,temp2;
        cin>>b>>w>>x>>y>>z;
        if((x+z) >= y)
            temp1 = y;
        else
            temp1 = x+z;
        if((y+z) >= x)
            temp2 = x;
        else
            temp2 = y+z;
        cout<<findCost(b,w,temp2,temp1)<<endl;
    }
    return 0;
}