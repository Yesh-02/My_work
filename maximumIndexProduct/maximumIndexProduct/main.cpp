#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<long long int> arr(sizeof(long long int));
long long int findLeft(long long int i)
{
    static long long int l_prev_val = 0;
    long long int val=i,j=i-1;
    cout<<"L,"<<"i="<<arr[i]<<','<<"j="<<arr[j]<<endl;
    if(arr.at(i)>arr.at(j) && arr.at(l_prev_val)> arr.at(i))
        return l_prev_val;
    else
    {
        while(j>=0)
        {
            if(arr.at(j)>arr.at(i))
            {
                val=j+1;
                l_prev_val = val;
                cout<<"L,,"<<val<<endl;
                return val;
            }
            j--;
        }
        return 0;
    }
}
long long int findRight(long long int i,long long int N)
{
    static long long int r_prev_val = 0;
    long long int val=i,j=i+1,run=1;
    cout<<"R,"<<"i="<<arr.at(i)<<','<<"j="<<arr.at(j)<<endl;
    if(arr.at(i-1)>arr.at(i) && run != 1)
        return r_prev_val;
    else
    {
        run++;
        while(j<=N)
        {
            if(arr.at(j)>arr.at(i))
            {
                val=j+1;
                r_prev_val = val;
                cout<<"R,,"<<val<<endl;
                return val;
            }
            j++;
        }
        return 0;
    }
}
long long int findMaxIndexProd(long long int N)
{
    long long int max_prod = 0,prod = 1;
    for(long long int i=1;i<N-1;i++)
    {
        long long int a=findLeft(i);
        long long int b=findRight(i,N);
        cout<<"a:"<<a<<' '<<"b:"<<b<<endl;
        prod=a*b;
        cout<<"prod:"<<prod<<endl;
        cout<<"max prod:"<<max_prod<<endl;
        if(prod>max_prod)
            max_prod=prod;
    }
    return max_prod;
}
int main()
{
    long long int N;
    cin>>N;
    for(long int i=0;i<N;i++)
        cin>>arr.at(i);
    cout<<endl;
    for(long long int i=0;i<N;i++)
        cout<<arr.at(i)<<' ';
    cout<<endl;
    cout<<findMaxIndexProd(N);
    return 0;
}