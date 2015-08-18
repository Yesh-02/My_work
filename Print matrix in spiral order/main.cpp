/*
 Author : Yeshwanth D S
 Problem Description 
    Print the array in spiral format.
 Problem Source : GeeksforGeeks.com
 
 */
#include<iostream>
using namespace std;
void printSpiral(int r,int c,int *matrix)
{
    int left = 0,right = c - 1, top = 0 , bottom = r - 1,i,j;
    while(left <= right && top <= bottom)
    {
        j = left;
        i = top;
        while(j <= right)
        {
            cout<<*((matrix+i*c)+j)<<' ';
            j++;
        }
        top++;
        j = right;
        i = top;
        while(i <= bottom)
        {
            cout<<*((matrix+i*c)+j)<<' ';
            i++;
        }
        right--;
        i = bottom;
        j = right;
        while(j >= left)
        {
            cout<<*((matrix+i*c)+j)<<' ';
            j--;
        }
        bottom--;
        j = left;
        i = bottom;
        while(i >= top )
        {
            cout<<*((matrix+i*c)+j)<<' ';
            i--;
        }
        left++;
    }
}
int main()
{
    int r,c;
    cin>>r>>c;
    int matrix[r][c];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin>>matrix[i][j];
    printSpiral(r,c,(int *)matrix);
}