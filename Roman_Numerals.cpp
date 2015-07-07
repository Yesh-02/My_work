/*
 Program : Roman numerals (Hackerrank.com)
 Author : Yeshwanth D S
 Description : Correct the given Roman numbers..
 problem statement link : https://www.hackerrank.com/contests/projecteuler/challenges/euler089
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
char roman_Number[1000];
int i=0;
int getNum(char val)
{
    switch(val)
    {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default : return 0;
    }
}
void predigits(char c1,char c2)
{
    roman_Number[i++] = c1;
    roman_Number[i++] = c2;
}

void postdigits(char c,int n)
{
    cout<<n<<" times "<<c<<endl;
    for(int j=0;j<n;j++)
        roman_Number[i++] = c;
}
void getRomanNum(int number)
{
    while(number != 0)
    {
        if(number >= 1000)
        {
            postdigits('M',number/1000);
            number = number - (number/1000) * 1000;
        }
        else if(number >=500)
        {
            if(number < 900)
            {
                postdigits('D',number/500);
                number = number - (number/500) * 500;
            }
            else
            {
                predigits('C','M');
                number = number - 900;
            }
        }
        else if(number >=100)
        {
            if(number < 400)
            {
                postdigits('C',number/100);
                number = number - (number/100) * 100;
            }
            else
            {
                predigits('L','D');
                number = number - 400;
            }
        }
        else if(number >=50)
        {
            if(number < 90)
            {
                postdigits('L',number/50);
                number = number - (number/50) * 50;
            }
            else
            {
                predigits('X','C');
                number = number - 90;
            }
        }
        else if(number >=10)
        {
            if(number < 40)
            {
                postdigits('X',number/10);
                number = number - (number/10) * 10;
            }
            else
            {
                predigits('X','L');
                number = number - 40;
            }
        }
        else if(number >=5)
        {
            if(number < 9)
            {
                postdigits('V',number/5);
                number = number - (number/5) * 5;
            }
            else
            {
                predigits('I','X');
                number = number - 9;
            }
        }
        else if(number >=1)
        {
            if(number < 4)
            {
                postdigits('I',number/1);
                number = number - (number/1) * 1;
            }
            else
            {
                predigits('I','V');
                number = number - 4;
            }
        }
    }
}
void printRoman()
{
    int i=0;
    while(roman_Number[i]!='\0')
    {
        cout<<roman_Number[i];
        i++;
    }
    cout<<endl;
}
int main()
{
    int t;
    string str;
    cin>>t;
    while(t--)
    {
        int sum = 0;
        cin>>str;
        int l=0;
        while(l<str.length())
        {
            if(getNum(str[l]) < getNum(str[l+1]))
            {
                sum+=getNum(str[l+1]);
                sum-=getNum(str[l]);
                l+=2;
            }
            else
            {
                sum+=getNum(str[l]);
                l++;
            }
        }
        cout<<sum<<endl;
        getRomanNum(sum);
        roman_Number[i++] = '\0';
        i=0;
        printRoman();
    }
    return 0;
}