/*
Author : Yeshwanth D S
 Problem Statement
 
 Princess Peach is trapped in one of the four corners of a square grid. You are in the center of the grid and can move one step at a time in any of the four directions. Can you rescue the princess?
 
 Input format
 
 The first line contains an odd integer N (3 <= N < 100) denoting the size of the grid. This is followed by an NxN grid. Each cell is denoted by '-' (ascii value: 45). The bot position is denoted by 'm' and the princess position is denoted by 'p'.
 
 Grid is indexed using Matrix Convention
 
 Output format
 
 Print out the moves you will take to rescue the princess in one go. The moves must be separated by '\n', a newline. The valid moves are LEFT or RIGHT or UP or DOWN.
 
 Sample input
 
 3
 ---
 -m-
 p--
 Sample output
 
 DOWN
 LEFT

Source : hackerrank.com
Problem Link : https://www.hackerrank.com/challenges/saveprincess
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
void displayPathtoPrincess(int n, char grid[101][101]){
    int x,y,i=0,j=0;
    /*for(int a=0;a<n;a++)
     for(int b=0;b<n;b++)
     {
     if(grid[a][b]=='m')
     {
     i=a;
     j=b;
     }
     if(grid[a][b] =='p')
     {
     x=a;
     y=b;
     }
     }*/
    if(grid[i][j]=='p')
    {
        x=i;
        y=j;
    }
    else if(grid[i][n-1]=='p')
    {
        x=i;
        y=n-1;
    }
    else if(grid[n-1][j]=='p')
    {
        x=n-1;
        y=j;
    }
    else
    {
        x=n-1;
        y=n-1;
    }
    if(grid[(n-1)/2][(n-1)/2]=='m')
    {
        i=(n-1)/2;
        j=(n-1)/2;
    }
    else if(grid[(n-1)/2][((n-1)/2)-1]=='m')
    {
        i=(n-1)/2;
        j=((n-1)/2)-1;
    }
    else if(grid[((n-1)/2)-1][(n-1)/2]=='p')
    {
        i=((n-1)/2)-1;
        j=(n-1)/2;
    }
    else
    {
        i=((n-1)/2)-1;
        j=((n-1)/2)-1;
    }
    while(grid[i][j]!='p')
    {
        if(x<i)
        {
            printf("UP\n");
            i--;
        }
        else if(x>i)
        {
            printf("DOWN\n");
            i++;
        }
        else if(y>j)
        {
            printf("RIGHT\n");
            j++;
        }
        else if(y<j)
        {
            printf("LEFT\n");
            j--;
        }
    }
}
int main(void) {
    
    int m;
    scanf("%d", &m);
    char grid[101][101]={};
    char line[101];
    
    for(int i=0; i<m; i++) {
        scanf("%s", line);
        strcpy(grid[i], line);
    }
    displayPathtoPrincess(m,grid);
    return 0;
}
