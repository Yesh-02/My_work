#include <iostream>
#include <string>
using namespace std;
string strrev(char word[])
{
    int i=0,j=strlen(word)-1;
    while(i<=j)
    {
        char temp = word[i];
        word[i]=word[j];
        word[j]=temp;
        i++;
        j--;
    }
    return word;
}
string getReverse(char str[])
{
    string output;
    char word[1000];
    int i=strlen(str)-2,j=0;
    while(i>=0)
    {
        if (i==0)
        {
            word[j]=str[i];
            word[j+1]='\0';
            output.append(strrev(word));
        }
        else if(str[i]!=' ')
        {
            word[j]=str[i];
            j++;
        }
        else if(str[i] == ' ')
        {
            word[j]='\0';
            output.append(strrev(word));
            output.append(" ");
            j=0;
        }
        i--;
    }
    return output;
}
int main()
{
    int N;
    char str[1000];
    FILE *fp;
    fp = fopen ("B-small-practice.in","r");
    fscanf(fp,"%d\n",&N);
    for(int i=1;i<=N;i++)
    {
        fgets(str,1001,fp);
        cout<<"Case #"<<i<<": "<<getReverse(str)<<endl;
    }
    return 0;
}