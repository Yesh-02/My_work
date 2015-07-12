#include<iostream>
#include<string>
using namespace std;
void inPal(string str);
void printPal(int val,int index,string str);
int findPal(string str,int n,int size);
void inPal(string str)
{
    int i,size=str.size(),pal[512],p=0,max=0,inx;
    for(i=0;i<size;i++)
    {
        pal[p]=findPal(str,i,size);
        if(pal[p]>max)
        {
            max=pal[p];
            inx=p;
        }
        p++;
    }
    printPal(max,inx,str);
}
int findPal(string str,int n,int size)
{
    int count=1,i=1;
    while(n-i>=0 && n+i<size)
    {
        if(str[n-i]==str[n+i])
        {
            count+=2;
            i++;
        }
        else break;
    }
    return count;
}
void printPal(int val,int index,string str)
{
    for (int i= index - (val-1)/2;i <= index + (val-1)/2;i++)
    {
        cout<<str[i];
    }
}
int main()
{
    inPal("abcmamemammmmalayalavmmm");
    return 0;
}