/*
 Author : Yeshwanth D S
 Problem Description 
    Change all the values in row and column of the current element of a matrix to 1, if the current element is 1.
 Problem Source : GeeksforGeeks.com
 */

#include<iostream>
using namespace std;
void convertMatrix(int r,int c,int *matrix)
{
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(*((matrix+i*c)+j) == -1)
                *((matrix+i*c)+j) = 1;
}
void printMatrix(int r,int c,int *matrix)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<*((matrix+i*c)+j)<<' ';
        cout<<endl;
    }
}
void modifyMatrix(int r,int c,int *matrix)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(*((matrix+i*c)+j) == 1)
            {
                for(int x = 0; x < c ; x++) // replaces all the elements as -1 in the row, if the value is not 1
                    if(*((matrix+i*c)+x) != 1)
                        *((matrix+i*c)+x) = -1;
                for(int y = 0; y < r ; y++) // replaces all the elements as -1 in the column, if the value is not 1
                    if(*((matrix+y*c)+j) != 1)
                        *((matrix+y*c)+j) = -1;
            }
        }
    }
    convertMatrix(r,c,(int *)matrix); // converts -1 to 1..
    printMatrix(r,c,(int *)matrix);
}
int main()
{
    int r,c;
    cin>>r>>c;
    int matrix[r][c];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin>>matrix[i][j];
    modifyMatrix(r,c,(int *)matrix);
}