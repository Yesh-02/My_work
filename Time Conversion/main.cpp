/*
 Author : Yeshwanth D S
 Problem Statement
 
 You are given time in AM/PM format. Convert this into a 24 hour format.
 
 Note Midnight is 12:00:00AM or 00:00:00 and 12 Noon is 12:00:00PM.
 
 Input Format
 
 Input consists of time in the AM/PM format i.e. hh:mm:ssAM or hh:mm:ssPM
 where
 01≤hh≤12
 00≤mm≤59
 00≤ss≤59
 
 Output Format
 
 You need to print the time in 24 hour format i.e. hh:mm:ss
 where
 00≤hh≤23
 00≤mm≤59
 00≤ss≤59
 
 Sample Input
 
 07:05:45PM
 Sample Output
 
 19:05:45
 
 Source : hackerrank.com
 Priblem Link : https://www.hackerrank.com/challenges/time-conversion
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int getter(char tens, char ones)
{
    return (tens - '0')*10 + (ones - '0');
}
string setter(string str,int num)
{
    static int pos = 0;
    if(num < 10)
    {
        str[pos] = '0';
        pos++;
        str[pos] = num + '0';
        pos++;
    }
    else
    {
        str[pos] = (num/10) + '0';
        pos++;
        str[pos] = (num%10) + '0';
        pos++;
    }
    str[pos] = ':';
    pos++;
    return str;
}
int main() {
    string str;
    cin>>str;
    int h,m,s;
    string AMorPM;
    h = getter(str[0],str[1]);
    m = getter(str[3],str[4]);
    s = getter(str[6],str[7]);
    AMorPM = AMorPM + str[8] + str[9];
    if(AMorPM == "PM" && h != 12)
    {
        h+=12;
        h%=24;
    }
    else if(AMorPM == "AM" && h == 12)
    {
        h+=12;
        h%=24;
    }
    str = setter(str , h);
    str = setter(str , m);
    str = setter(str , s);
    str[8] = '\0';
    for(int i = 0;i<8 ;i++)
        cout<<str[i];
    return 0;
}
