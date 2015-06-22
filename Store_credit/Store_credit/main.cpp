#include <iostream>
using namespace std;

void swap ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}

void findSet(int arr[],int list[],int size,int Credit)
{
    quickSort(list,0,size-1);
    int i = 0,j = 0, firstItem=0, secondItem=0;
    while(i < size-1)
    {
        if(list[i] + list[j] == Credit)
        {
            firstItem = list[i];
            secondItem = list[j];
            break;
        }
        else if(list[i] + list[j] > Credit)
        {
            i+=1;
            j=i;
        }
        if(j == size - 1 )
        {
            i++;
            j=i;
        }
        else
            j++;
    }
    for(int i=0;i<size;i++)
        if(arr[i] == firstItem || arr[i] == secondItem)
            cout<<i+1<<' ';
    cout<<endl;
}

int main()
{
    int arr[2000],list[2000],N,C,L;
    FILE *fp;
    fp=fopen("A-large-practice.in","r");
    fscanf(fp,"%d\n",&N);
    for(int j=1;j<=N;j++)
    {
        fscanf(fp,"%d\n",&C);
        fscanf(fp,"%d\n",&L);
        for(int i=0;i<L;i++)
        {
            fscanf(fp,"%d\n",&list[i]);
            arr[i]=list[i];
        }
        cout<<"Case #"<<j<<": ";
        findSet(arr,list,L,C);
    }
}