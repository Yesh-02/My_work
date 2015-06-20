#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string str;
    cin>>str;
    int i=1,j=1,mini=0,minj=0,size=str.length(),min=82,c=ceil(sqrt(size)),k=0;
    for(i=1;i<=c;i++)
        for(j=i;j<=c;j++)
        {
            if(i*j>=size)
            {
                if(min>size)
                {
                    min=size;
                    mini = i;
                    minj = j;
                }
            }
        }
    cout<<mini<<' '<<minj<<endl;
    char matrix[mini][minj];
    for(i = 0;i<mini;i++)
    {
        for(j=0;j<minj;j++)
        {
            matrix[i][j]='0';
        }
        cout<<' ';
    }
    for(i = 0;i<mini;i++)
        for(j=0;j<minj;j++)
        {
            if(k<size)
            {
                matrix[i][j]=str[k];
                k++;
            }
            else
                break;
        }
    for(i = 0;i<mini;i++)
    {
        for(j=0;j<minj;j++)
        {
            cout<<matrix[i][j];
        }
        cout<<' ';
    }
    cout<<endl;
    for(j = 0;j<minj;j++)
    {
        for(i=0;i<mini;i++)
        {
            if(matrix[i][j] != '0')
            cout<<matrix[i][j];
        }
        cout<<' ';
    }
    return 0;
}

