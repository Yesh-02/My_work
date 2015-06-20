#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string swap(string str,int i,int j)
{
    // cout<<"before swap in swap "<<str<<endl;
    char temp;
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    // cout<<"after swap in swap "<<str<<endl;
    return str;
}
string nextWord(string str)
{
    // cout<<"before swap in nextwoed "<<str<<endl;
    //cout<<str;
    int i=str.length()-1,j=i-1;
    while(i>0)
    {
        //cout<<"before swap in nextwoed in loop "<<str<<endl;
        if(str[i]>str[j])
        {
            //cout<<"before swap in nextwoed in loop in if "<<str<<endl;
            return swap(str,i,j);
        }
        j-=1;
        if(j<0)
        {
            i-=1;
            j=i-1;
        }
    }
    //cout<<"sfter swap in nextwoed "<<str<<endl;
    return str;
}

int main() {
    int t;
    string str,ans;
    cin>>t;
    while(t--)
    {
        cin>>str;
        ans=nextWord(str);
        //cout<<"after swap in main "<<ans<<endl;
        if(ans.compare(str)==0)
            cout<<"no answer"<<endl;
        else
            cout<<ans<<endl;
        //  cout<<"----------------"<<endl;
    }
    return 0;
}
