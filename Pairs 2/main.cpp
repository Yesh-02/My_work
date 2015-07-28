/*
 Author : Yeshwanth D S
 Problem:
    Modified problem.. 
    find the index of the first pair with the total sum equating to the given number.
 
 Advantage of this solution :
    My solution doesnot use any sorting function to arrange the elements in the array to find the solution.
    This method used the fact that the index of an array is already sorted..
 
        Let's say the complexity of the quick sort as NlogN. This is totally neglitted by my solution.
 
 Limitations :
    This Solution only works with array of unique values..
 
 Source : Self
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void getIndex(int arr[],int max,int sum)
{
    for(int i=0;i<max && i <= sum;i++)
    {
        if(arr[i] == -1)
            continue;
        for(int j=i+1;j<=max;j++)
        {
            if(arr[j] == -1)
                continue;
            if(i+j > sum)
                break;
            if((i+j) == sum)
            {
                cout<<arr[i]+1<<' '<<arr[j]+1<<endl;
                return;
            }
        }
    }
    cout<<"Not Found.."<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr[10000],num,max=0;
        fill_n(arr,n,-1);
        for(int i=0;i<n;i++)
        {
            cin>>num;
            arr[num] = i;
            if(i > max)
                max = i;
        }
        getIndex(arr,max+1,m);
    }
    return 0;
}