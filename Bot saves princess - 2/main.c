/*
 Author : Yeshwanth D S
 Problem Statement
 
 In this version of "Bot saves princess", Princess Peach and bot's position are randomly set. Can you save the princess?
 
 Task
 
 Complete the function nextMove which takes in 4 parameters - an integer N, integers r and c indicating the row & column position of the bot and the character array grid - and outputs the next move the bot makes to rescue the princess.
 
 Input Format
 
 The first line of the input is N (<100), the size of the board (NxN). The second line of the input contains two space separated integers, which is the position of the bot.
 
 Grid is indexed using Matrix Convention
 
 The position of the princess is indicated by the character 'p' and the position of the bot is indicated by the character 'm' and each cell is denoted by '-' (ascii value: 45).
 
 Output Format
 
 Output only the next move you take to rescue the princess. Valid moves are LEFT, RIGHT, UP or DOWN
 
 Sample Input
 
 5
 2 3
 -----
 -----
 p--m-
 -----
 -----
 Sample Output
 
 LEFT
 Resultant State
 
 -----
 -----
 p-m--
 -----
 -----
 
 Source : hackerrank.com
 Problem Link : https://www.hackerrank.com/challenges/saveprincess2
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
void nextMove(int n, int r, int c, char grid[101][101]){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(grid[i][j]=='p')
            {
                if(r<i)
                {
                    printf("DOWN\n");
                }
                else if(r>i)
                {
                    printf("UP\n");
                }
                else if(c>j)
                {
                    printf("LEFT\n");
                }
                else if(c<j)
                {
                    printf("RIGHT\n");
                }
                return;
            }
}
int main(void) {
    
    int n, r, c;
    
    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &c);
    
    char grid[101][101];
    
    for(int i=0; i<n; i++) {
        scanf("%s[^\n]%*c", grid[i]);
    }
    
    nextMove(n, r, c, grid);
    return 0;
}