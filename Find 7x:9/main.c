#include<stdio.h>
void fndVal(int n)
{
    int temp = 0,ans = 0;
    while(n)
    {
        temp += 7;
        n--;
    }
    while(temp>=10)
    {
        temp-= 9;
        ans++;
    }
    printf("answer is %d %d/9\n",ans,temp);
}
int main()
{
    int num;
    scanf("%d",&num);
    fndVal(num);
    return 0;
}