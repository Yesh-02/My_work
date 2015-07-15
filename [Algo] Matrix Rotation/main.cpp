/*
 Author : Yeshwanth D S
 Problem Statement
 
 You are given a 2D matrix, a, of dimension MxN and a positive integer R. You have to rotate the matrix R times and print the resultant matrix. Rotation should be in anti-clockwise direction.
 
 Rotation of a 4x5 matrix is represented by the following figure. Note that in one rotation, you have to shift elements by one step only (refer sample tests for more clarity).
 
 matrix-rotation
 
 It is guaranteed that the minimum of M and N will be even.
 
 Input
 First line contains three space separated integers, M, N and R, where M is the number of rows, N is number of columns in matrix, and R is the number of times the matrix has to be rotated.
 Then M lines follow, where each line contains N space separated positive integers. These M lines represent the matrix.
 
 Output
 Print the rotated matrix.
 
 Constraints
 2 <= M, N <= 300
 1 <= R <= 109
 min(M, N) % 2 == 0
 1 <= aij <= 108, where i ∈ [1..M] & j ∈ [1..N]
 
 Sample Input #00
 
 4 4 1
 1 2 3 4
 5 6 7 8
 9 10 11 12
 13 14 15 16
 Sample Output #00
 
 2 3 4 8
 1 7 11 12
 5 6 10 16
 9 13 14 15
 Sample Input #01
 
 4 4 2
 1 2 3 4
 5 6 7 8
 9 10 11 12
 13 14 15 16
 Sample Output #01
 
 3 4 8 12
 2 11 10 16
 1 7 6 15
 5 9 13 14
 Sample Input #02
 
 5 4 7
 1 2 3 4
 7 8 9 10
 13 14 15 16
 19 20 21 22
 25 26 27 28
 Sample Output #02
 
 28 27 26 25
 22 9 15 19
 16 8 21 13
 10 14 20 7
 4 3 2 1
 Sample Input #03
 
 2 2 3
 1 1
 1 1
 Sample Output #03
 
 1 1
 1 1
 Explanation
 Sample Case #00: Here is an illustration of what happens when the matrix is rotated once.
 
 1  2  3  4      2  3  4  8
 5  6  7  8      1  7 11 12
 9 10 11 12  ->  5  6 10 16
 13 14 15 16      9 13 14 15
 Sample Case #01: Here is what happens when to the matrix after two rotations.
 
 1  2  3  4      2  3  4  8      3  4  8 12
 5  6  7  8      1  7 11 12      2 11 10 16
 9 10 11 12  ->  5  6 10 16  ->  1  7  6 15
 13 14 15 16      9 13 14 15      5  9 13 14
 Sample Case #02: Following are the intermediate states.
 
 1  2  3  4      2  3  4 10    3  4 10 16    4 10 16 22
 7  8  9 10      1  9 15 16    2 15 21 22    3 21 20 28
 13 14 15 16 ->  7  8 21 22 -> 1  9 20 28 -> 2 15 14 27 ->
 19 20 21 22    13 14 20 28    7  8 14 27    1  9  8 26
 25 26 27 28    19 25 26 27    13 19 25 26   7 13 19 25
 
 
 
 10 16 22 28    16 22 28 27    22 28 27 26    28 27 26 25
 4 20 14 27    10 14  8 26    16  8  9 25    22  9 15 19
 3 21  8 26 ->  4 20  9 25 -> 10 14 15 19 -> 16  8 21 13
 2 15  9 25     3 21 15 19     4 20 21 13    10 14 20  7
 1  7 13 19     2  1  7 13     3  2  1  7     4  3  2  1
 
 Source : hackerrank.com
 Problem link : https://www.hackerrank.com/challenges/matrix-rotation-algo
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
int max(int a,int b)
{
    return (a>b)?a:b;
}
int min(int a,int b)
{
    return (a<b)?a:b;
}
using namespace std;
int main()
{
    int Row,Col,Rotations;
    long int Rot;
    cin>>Row>>Col>>Rot;
    long int arr[Row][Col];
    for(int i=0;i<Row;i++)
        for(int j=0;j<Col;j++)
            cin>>arr[i][j];
    int R = Row-1,C = Col-1,count,sgmnt,RRR=Row,CCC=Col,i,j,r,c,R1,C1;
    sgmnt = min(Row,Col)/2;
    for(int n=0;n<sgmnt;n++)
    {
        r = R-n;
        c = C-n;
        Rotations = Rot;
        if(RRR == 0 || CCC == 0)
            Rotations = 0;
        else
            Rotations %= ((RRR*CCC)-((RRR-2)*(CCC-2)));
        while(Rotations--)
        {
            R1 = r;
            C1 = c;
            i=n;
            j=n;
            count = max(RRR,CCC)-1;
            int wflag = 1;
            int xflag = 1;
            int yflag = 1;
            int zflag = 1;
            int w = arr[i][j],x = arr[r][j],y = arr[r][c],z = arr[i][c];
            while(count--)
            {
                if(i < R1 && i+wflag <= r)
                {
                    w = w + arr[i+wflag][j];
                    arr[i+wflag][j] = w - arr[i+wflag][j];
                    w = w - arr[i+wflag][j];
                    wflag++;
                }
                if(j < C1 && j+xflag <= c)
                {
                    x = x + arr[r][j+xflag];
                    arr[r][j+xflag] = x - arr[r][j+xflag];
                    x = x - arr[r][j+xflag];
                    xflag++;
                }
                if(r >= 0 && r-yflag >= i)
                {
                    y = y + arr[r-yflag][c];
                    arr[r-yflag][c] = y - arr[r-yflag][c];
                    y = y - arr[r-yflag][c];
                    yflag++;
                }
                if(c >= 0 && c-zflag >= j)
                {
                    z = z + arr[i][c-zflag];
                    arr[i][c-zflag] = z - arr[i][c-zflag];
                    z = z - arr[i][c-zflag];
                    zflag++;
                }
            }
        }
        RRR-=(2);
        CCC-=(2);
    }
    for(int i=0;i<Row;i++)
    {
        for(int j=0;j<Col;j++)
            cout<<arr[i][j]<<' ';
        cout<<endl;
    }
}