#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int strlen(char str[])
{
    int count=0,i=0;
    while(str[i]!='\n')
    {
        count++;
        i++;
    }
    return count;
}
int isPangram(char str[])
{
    int count[26]={0},i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]==' ' || str[i]=='\n')
            continue;
        if(str[i]>=97 && str[i]<=122)
            count[str[i]%97]++;
        else if(str[i]<=90 && str[i]>=65)
            count[str[i]%65]++;
    }
    
    for(i=0;i<26;i++)
    {
        if(count[i] == 0)
            return 1;
    }
    return 0;
}

int main() {
    char str[1000];
    fgets(str,1000, stdin);
    if (!isPangram(str))
        cout<<"pangram\n";
    else
        cout<<"not pangram\n";
    return 0;
}


