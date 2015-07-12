//Program to print if string 2 is a substring of string 1..

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str1[30],str2[15];
    char *ptr1,*ptr2;
    scanf("%s %s",str1,str2);
    ptr1=str1;
    ptr2=str2;
    int length=strlen(str2),len=length,length1=strlen(str1);
    while (length1)
    {
        if(*ptr1==*ptr2)
        {
            ptr1++;
            ptr2++;
            length--;
            if (length==0)
            {
                printf("found");exit(0);
            }length1--;
        }
        else
        {
            ptr2=str2;
            ptr1++;
            length=len;length1--;
        }
    }
    printf("not found");
}