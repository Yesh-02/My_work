/*
Author : Yeshwanth D S
 Problem Statement
 
 Given the time in numerals we may convert it into words, as shown below:
 
 5:005:015:105:305:405:455:475:28→ five o' clock→ one minute past five→ ten minutes past five→ half past five→ twenty minutes to six→ quarter to six→ thirteen minutes to six→ twenty eight minutes past five
 Write a program which prints the time in words for the input given in the format mentioned above.
 
 Input Format
 
 There will be two lines of input:
 H, representing the hours
 M, representing the minutes
 
 Constraints
 1≤H≤12
 0≤M<60
 Output Format
 
 Display the time in words.
 
 Sample Input
 
 5
 47
 Sample Output
 
 thirteen minutes to six
 
 Source : hackerrank.com
 Problem link : https://www.hackerrank.com/challenges/the-time-in-words
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map <int,string> createCheklist()
{
    map <int,string> check;
    check[00]="o' clock";
    check[1]="one";
    check[2]="two";
    check[3]="three";
    check[4]="four";
    check[5]="five";
    check[6]="six";
    check[7]="seven";
    check[8]="eight";
    check[9]="nine";
    check[10]="ten";
    check[11]="eleven";
    check[12]="twelve";
    check[13]="thirteen";
    check[14]=check[4]+"teen";
    check[15]="fifteen";
    check[16]="sixteen";
    check[17]="seventeen";
    check[18]="eughteen";
    check[19]="nineteen";
    check[20]="twenty";
    check[30]="thirty";
    check[40]="fourty";
    check[50]="fifty";
    int tens=2;
    while(tens<6)
        for(int i=1;i<10;i++)
        {
            check[tens*10+i]=check[tens*10]+" "+check[i];
            if(i==9) tens++;
        }
    return check;
}
void findTime(int hrs,int mins)
{
    map <int ,string > check = createCheklist();
    string past_or_to;
    if(mins <= 30)
    {
        past_or_to = "past";
        if(mins == 0)
        {
            cout<<check[hrs]<<' '<<check[0];
        }
        else if(mins == 15)
        {
            cout<<"quarter "<<past_or_to<<' '<<check[hrs];
        }
        else if(mins == 30)
        {
            cout<<"half "<<past_or_to<<' '<<check[hrs];
        }
        else
        {
            if(mins == 1)
                cout<<check[mins]<<" minute "<<past_or_to<<' '<<check[hrs];
            else
                cout<<check[mins]<<" minutes "<<past_or_to<<' '<<check[hrs];
        }
    }
    else
    {
        past_or_to = "to";
        hrs++;
        hrs%=12;
        if(hrs == 0)
            hrs = 12;
        mins=60-mins;
        if(mins == 15)
        {
            cout<<"quarter "<<past_or_to<<' '<<check[hrs];
        }
        else
        {
            if(mins == 1)
                cout<<check[mins]<<" minute "<<past_or_to<<' '<<check[hrs];
            else
                cout<<check[mins]<<" minutes "<<past_or_to<<' '<<check[hrs];
        }
    }
}

int main() {
    int h,m;
    cin>>h>>m;
    findTime(h,m);
    return 0;
}


