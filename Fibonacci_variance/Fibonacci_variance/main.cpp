//
//  main.cpp
//  Fibonacci_variance
//
//  Created by yesh on 18/06/15.
//  Copyright (c) 2015 yesh. All rights reserved.
//
#include <stdio.h>
void multiply(int F[2][2], int M[2][2]);
void power(int F[2][2], int n);
int fib(int n)
{
    int F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1);
    return F[0][0];
}
void power(int F[2][2], int n)
{
    if( n == 0 || n == 1)
        return;
    int M[2][2] = {{1,1},{1,0}};
    
    power(F, n/2);
    multiply(F, F);
    
    if (n%2 != 0)
        multiply(F, M);
}

void multiply(int F[2][2], int M[2][2])
{
    int x =  ((((F[0][0]%99991)*(M[0][0]%99991))%99991) + (((F[0][1]%99991)*(M[1][0]%99991))%99991))%99991;
    int y =  ((((F[0][0]%99991)*(M[0][1]%99991))%99991) + (((F[0][1]%99991)*(M[1][1]%99991))%99991))%99991;
    int z =  ((((F[1][0]%99991)*(M[0][0]%99991))%99991) + (((F[1][1]%99991)*(M[1][0]%99991))%99991))%99991;
    int w =  ((((F[1][0]%99991)*(M[0][1]%99991))%99991) + (((F[1][1]%99991)*(M[1][1]%99991))%99991))%99991;
    
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
int main()
{
    int N,K,sum=0,temp;
    scanf("%d %d",&N,&K);
    while(N--)
    {
        scanf("%d",&temp);
        sum=((sum%99991)+fib(temp))%99991;
    }
    sum=((sum%99991)*(K%99991))%99991;
    printf("%d",sum);
    return 0;
}
