#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string str1,str2;
    int changes=0;
    int count[26]={0};
    cin>>str1>>str2;
    for(int i=0;i<=str1.length()-1;i++)
        count[(str1[i]%97)]++;
    for(int i=0;i<=str2.length()-1;i++)
        count[(str2[i]%97)]--;
    for(int i=0;i<26;i++)
        if(count[i]<0)
            changes+=-(count[i]);
        else
            changes+=count[i];
    cout<<changes;
    return 0;
}