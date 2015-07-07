/*
 Program : Sum of Absolutes (Hackerrank.com)
 Author : Yeshwanth D S
 Description : find if the sum of contegious elements in an array is Odd or Even
 problem statement link : https://www.hackerrank.com/contests/w16/challenges/sum-of-absolutes
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int A[100001];
int Find(int L,int R)
{
    int sum = 0;
    for (int i = L ; i<= R; i++ )
    {
        sum = abs(sum + A[i]);
    }
    return sum;
}
int main() {
    int N,Q,L,R;
    cin>>N>>Q;
    for(int i=0;i<N;i++)
        cin>>A[i];
    while(Q--)
    {
        cin>>L>>R;
        if(Find(L-1,R-1)%2 == 0 )
            cout<<"Even"<<endl;
        else
            cout<<"Odd"<<endl;
    }
    return 0;
}