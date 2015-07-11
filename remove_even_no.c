//program to remove even numbers from a array..
#include<stdio.h>
#include<stdlib.h>
#define length sizeof(input)/sizeof(input[0])
int main()
{
    int input[]={1,2,3,4,5,6,7},i,j,output[length]={0};
    for(i=0,j=0;i<length;i++)
    {
        if(input[i]%2!=0)
        {
            output[j]=input[i];
            j++;
        }
    }
    for(i=0;i<length;i++)
    {
        printf("%d ",output[i]);
    }
}