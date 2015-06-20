#include<stdio.h>
#define max 512
void findDel(int *num,int size)
{
    printf("%d",size);
    int i=0,conti=1;
    int count[max];
    while(i<size)
    {
        count[num[i]]++;
        i++;
    }
    i=1;
    while(count[i+1])
    {
        printf("%d",count[i]);
        i++;
    }
    while(conti)
    {
        int n;
        int i=0;
        int count1[max];
        printf("\n Enter number to delete..");
        scanf("%d",&n);
        while(i < size)
        {
            if(num[i] == n)
            {
                num[i]= 0;
            }
            i++;
        }
        i=1;
        while(count[i])
        {
            printf("%d",count[i]);
            i++;
        }
        i=0;
        while(i < size)
        {
            count1[num[i]]++;
            i++;
        }
        i=1;
        while(count1[i])
        {
            printf("%d",count1[i]);
            i++;
        }
        i=0;
        while(i < sizeof(count)/sizeof(count[0])||i < sizeof(count1)/sizeof(count1[0]))
        {
            if(count[i]==count1[i])
                continue;
            else
                printf("number deleted is .. %d",i);
            i++;
        }
        printf("enter 0 to stop..");
        scanf("%d",&conti);
    }
}
int main()
{
    int num[]={10,2,1,3,4,5,6,7,8,9};
    findDel(num,sizeof(num)/sizeof(num[0]));
    return 0;
}