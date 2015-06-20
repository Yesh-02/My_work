#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int array1[m],array2[n];
    int result[m+n];
    int i=0,j=0,k=0;
    while(j<m)
    {
        
        scanf("%d ",&array1[j]);
        printf("enter value of array1[%d]:%d",j,array1[j]);printf("\n");
        j++;
    }
    while(k<n)
    {

        scanf("%d ",&array2[k]);
        printf("enter value of array2[%d]:%d",k,array2[k]);printf("\n");
        k++;
    }
    i=0;j=0;k=0;
    while(i<m+n)
    {
        if(j>=m)
        {
            result[i]=array2[k];
            k++;
            i++;
        }
        else if(k>=n)
        {
            result[i]=array1[j];
            j++;
            i++;
        }
        else if(array1[j]<array2[k])
        {
            result[i]=array1[j];
            i++;
            j++;
        }
        else if(array1[j]>=array2[k])
        {
            result[i]=array2[k];
            k++;
            i++;
        }
    }
    i=0;
    while(i<m+n)
    {
        printf("%d ",result[i]);
        i++;
    }
    return 0;
}
