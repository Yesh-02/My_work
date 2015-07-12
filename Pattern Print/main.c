/*Program to print the below pattern..
 4
 
 4444444
 4333334
 4322234
 4321234
 4322234
 4333334
 4444444
*/
#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<2*a-1;i++)
    {
        int n=a;
        for(int j=0;j<2*a-1;j++)
        {
            printf("%d",n);
            if(i-j>0)
                --n;
            if(i+j>=2*a-2)
                ++n;
        }
        printf("\n");
    }
}