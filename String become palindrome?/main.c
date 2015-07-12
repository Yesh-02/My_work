#include<stdio.h>
#include<string.h>
#define MAX 512
int main()
{
    char ch;
    int count[MAX],i=0,odd=0;
    while((ch=(char) getchar())!='\n')
    {
        count[ch]++;
    }
    for(i=0;i<256;i++)
    {
        if(count[i]%2!=0)
        {
            odd++;
        }
    }
    if(odd>1)
    {
        printf("cannot form palindrome\n");
    }
    else
    {
        printf("can form palindrome\n");
    }
}