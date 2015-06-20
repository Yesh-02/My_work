#include<iostream>
#include<string>
using namespace std;
int balParanth(string str)
{
    int max=0,cur_max=0,i=0;
    for (int i = 0; i< str.size(); i++)
    {
        if(str[i]=='(')
        {
            cur_max+=1;
            if(cur_max>max)
            {
                max=cur_max;
            }
        }
        else if (str[i]==')')
        {
            cur_max-=1;
            if(cur_max<0)
                return -1;
        }
    }
    if(cur_max!=0) return -1;
    else return max;
}
int main()
{
    cout<<balParanth("( ((X)) (((Y))) )");
    return 0;
}