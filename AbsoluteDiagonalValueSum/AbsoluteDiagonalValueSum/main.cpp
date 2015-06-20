#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int abs(int left,int right)
{
     return(left+right>=0)? left+right : -(left+right);
}
int main() {
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    int left=0,right=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i==j)
                left+=arr[i][j];
    int i=0,j=n-1;
    while(i<n && j>=0)
    {
        right+=arr[i][j];
        i++;
        j--;
    }
    cout<<abs(left,right);
    return 0;
}