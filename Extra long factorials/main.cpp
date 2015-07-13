/*
 Author : Yeshwanth
 Problem Statement
 
 You are given an integer N. Print the factorial of this number.
 
 N!=N×(N−1)×(N−2)×⋯×3×2×1
 Note: Factorials of N>20 can't be stored even in a 64−bit long long variable. Big integers must be used for such calculations. Languages like Java, Python, Ruby etc. can handle big integers but we need to write additional code in C/C++ to handle such large values.
 
 We recommend solving this challenge using BigIntegers.
 
 Input Format
 Input consists of a single integer N.
 
 Constraints
 1≤N≤100
 
 Output Format
 Output the factorial of N.
 
 Sample Input
 
 25
 Sample Output
 
 15511210043330985984000000
 
 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/extra-long-factorials
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void findFact(int num)
{
    int ans[250]={0};
    int size = 1, carry = 0, temp;
    ans[0] = 1;
    for(int i = 1; i <= num; i++)
    {
        for(int j=0; j < size; j++ )
        {
            temp = ans[j] * i + carry;
            ans[j] = temp % 10;
            carry = temp/10;
        }
        while(carry > 0)
        {
            ans[size] = carry % 10;
            carry = carry / 10;
            size++;
        }
    }
    for(int i=size-1;i>=0;i--)
        cout<<ans[i];
}

int main() {
    int num;
    cin>>num;
    findFact(num);
    return 0;
}