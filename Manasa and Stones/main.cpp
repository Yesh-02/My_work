/*
 Author : Yeshwanth D S
 Problem Statement
 
 Manasa is out on a hike with friends. She finds a trail of stones with numbers on them. She starts following the trail and notices that two consecutive stones have a difference of either a or b. Legend has it that there is a treasure trove at the end of the trail and if Manasa can guess the value of the last stone, the treasure would be hers. Given that the number on the first stone was 0, find all the possible values for the number on the last stone.
 
 Note: The numbers on the stones are in increasing order.
 
 Input Format
 The first line contains an integer T, i.e. the number of test cases. T test cases follow; each has 3 lines. The first line contains n (the number of stones). The second line contains a, and the third line contains b.
 
 Output Format
 Space-separated list of numbers which are the possible values of the last stone in increasing order.
 
 Constraints
 1≤T≤10
 1≤n,a,b≤103
 
 Sample Input
 
 2
 3
 1
 2
 4
 10
 100
 Sample Output
 
 2 3 4 
 30 120 210 300
 
 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/manasa-and-stones
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        if(a!=b)
        {
            int max=((a>b)?a:b);
            int min=((a>b)?b:a);
            for(int i = min*(n-1);i<=(max*(n-1));i+=(max-min))
                cout<<i<<' ';
        }
        else
            cout<<a*(n-1);
        cout<<endl;
    }
    return 0;
}
