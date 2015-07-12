#include<stdio.h>
void hasBalParanthesis(char *string)
{
    int i=0;
    int count=0;
    while(string[i])
    {
        if (string[i]== '{')
        {
            count++;
            printf("\n%c,%d,%d",string[i],count,i);
        }
        else if (string[i]=='}')
        {
            count--;
            printf("\n%c,%d,%d",string[i],count,i);
        }
        i++;
    }
    if (count==0)
        printf("\nmatches");
    else
        printf("\nNot a match");
}
int main()
{
    char *string = "{{{,../}}";
    hasBalParanthesis(string);
    return 0;
}