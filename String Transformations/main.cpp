/*
 Author : Yeshwanth D S
 Problem Statement
 
 Given a string S, you need to perform Q transformations of the form (a,b). For each transformation, you need to reverse the substring s[a...b] and then print the transformed string. This change is permanently applied on the string, i.e., each tranformation will be done on the output of previous transformation.
 
 Input Format
 
 The first line of input contains the string S.
 This is followed by integer Q in the next line.
 Then Q lines follow, each containing two space-separated integers, a and b.
 
 Constraints
 
 1≤length(S)≤1000
 1≤Q≤1000
 0≤a≤b<length(S)
 Output Format
 
 For each transformation, print the answer in a new line.
 
 Sample Input
 
 abcdef
 4
 0 0
 0 5
 0 2
 0 1
 Sample Output
 
 abcdef
 fedcba
 defcba
 edfcba
 
 Source : Hackerrank.com (Contest)

 Problem Link : https://www.hackerrank.com/contests/code-cpp-may-2015/challenges/string-transformations
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    char str[1000];
    cin>>str;
    int N;
    cin>>N;
    while(N--)
    {
        int l,r;
        cin>>l>>r;
        if(l != r)
        {
            char *ptr = str + l,*ptr1 = str + r;
            while(ptr < ptr1)
            {
                char temp = *ptr;
                *ptr = *ptr1;
                *ptr1 = temp;
                *ptr++;
                *ptr1--;
            }
        }
        cout<<str<<endl;
    }
    return 0;
}