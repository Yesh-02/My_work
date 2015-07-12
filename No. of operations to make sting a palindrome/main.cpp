#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int isPal(string str)
{
    int i=0,j=str.length()-1;
    while(i<=j)
    {
        if(str[i]!=str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
int getNumOfOper(string str)
{
    int i=0,j=str.length()-1,num=0,diff;
     while(i<=j)
     {
     diff= str[i] - str[j];
     if(diff > 0)
     num+=diff;
     else
     num+=-(diff);
         i++;
         j--;
     }
    return num;
}

int main() {
    int t,num=0;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        if(!isPal(str))
        num=getNumOfOper(str);
        cout<<num<<endl;
    }
    return 0;
}

