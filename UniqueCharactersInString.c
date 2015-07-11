//Program to print the unique characters in a string
#include<stdio.h>
int main()
{
    char str[]="asdasdaa";
    char *ptr1,*ptr2;
    ptr1=str;
    ptr2=str+1;
    printf("%c",*ptr1);
    while(*ptr2!='\0')
    {
        if(*ptr1==*ptr2)
        {
            ptr1++;ptr2++;
        }
        else
        {
            printf("%c",*ptr2);
            ptr2++;
        }
    }printf("\n");
}