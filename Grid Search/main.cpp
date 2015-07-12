/*
 Author : Yeshwanth D S
 
 Problem Statement
 
 Given a 2D array of digits, try to find the location of a given 2D pattern of digits. For example, consider the following 2D matrix:
 
 1234567890
 0987654321
 1111111111
 1111111111
 2222222222
 
 Assume we need to look for the following 2D pattern:
 
 876543
 111111
 111111
 
 If we scan through the original array, we observe that the 2D pattern begins at the second row and the third column of the larger grid (the 8 in the second row and third column of the larger grid is the top-left corner of the pattern we are searching for).
 
 So, a 2D pattern of P digits is said to be present in a larger grid G, if the latter contains a contiguous, rectangular 2D grid of digits matching with the pattern P, similar to the example shown above.
 
 
 Source : Hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/the-grid-search
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int isFound(int row,int col,int r,int c,string main[],string sub[])
{
    int i,j,x,y;
    for(i=row,x=0;x<r;i++,x++)
        for(j=col,y=0;y<c;j++,y++)
        {
            if(main[i][j] != sub[x][y])
                return 0;
        }
    return 1;
}
string isSubString(int R,int C,int r,int c,string main[],string sub[])
{
    for(int i=0;i<R-r+1;i++)
        for(int j=0;j<C-c+1;j++)
            if(main[i][j] == sub[0][0])
                if(isFound(i,j,r,c,main,sub) == 1 )
                    return "YES";
    return "NO";
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int R,C,r,c;
        cin>>R>>C;
        string main[R];
        int ret[R]={0};
        for(int i=0; i<R;i++)
            cin>>main[i];
        cin>>r>>c;
        string sub[r];
        for(int i=0;i<r;i++)
            cin>>sub[i];
        cout<<isSubString(R,C,r,c,main,sub)<<endl;
    }
    return 0;
}