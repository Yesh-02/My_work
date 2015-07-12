/*
 Program : Palindrome Index (Hackerrank.com)
 Author : Yeshwanth D S
 Description : Find the index to be removed, so that the string becomes a palindrome..
 problem statement link : https://www.hackerrank.com/challenges/palindrome-index
 Optimized solution.. Will get you full Score..
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int _isPalindrome(string str)
{
    int i=0,j=str.length()-1;
    while(i<=j)
    {
        if(str[i] != str[j])
            return -1;
        i++;
        j--;
    }
    return 1;
}
int isPalindrome(string str)
{
    if(_isPalindrome(str) == 1)
        return -1;
    int i,j,left;
    if(str[0] != str[str.length()-1])
    {
        if(str[0] == str[str.length()-2])
            return str.length()-1;
        else
            return 0;
    }
    if(str.length()%2 == 0)
    {
        i = (str.length()/2)-1;
    }
    else if(str.length()%2 != 0)
    {
        i = str.length()/2;
    }
    if(str[i] == str[i+1])
    {
        j=i+1;
        left = 1;
    }
    else if(str[i] == str[i-1])
    {
        j=i;
        i=i-1;
        left = 0;
    }
    while(i>=0 && j<str.length())
    {
        if(str[i]!=str[j])
        {
            if(left == 1)
                return i;
            else if(left == 0)
                return j;
        }
        i--;
        j++;
    }
    return i;
}

int main() {
    int t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        cout<<isPalindrome(str)<<endl;
    }
    return 0;
}