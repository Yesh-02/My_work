/*
 Author : Yeshwanth D S
 Problem Description 
    Given a 2D matrix, print "Found" if the element is  found inside the matrix else print "Not found". The solution should be optimized in all possible ways.
 
 Problem Source : GeekeforGeeks.com
 */

#include<iostream>
using namespace std;
string searchKey(int r,int c,int *matrix,int key)
{
    int i = 0,j = c-1;
    while(i<r && j>=0)
    {
        if(*((matrix+i*c) + j) == key)
            return "Found";
        else if(*((matrix+i*c) + j) > key)
            j--;
        else
            i++;
    }
    return "Not found";
}
int main()
{
    int r,c;
    cin>>r>>c;
    int matrix[r][c];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin>>matrix[i][j];
    int key;
    cin>>key;
    cout<<searchKey(r,c,(int *)matrix,key)<<endl;;
}