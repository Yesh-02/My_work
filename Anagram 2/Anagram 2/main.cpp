//find the number of changes required in the first string to make it an anagram of the second..

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int count[26]={0},changes=0,mid;
        string str1,str2;
        cin>>str1;
        mid = str1.length()/2;
        if(str1.length()%2==0)
        {
            str2=str1.substr(mid,mid);
            str1=str1.substr(0,mid);
            for(int i=0;i<=str1.length()-1;i++)
                count[(str1[i]%97)]++;
            for(int i=0;i<=str2.length()-1;i++)
                count[(str2[i]%97)]--;
            for(int i=0;i<26;i++)
                if(count[i]>0)
                    changes+=count[i];
            cout<<changes<<endl;
        }
        else
            cout<<"-1"<<endl;
    }
    return 0;
}