//Program to reverse a string..
#include<stdio.h>
#include<string.h>
int main()
{
    char str[]="vish";
    char *ptr1,*ptr2,temp;
    ptr1=str;
    ptr2=str+(strlen(str)-1);
   while(ptr1<ptr2)
    {
        temp=*ptr1;
        *ptr1=*ptr2;
        *ptr2=temp;
        ptr1++;
        ptr2--;
    }
    printf("%s\n",str);
    return 0;
}