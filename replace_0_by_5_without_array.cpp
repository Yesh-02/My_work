#include<iostream>
using namespace std;
int returnNum(long int num=01450)
{
    cout<<num;
    long int tens=1,temp_mod=num,temp_div=num;
    if(num ==0)
        return 5;
    while(temp_div>1)
    {
        temp_mod=temp_div%10;
        if(temp_mod == 0)
        {
            num=num+5*tens;
        }
        temp_div=temp_div/10;
        tens*=10;
    }
    return num;
}
int main()
{
    cout<<returnNum(100000);
    return 0;
}