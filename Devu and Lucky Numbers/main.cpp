/*
 Author : Yeshwanth D S
 
 Problem Statement
 
 You are given three integers x, y and z. You have to find the sum of all numbers whose digits are made of only 4, 5 and 6, that have at most x fours in decimal representation, at most y fives in decimal representation and at most z sixes in decimal representation. As summation can be very large, print it modulo 109+7.
 
 Input Format
 The only line containing three space-separated integers x, y and z.
 
 Constraints
 0≤x≤100
 0≤y≤100
 0≤z≤100
 
 Output Format
 Output the summation modulo 109+7.
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long  factTR(int n, long long a)
{
    if (n == 0)  return a%1000000007;
    
    return factTR(n-1, (n*(a%1000000007))%1000000007);
}
long long  fact(int n)
{
    return factTR(n, 1);
}
int main()
{
    long long x,y,z,val,per,digit_sum,no_of_rep,i,j,k;
    long long mul=0,temp=1,sum=0;
    cin>>x>>y>>z;
    for(i=0 ; i <= x; i++)
    {
        for( j = 0;j <= y; j++)
        {
            for( k = 0; k <= z; k++)
            {
                if(i==0 && j==0 && k==0)
                    continue;
                val=i+j+k;
                for(int x=1;x<=val;x++)
                {
                    mul+=temp;
                    temp*=10;
                }
                per = fact(val-1);
                digit_sum = (i*4)+(j*5)+(k*6);
                no_of_rep = fact(i)*fact(k)*fact(j);
                sum += ((mul%1000000007*per%1000000007*digit_sum%1000000007)%1000000007/no_of_rep);
                sum%=1000000007;
                mul=0;
                temp=1;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}