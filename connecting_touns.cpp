#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long int noOfRoutes(int n,int routes[])
{
    int i=0,prod=1;
    for(i=0;i<n-1;i++)
    {
        prod*=routes[i];
        prod%=1234567;
    }
    return prod;
}

int main() {
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int route[n-1];
        for(i=0;i<n-1;i++)
            cin>>route[i];
        cout<<noOfRoutes(n,route);
    }
    return 0;
}