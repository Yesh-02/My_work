#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int pow(int num)
{
    int pow=1;
    while(num--)
    {
        pow*=2;
        pow%=100000;
    }
    return pow;
}
int findPattern(int n)
{
    return (pow(n)-1);
}

int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<findPattern(n)<<endl;
    }
    return 0;
}