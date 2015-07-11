//program to return the first character that repeats the most number of times in a stirng
#include<stdio.h>
#define MAX 256
int main()
{
    char ch,max_char;
    int max=0,count[MAX]={};
    while((ch=getchar())!='\n')
    {
        count[ch]++;
        if(max<count[ch])
        {
            max=count[ch];
            max_char=ch;
        }
    }
    printf("%c\n",max_char);
    return 0;
}