/*
 Program : Sum of Absolutes (Hackerrank.com)
 Author : Yeshwanth D S
 Description : find if the sum of contegious elements in an array is Odd or Even
 problem statement link : https://www.hackerrank.com/contests/w16/challenges/sum-of-absolutes
 */

#include<iostream>
using namespace std;
int arr[]={0},odd[]={0};
string findOdd(int l,int r,int ocount,int size)
{
    int count=0;
    for(int i=0;i<ocount;i++)
    {
        if(odd[i]>r)
        {
            printf(".");
            break;
        }
        if(odd[i]>=l && odd[i]<=r)
            count++;
    }
    if(count%2 == 0)
        return "Even";
    else
        return "Odd";
}
int main() {
    int n,q,j=0;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]%2!=0)
            odd[j++]=i;
    }
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<findOdd(a-1,b-1,j,n)<<endl;
    }
    return 0;
}
